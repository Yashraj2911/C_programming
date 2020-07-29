#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "kv.h"
#include "counts.h"
#include "outname.h"

counts_t * countFile(const char * filename, kvarray_t * kvPairs) {
  counts_t* c=createCounts();
  FILE* f=fopen(filename,"r");
  char str[30];
  while(fgets(str,30,f))
    {
      if(str[strlen(str)-1]=='\n')
	str[strlen(str)-1]=0;
      addCount(c,lookupValue(kvPairs,str));
    }
  if(fclose(f))
    {
      fprintf(stderr,"\nCould  not close file");
      exit(EXIT_FAILURE);
    }
  return c;
}

int main(int argc, char ** argv) {
  //WRITE ME (plus add appropriate error checking!)
  if(argc<3)
    {
      fprintf(stderr,"\nToo few arguments");
      return EXIT_FAILURE;
    }
  kvarray_t* kv=readKVs(argv[1]); //read the key/value pairs from the file named by argv[1] (call the result kv)
  if(!kv)
    {
      fprintf(stderr,"\nFile not found..");
      freeKVs(kv);
      return EXIT_FAILURE;
    }
  for(int i=2;i<argc;i++) //count from 2 to argc (call the number you count i)
    {
      counts_t* c=countFile(argv[i],kv);
      char* outName=malloc((strlen(argv[i])+9)*sizeof(*outName));
      strcpy(outName,argv[i]);
      char add[]=".counts";
      strcat(outName,add);
      FILE* f=fopen(outName,"w");
      printCounts(c,f);
      if(fclose(f))
	{
	  fprintf(stderr,"\nCould not close file...");
	  //	  free(outName);
	  //freeCounts(c);
	  //freeKVs(kv);
	  return EXIT_FAILURE;
	}
      free(outName);
      freeCounts(c);
    }
  freeKVs(kv);
    //count the values that appear in the file named by argv[i], using kv as the key/value pair
    //   (call this result c)

    //compute the output file name from argv[i] (call this outName)


    //open the file named by outName (call that f)

    //print the counts from c into the FILE f

    //close f

    //free the memory for outName and c



 //free the memory for kv

  return EXIT_SUCCESS;
}
