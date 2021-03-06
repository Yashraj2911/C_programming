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
  future_cards_t fc;//=malloc(sizeof(*fc));
  fc.decks=malloc(sizeof(deck_t));
  fc.decks[0].cards=NULL;
  fc.decks[0].n_cards=0;
  fc.n_decks=1;

  deck_t** input=read_input(f,&n_hands,&fc);
  deck_t* rem_deck=build_remaining_deck(input,n_hands);
  unsigned* win=calloc((n_hands+1),sizeof(*win));
  unsigned int num_trials;
  if(argc==3)
    {
      num_trials=atoi(argv[2]);
    }
  else
    {
      num_trials=10000;
    }
  for(size_t i=0;i<num_trials;i++)
    {
      shuffle(rem_deck);
      future_cards_from_deck(rem_deck,&fc);
      int decide;
      // deck_t *highest=input[0];
      size_t index=0;
      size_t indexl=0;
      for(size_t j=1;j<n_hands;j++)
	{
	  decide=compare_hands(input[indexl],input[j]);
	  if(decide<0)
	    {
	      indexl=j;
	      index=j;
	    }
	  else if(decide>0)
	    {
	      index=indexl;
	    }
	  else
	    {
	      index=n_hands;
	    }
	}
      win[index]++;

    }
  for(size_t k=0;k<n_hands;k++)
    {
      printf("Hand %zu won %u / %u times (%.2f%%)\n",k,win[k],num_trials,(double)win[k]/(double)num_trials*100);
    }
  printf("And there were %u ties\n",win[n_hands]);
  for(int i=0;i<fc.n_decks;i++)
    {
      // for(int j=0;j<fc->decks[i].n_cards;j++)
      // free(fc->decks[i].cards[j]);
      //     if(fc->decks[i].cards)
      free(fc.decks[i].cards);
    }
  free(fc.decks);
  //  free(fc);
  for(int i=0;i<n_hands;i++)
    free_deck(input[i]);
  free(input);
  free_deck(rem_deck);
  free(win);
  if(fclose(f))
    {
      fprintf(stderr,"\nError in closing the file");
    }
  return EXIT_SUCCESS;
}
