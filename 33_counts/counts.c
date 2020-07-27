#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "counts.h"
counts_t * createCounts(void) {
  counts_t* temp=malloc(sizeof(*temp));
  temp->arr=NULL;
  temp->unknown_count=0;
  temp->len=0;
  return temp;
}
void addCount(counts_t * c, const char * name) {
  if(!name)
    {
      c->unknown_count++;
      return;
    }
  if(!c->len)
    {
      c->arr=malloc(sizeof(*c->arr));
      c->len++;
      c->arr[0]=malloc(sizeof(**c->arr));
      c->arr[0]->name=malloc(strlen(name)*sizeof(char));
      c->arr[0]->count=1;
      strcpy(c->arr[0]->name,name);
    }
  else
    {
      int i;
      for(i=0;i<c->len;i++)
	{
	  if(!strcmp(c->arr[i]->name,name))
	    {
	      c->arr[i]->count++;
	      break;
	    }
	}
      if(i==c->len)
	{
	  c->arr=realloc(c->arr,(++c->len)*sizeof(*c->arr));
	  i=c->len-1;
	  c->arr[i]=malloc(sizeof(**c->arr));
	  c->arr[i]->name=malloc(strlen(name)*sizeof(char));
	  c->arr[i]->count=1;
	  strcpy(c->arr[i]->name,name);
	}
    }
}
void printCounts(counts_t * c, FILE * outFile) {
  for(int i=0;i<c->len;i++)
    {
      fprintf(outFile,"%s: %d\n",c->arr[i]->name,c->arr[i]->count);
    }
  if(c->unknown_count)
    {
      fprintf(outFile,"<unknown> : %d",c->unknown_count);
    }
}

void freeCounts(counts_t * c) {
  for(int i=0;i<c->len;i++)
    {
      free(c->arr[i]->name);
      free(c->arr[i]);
    }
  free(c->arr);
  free(c);
}
