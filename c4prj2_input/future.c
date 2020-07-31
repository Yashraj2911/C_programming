#include "future.h"
#include "cards.h"
#include "input.h"
#include <stdlib.h>
#include <stdio.h>
 
void add_future_card(future_cards_t* fc,size_t index,card_t* ptr)
{
  if(index>=fc->n_decks)
    {
      fc->decks=realloc(fc->decks,(index+1)*sizeof(*fc));
      fc->decks[index].n_cards=0;
      fc->decks[index].cards[fc->decks.n_cards++]=ptr;
      fc->n_decks++;
    }
  else
    {
      fc->decks[index].cards[fc->decks[index].n_cards-1]=ptr;
      fc->decks[index].n_cards++;
    }
}
void future_cards_from_deck(deck_t* deck,future_cards_t* fc)
{
  if(deck->n_cards!=fc->n_decks)
    {
      fprintf(stderr,"\nNot enough cards");
	return;
    }
  for(int i=0;i<fc->n_decks;i++)
    {
      for(int j=0;j<fc->decks[i].n_cards;j++)
	{
	  fc->decks[i].cards[j]->value=deck->cards[i]->value;
	  fc->decks[i].cards[j]->suit=deck->cards[i]->suit;
	}
    }
}