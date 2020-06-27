#include<stdlib.h>
size_t maxSeq(int* array,size_t n);
int main()
{
  int arr1[]={1,2,2,3,4,5}; 
  if( maxSeq(arr1,6)!=4)
    return EXIT_FAILURE;
  int arr2[]={0,1,-1};
  if(maxSeq(arr2,3)!=2)
    return EXIT_FAILURE;
    int arr3[2];
     if(maxSeq(arr3,0)!=0)
     return EXIT_FAILURE;
    int arr4[]={};
  if(maxSeq(arr4,0)!=0)
  return EXIT_FAILURE;
    int arr5[]={0,1,2,3,4,5,0,1,2,3,4,0,1,2,3};
  if(maxSeq(arr5,15)!=6)
  return EXIT_FAILURE;
  int arr6[]={-3,-42,-99,-1000,-999,-88,-77};
  if(maxSeq(arr6,7)!=4)
    return EXIT_FAILURE;
  int arr7[]={1,2,1,2,3,1,2};
  if(maxSeq(arr7,7)!=3)
    return EXIT_FAILURE;
  return EXIT_SUCCESS;
  }
