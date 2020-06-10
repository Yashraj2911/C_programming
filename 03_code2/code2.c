
int printTriangle(int size) {
  int starcount=0;//start with starCount being 0
  for(int i=0;i<size:i++)
  {
    for(int j=0;j<=i;j++)
      printf("*"),starcount++;
    printf("\n");
  }
  return starcount;
}

int main(void) {
  int numStars;
  printf("Here is a triangle with height 4\n");
  numStars = printTriangle(4);
  printf("That triangle had %d total stars\n", numStars);
  printf("Here is a triangle with height 7\n");
  numStars=printTriangle(7);
  printf("That triangle had %d total stars\n",numStars);
  return 0;
}



