#include <stdio.h>
#include <stdlib.h>
#include "deck.h"
#include "cards.h"
#include "future.h"
#include <ctype.h>
deck_t** read_input(FILE* f,size_t* n_hands,future_cards_t* fc)
{
  if(!f)
    {
      fprintf(stderr,"\nnvalid file");
      exit(EXIT_FAILURE);
    }
  deck_t** answer=NULL;
  size_t size;
  int len=0,i=0;
  char* line=NULL;
  while((len=getline(&line,&size,f))>=0)
    {
      if(line[len-1]=='\n')
	{
	  line[len-1]=0;
	  len--;
	}
      answer=realloc(answer,(i+1)*sizeof(*answer));
      answer[i]=malloc(sizeof(deck_t));
      answer[i]->cards=NULL;
      answer[i]->n_cards=0;
      int line_ind=0;;
      int count=0;
      while(line[line_ind])
	{
	  if(line[line_ind]==32)
	    {
	      line_ind++;
	      continue;
	    }
	  if(line[line_ind]=='?'&&isdigit(line[line_ind+1]))
	    {
	      line_ind++;
	      size_t index;
	      char num[5];int j;
	      for(j=0;line[line_ind];line_ind++)
		if(isdigit(line[line_ind]))
		  num[j++]=line[line_ind];
		else
		  break;
	      num[j]=0;
	      line_ind--;
	      index=strtoul(num,NULL,10);
	      add_future_card(fc,index,add_empty_card(answer[i]));
	    }
	  else
	    {
	      char first=line[line_ind];
	      //	      printf("%d\n",first);
	      if(!isdigit(first)&&(first!='K'&&first!='A'&&first!='Q'&&first!='J'))
		{
		  fprintf(stderr,"\nInvalid input 4");
		  exit(EXIT_FAILURE);
		}
	      line_ind++;
	      // if(line[line_ind]==32)
	      //	line_ind++;
	      if(line[line_ind]!='s'&&line[line_ind]!='h'&&line[line_ind]!='c'&&line[line_ind]!='d')
		{
		  fprintf(stderr,"\nInvalid input 2");
		  exit(EXIT_FAILURE);
		  }
	      add_card_to(answer[i],card_from_letters(first,line[line_ind]));
	    }
	  line_ind++;
	  count++;
	}
      if(count<6)
	{
	  fprintf(stderr,"\nInvalid input 3");
	  exit(EXIT_FAILURE);
	}
      i++;
      free(line);
      line=NULL;
    }
  free(line);
  *n_hands=i;
  return answer;
}
