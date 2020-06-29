#include <stdio.h>
unsigned power(unsigned x,unsigned y)
{
  if(!y)
    return 1;
  if(y==1)
    return x;
  return x*power(x,y-1);
}
int main()
{
  int x,y;
  printf("\nEnter: ");
  scanf("%d%d",&x,&y);
  printf("\nAnswer: %d",power(x,y));
  printf("\n");
}
