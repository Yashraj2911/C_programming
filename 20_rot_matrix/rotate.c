#include  <stdio.h>
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
