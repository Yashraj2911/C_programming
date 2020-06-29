#include <stdlib.h>
unsigned power(unsigned ,unsigned);
int main()
{
  if(power(0,0)!=1)
    return EXIT_FAILURE;
  if(power(2,0)!=1)
    return EXIT_FAILURE;
  if(power(0,2)!=0)
    return EXIT_FAILURE;
  if(power(-1,-1)!=-1)
    return EXIT_FAILURE;
  if(power(-2,2)!=4)
    return EXIT_FAILURE;
  if(power(2,1)!=2)
    return EXIT_FAILURE;
  if(power(2,25)!=33554432)
    return EXIT_FAILURE;
  return EXIT_SUCCESS;
}
