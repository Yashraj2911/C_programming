#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
int main(int argc,char* argv[])
{
  if(argc!=2)
    return EXIT_FAILURE;
  FILE* f=fopen(argv[1],"r");
  if(f==NULL)
    return EXIT_FAILURE;
  int c;
  int arr[26]={0};
  while((c=fgetc(f))!=EOF)
    {
      if(!isalpha(c))
	continue;
      c=tolower(c);
      arr[c-97]++;
    }
  int max=0;
  for(int i=0;i<26;i++)
    if(max<arr[i])
      max=i;
  return max;
}
