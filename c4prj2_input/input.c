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
      char* line_ind=line;
      int count=0;
      while(*line_ind)
	{
	  if(*line_ind==32)
	    {
	      line_ind++;
	      continue;
	    }
	  if(*line_ind=='?'&&isdigit(*(line_ind+1)))
	    {
	      line_ind++;
	      size_t index;
	      index=strtoul(line_ind,&line_ind,10);
	      add_future_card(fc,index,add_empty_card(answer[i]));
	    }
	  else
	    {
	      char first=*line_ind;
	      //	      printf("%d\n",first);
	      if(isdigit(first)&&((first!='K'||first!='k')&&(first!='A'||first!='a')&&(first!='Q'||first!='q')&&(first!='J'||first!='j')))
		{
		  fprintf(stderr,"\nInvalid input 4");
		  exit(EXIT_FAILURE);
		}
	      line_ind++;
	       if(isalpha(*line_ind))
		{
		  fprintf(stderr,"\nInvalid input 2");
		  exit(EXIT_FAILURE);
		  }
	      add_card_to(answer[i],card_from_letters(first,*line_ind));
	    }
	  count++;
	}
      if(count<5)
	{
	  fprintf(stderr,"\nInvalid input 3");
	  exit(EXIT_FAILURE);
	}
      i++;
      free(line);
      line=line_ind=NULL;
    }
  free(line);
  *n_hands=i;
  return answer;
}
