#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "deck.h"
void print_hand(deck_t * hand){
  for(int i=0;i<hand->n_cards;i++)
    {
      print_card(*hand->cards[i]);
      printf(" ");
    }
}

int deck_contains(deck_t * d, card_t c) {
  for(int i=0;i<d->n_cards;i++)
    {
      if(d->cards[i]->value==c.value&&d->cards[i]->suit==c.suit)
	return 1;
    }
  return 0;
}
void shuffle(deck_t * d){
  for(int i=0;i<d->n_cards;i++)
    {
      int random=rand()%(d->n_cards);
      card_t *temp=d->cards[i];
      d->cards[i]=d->cards[random];
      d->cards[random]=temp;
    }
}
void assert_full_deck(deck_t * d) {
  for(int i=0;i<d->n_cards;i++)
    assert_card_valid(*d->cards[i]);
}
void add_card_to(deck_t* deck,card_t c)
{
  deck->cards=realloc(deck->cards,(deck->n_cards+1)*sizeof(*deck->cards));
  deck->cards[deck->n_cards]=malloc(sizeof(card_t));
  deck->cards[deck->n_cards]->value=c.value;
  deck->cards[deck->n_cards]->suit=c.suit;
  deck->n_cards++;
  }
card_t* add_empty_card(deck_t* deck)
{
  deck->cards=realloc(deck->cards,(deck->n_cards+1)*sizeof(*deck->cards));
  deck->cards[deck->n_cards]=malloc(sizeof(card_t));
  deck->cards[deck->n_cards]->value=0;
  deck->cards[deck->n_cards]->suit=0;
  deck->n_cards++;
  return deck->cards[deck->n_cards-1];
  }
deck_t* make_deck_exclude(deck_t* excluded_cards)
{
  deck_t* excl=malloc(sizeof(deck_t));
  excl->cards=NULL;
  excl->n_cards=0;
  for(int i=0;i<52;i++)
    {
      card_t temp=card_from_num(i);
      if(!deck_contains(excluded_cards,temp))
	{
	  excl->cards=realloc(excl->cards,(excl->n_cards+1)*sizeof(*excl->cards));
	  excl->cards[excl->n_cards]=malloc(sizeof(card_t));
	  excl->cards[excl->n_cards]->value=temp.value;
	  excl->cards[excl->n_cards]->suit=temp.suit;
	  excl->n_cards++;
	}
    }
  free(excluded_cards->cards);
  free(excluded_cards);
  return excl;
  }
deck_t* build_remaining_deck(deck_t** hands,size_t n_hands)
{
  deck_t* excluded_deck=malloc(sizeof(deck_t));
  excluded_deck->n_cards=0;
  excluded_deck->cards=NULL;
  for(int i=0;i<n_hands;i++)
    {
      for(int j=0;j<hands[i]->n_cards;j++)
	{
	  if(hands[i]->cards[j]->value)
	    {
	      excluded_deck->cards=realloc(excluded_deck->cards,(excluded_deck->n_cards+1)*sizeof(card_t*));
	      excluded_deck->cards[excluded_deck->n_cards]=hands[i]->cards[j];
	      excluded_deck->n_cards++;
	    }
	}
    }
  return make_deck_exclude(excluded_deck);
  }
void free_deck(deck_t* deck)
{
  for(int i=0;i<deck->n_cards;i++)
    free(deck->cards[i]);
  free(deck->cards);
  free(deck);
  }
