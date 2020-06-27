#include<stdlib.h>
size_t maxSeq(int *array,size_t n)
{
  int i=1;
  if(n==0)
    return 0;
  int count=1;
  for(;i<n;i++)
    {
      if(array[i]>array[i-1])
	count++;
      else
	count=1;
    }
  return count;
}
