#include "future.h"
#include "cards.h"
#include "input.h"
#include <stdlib.h>
#include <stdio.h>
 
void add_future_card(future_cards_t* fc,size_t index,card_t* ptr)
{
  if(!fc)
    {
      fc=malloc(sizeof(*fc));
      fc->decks=NULL;
      fc->n_decks=1;
    }
  if(index>=fc->n_decks)
    {
      fc->decks=realloc(fc->decks,(index+1)*sizeof(*fc->decks));
      for(int i=fc->n_decks;i<index;i++)
	{
	  fc->decks[i].cards=NULL;
	  fc->decks[i].n_cards=0;
	}
      fc->decks[index].cards=malloc(sizeof(card_t*));
      fc->decks[index].n_cards=0;
      fc->decks[index].cards[fc->decks[index].n_cards++]=ptr;
      fc->n_decks=index+1;
    }
  else
    {
      fc->decks[index].cards=realloc(fc->decks[index].cards,(fc->decks[index].n_cards+1)*sizeof(card_t*));
      fc->decks[index].cards[fc->decks[index].n_cards-1]=malloc(sizeof(card_t));
      fc->decks[index].cards[fc->decks[index].n_cards-1]->value=ptr->value;
      fc->decks[index].cards[fc->decks[index].n_cards-1]->suit=ptr->suit;
      fc->decks[index].n_cards++;
    }
}
void future_cards_from_deck(deck_t* deck,future_cards_t* fc)
{
  if(!fc||!deck)
    {
      fprintf(stderr,"\nInvalid fc");
      exit(EXIT_FAILURE);
    }
  if(deck->n_cards!=fc->n_decks)
    {
      fprintf(stderr,"\nNot enough cards");
	return;
    }
  for(int i=0;i<fc->n_decks;i++)
    {
      for(int j=0;j<fc->decks[i].n_cards;j++)
	{
	  if(!deck->cards||!fc->decks[i].cards)
	    {
	      fprintf(stderr,"\nInvalid deck");
	      exit(EXIT_FAILURE);
	    }
	  fc->decks[i].cards[j]->value=deck->cards[i]->value;
	  fc->decks[i].cards[j]->suit=deck->cards[i]->suit;
	}
    }
}
