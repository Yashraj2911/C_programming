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
void read(int argc,char** argv)
{
  for(int i=1;i<argc;i++)
    {
      FILE* f=fopen(argv[i],"r");
      if(!f)
	{
	  fprintf(stderr,"\nFile does not exist..");
	  exit(EXIT_FAILURE);
	}
      char* line=NULL;
      char** arr=NULL;
      size_t size=0;
      int len,i=0;
      while((len=getline(&line,&size,f))>=0)
	{
	  arr=(char**)realloc(arr,(i+2)*sizeof(*arr));
	  //arr[i]=malloc(len*sizeof(**arr));
	  arr[i]=line;
	  line=NULL;
	  free(line);
	  size=0;
	  i++;
	}
      free(line);
      arr[i]=NULL;
      //line=NULL;
      sortData(arr,i);
      printData(arr);
      for(int j=0;j<=i;j++)
	free(arr[j]);
      free(arr);
      if(fclose(f))
	{
	  fprintf(stderr,"\nError in closing the file");
	  exit(EXIT_FAILURE);
	}
    }
}
void foo()
{
  char s[1000];
    scanf("%[^\t]",s);
      printf("%s",s);
}
int main(int argc, char * argv[]) {

  if(argc==1)
    {
       foo();
    }
  else
    {
      read(argc,argv);
    }
  return EXIT_SUCCESS;
}
