#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "kv.h"



kvarray_t * readKVs(const char * fname) {
  FILE* f=fopen(fname,"r");
  if(!f)
    {
      fprintf(stderr,"\nCould not open file..");
      return NULL;
    }
  kvarray_t* temp=malloc(sizeof(kvarray_t));
  temp->arr=NULL;
  char* line=NULL;
  size_t size=0;
  int i=0,len;
  while((len=getline(&line,&size,f))>=0)
    {
      if(line[0]=='\n')
	{
	  free(line);
	  line=NULL;
	  continue;
	}
      temp->arr=realloc(temp->arr,(i+1)*sizeof(kvpair_t*));
      temp->len=i+1;
      int j=0;
      while(j<len&&line[j]!='=')
	j++;
      temp->arr[i]=malloc(sizeof(kvpair_t));
      temp->arr[i]->key=malloc(j*sizeof(char*));
      temp->arr[i]->value=malloc((len-j-1)*sizeof(char*));
      int k;
      for(k=0;k<j;k++)
	temp->arr[i]->key[k]=line[k];
      temp->arr[i]->key[k]=0;
      int t=0;
      for(int v=j+1;v<len;v++)
	{
	  if(line[v]!='\n')
	    temp->arr[i]->value[t++]=line[v];
	}
      temp->arr[i]->value[t++]=0;
      free(line);
      line=NULL;
      i++;
    }
  free(line);
  line=NULL;
  if(fclose(f))
    {
      fprintf(stderr,"\nError in closing the file");
      return NULL;
    }
  return temp;
}
void freeKVs(kvarray_t * pairs) {
  for(int i=0;i<pairs->len;i++)
    {
      free(pairs->arr[i]->key);
      free(pairs->arr[i]->value);
      free(pairs->arr[i]);
    }
  free(pairs->arr);
  free(pairs);
}

void printKVs(kvarray_t * pairs) {
  for(int i=0;i<pairs->len;i++)
    {
      printf("key = \'%s\' value = \'%s\'\n",pairs->arr[i]->key,pairs->arr[i]->value);
    }
}
char * lookupValue(kvarray_t * pairs, const char * key) {
  for(int i=0;i<pairs->len;i++)
    {
      if(!strcmp(pairs->arr[i]->key,key))
	{
	  return pairs->arr[i]->value;
	}
    }
  return NULL;
}
