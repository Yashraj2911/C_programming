#include<stdlib.h>
size_t maxSeq(int *array,size_t n)
{
  int i=1;
  if(n==0)
    return 0;
  int count=1;
  int prev_count=0;
  for(;i<n;i++)
    {
      if(array[i]>array[i-1])
	count++;
      else
	{
	  if(prev_count<count)
	    prev_count=count;
	  count=1;
	} 
    }
  return count>prev_count?count:prev_count;
}
