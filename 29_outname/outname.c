#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "outname.h"

char * computeOutputFileName(const char * inputName) {
  char* temp=(char*)malloc((strlen(inputName)+7)*sizeof(*temp));
  strcpy(temp,inputName);
  strcat(temp,".counts");
  return temp;
}
