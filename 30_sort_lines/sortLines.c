#include <stdio.h>
#include <stdlib.h>
#include <string.h>


//This function is used to figure out the ordering
//of the strings in qsort.  You do not need
//to modify it.
int stringOrder(const void * vp1, const void * vp2) {
  const char * const * p1 = vp1;
  const char * const * p2 = vp2;
  return strcmp(*p1, *p2);
}
//This function will sort and print data (whose length is count).
void sortData(char ** data, size_t count) {
  qsort(data, count, sizeof(char *), stringOrder);
}
void printData(char **arr)
{
  int i=0;
      while(arr[i])
	{
	  printf("%s",arr[i]);
	  i++;
	}
}
void read(FILE* stream,int flag)
{
      char* line=NULL;
       if(flag==1)
	{
	   char** arr=NULL;
	   size_t size=0;
           size_t len,i=0;
     	  while((len=getline(&line,&size,stream))>=0)
	    {
	      arr=realloc(arr,(i+1)*sizeof(*arr));
	      arr[i]=line;
	      line=NULL;
	      size=0;
	      i++;
	    }
	  free(line);
	  sortData(arr,i);
	  printData(arr);
	  for(int j=0;j<i;j++)
	    free(arr[j]);
	  free(arr);
	}
      else
	{
	  char s[1000];
	  scanf("%[^\t]",s);
	  printf("%s",s);
	}
}
int main(int argc, char ** argv) {
  
  if(argc==1)
    {
      read(stdin,0);
    }
  else
    {
      for(int i=1;i<argc;i++)
	{
	  FILE* f=fopen(argv[i],"r");
	  if(!f)
	    {
	      fprintf(stderr,"\nFile does not exist..");
	      return EXIT_FAILURE;
	    }
	  read(f,1);
	  if(fclose(f))
	    {
	      fprintf(stderr,"\nError in closing the file");
	      return EXIT_FAILURE;
	    }
	}
    }
  return EXIT_SUCCESS;
}
