#include <stdio.h>
#include <stdlib.h>
#include "deck.h"
#include "cards.h"
#include "future.h"
deck_t** read_input(FILE* f,size_t* n_hands,future_cards_t* fc)
{
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
      char* line_ind=line;
      int count=0;
      while(line_ind)
	{
	  if(*line_ind==32)
	    line++;
	  if(*line_ind=='?')
	    {
	      add_future_card(fc,*(++line_ind)-48,add_empty_card(answer[i]));
	    }
	  else
	    {
	      char first=*line;
	      line_ind++;
	      add_card_to(answer[i],card_from_letters(first,*line_ind);
	    }
	  count++;
	}
      if(count<5)
	{
	  fprintf(stderr,"\nInvalid input");
	  exit(EXIT_FAILURE);
	}
      i++;
      free(line);
      line=line_ind=NULL;
    }
  *n_hands=i;
  return answer;
}
