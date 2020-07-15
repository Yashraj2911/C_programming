#include <stdio.h>
#include <stdlib.h>
void rotate(char matrix[10][10])
{
   char temp[10][10];
  for(int i=0;i<10;i++)
    for(int j=0;j<10;j++)
      temp[i][j]=matrix[i][j];

  int sum=9;
  for(int i=0;i<10;i++)
    {
      for(int j=0;j<10;j++)
	{
	  int row_sum=sum+i+j;
	  matrix[j][row_sum-j]=temp[i][j];
	}
      sum-=2;
    }
}
void printMatrix(char matrix[10][10])
{
  for(int i=0;i<10;i++)
    {
      for(int j=0;j<10;j++)
	printf("%c",matrix[i][j]);
      printf("\n");
    }
}
int main(int argc,char* argv[])
{
  if(argc!=2)
    {
      fprintf(stderr,"\nToo few or many arguments");
      return EXIT_FAILURE;
    }
  FILE* f=fopen(argv[1],"r");
  if(!f)
    {
      fprintf(stderr,"\nFile does not exist..");
      return EXIT_FAILURE;
    }
  char matrix[10][10];
  int c,i=1,j=0;
  while((c=fgetc(f))!=EOF)
    {
      if(c=='\n'&& !(i%11))
	{
	  i=1;
	  j++;
	  continue;
	}
      if(c=='\n' && i%11)
	{
	  fprintf(stderr,"\nInvalid input..");
	  return EXIT_FAILURE;
	}
      if(j>9)
	{
	  fprintf(stderr,"\nToo many lines");
	  return EXIT_FAILURE;
	}
      matrix[j][i-1]=c;
      i++;
      if(i>11)
	{
	  fprintf(stderr,"\nToo long line");
	  return EXIT_FAILURE;
	}
    }
  if(j==9)
    {
      rotate(matrix);
      printMatrix(matrix);
    }
  else
    {
      fprintf(stderr,"\nFile empty or too short");
      return EXIT_FAILURE;
    }
  if(!fclose(f))
    return EXIT_SUCCESS;
  else
    {
      fprintf(stderr,"\nFile was not closed successfully..");
      return EXIT_FAILURE;
    }
}
