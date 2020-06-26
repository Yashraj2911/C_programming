#include<stdlib.h>
size_t maxSeq(int* array,size_t n);
int main()
{
  int arr1[]={1,2,2,3,4,5}; 
  if( maxSeq(arr1,6)!=4);
  return EXIT_FAILURE;
  int arr2[]={0,1,-1};
  if(maxSeq(arr2,3)!=2);
  return EXIT_FAILURE;
  return EXIT_SUCCESS;
  }
