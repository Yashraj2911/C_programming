#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <ctype.h>
#include "cards.h"
#include "deck.h"
#include "eval.h"
#include "future.h"
#include "input.h"



int main(int argc, char ** argv) {
  if(argc<2||argc>3)
    {
      fprintf(stderr,"\nInvalid number of arguments");
      return EXIT_FAILURE;
    }
  
  FILE *f=fopen(argv[1],"r");
  if(!f)
    {
       fprintf(stderr,"\nCould not open the file");
      return EXIT_FAILURE;
    }
  
  size_t n_hands;
  future_cards_t* fc=malloc(sizeof(*fc));
  fc->decks=malloc(sizeof(deck_t));
  fc->decks[0].cards=NULL;
  fc->decks[0].n_cards=0;
  fc->n_decks=1;

  deck_t** input=read_input(f,&n_hands,fc);
  deck_t* rem_deck=build_remaining_deck(input,n_hands);
  unsigned int* win=calloc((n_hands+1),sizeof(*win));
  unsigned int num_trials;
  if(argc==3)
    {
      num_trials=strtoul(argv[2],NULL,0);
    }
  else
    {
      num_trials=10000;
    }
  for(int i=0;i<num_trials;i++)
    {
      shuffle(rem_deck);
      future_cards_from_deck(rem_deck,fc);
      int decide;
      deck_t *highest=input[0];
      int index=0;
      for(int j=1;j<n_hands;j++)
	{
	  if((decide=compare_hands(highest,input[j]))==1)
	    {
	      highest=input[j];
	      index=j;
	      win[index]++;
	    }
	  else if(decide==-1)
	    {
	      win[index]++;
	    }
	  else
	    {
	      win[n_hands]++;
	    }
	}
      for(size_t i=0;i<n_hands;i++)
	{
	  printf("Hand %zu won %u / %u times (%.2f%%)\n",i,win[i],num_trials,(float)(win[i]/n_hands*100));
	}
      printf("And there were %u ties\n",win[n_hands]);
    }


  return EXIT_SUCCESS;
}
