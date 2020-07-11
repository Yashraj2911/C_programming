#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
int main(int argc,char* argv[])
{
  if(argc!=2)
    {
      fprintf(stderr,"Too few or many arguments..");
      return EXIT_FAILURE;
    }
  FILE* f=fopen(argv[1],"r");
  if(f==NULL)
    {
      fprintf(stderr,"\nFile %s does not exist...",argv[1]);
      return EXIT_FAILURE;
    }
  int c;
  int arr[26]={0};
  while((c=fgetc(f))!=EOF)
    {
      if(!isalpha(c))
	continue;
      c=tolower(c);
      arr[c-97]++;
    }
  int max=0,max_ind=0;
  for(int i=0;i<26;i++)
    if(max<arr[i])
      {
	max=arr[i];
	max_ind=i;
      }
  printf("%d\n",max_ind);
  return EXIT_SUCCESS;
}
