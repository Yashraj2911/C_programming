#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include "cards.h"


void assert_card_valid(card_t c) {
  assert(c.value>=2&&c.value<=VALUE_ACE);
  assert(c.suit>=SPADES&&c.suit<=CLUBS);
}

const char * ranking_to_string(hand_ranking_t r) {
  switch(r)
    {
    case STRAIGHT_FLUSH:return "STRAIGHT_FLUSH";break;
    case FOUR_OF_A_KIND:return "FOUR_OF_A_KIND";break;
    case FULL_HOUSE:return "FULL_HOUSE";break;
    case FLUSH:return "FLUSH";break;
    case STRAIGHT:return "STRAIGHT";break;
    case THREE_OF_A_KIND:return "THREE_OF_A_KIND";break;
    case TWO_PAIR:return "TWO_PAIR";break;
    case PAIR:return "PAIR";break;
    case NOTHING:return "NOTHING";break;
    }
  return "";
 }
char value_letter(card_t c) {
  switch(c.value)
    {
    case VALUE_ACE:return 'A';break;
    case VALUE_KING:return 'K';break;
    case VALUE_QUEEN:return 'Q';break;
    case VALUE_JACK:return 'J';break;
    case 10: return '0';break;
    }
  /*  if(c.value>=48&&c.value<=57)
    return (char)(c.value-48);
    else*/
  return (char)(c.value+48);
  }
char suit_letter(card_t c) {
  int ch=c.suit;
  switch(ch)
    {
    case SPADES:return 's';break;
    case HEARTS:return 'h';break;
    case DIAMONDS:return 'd';break;
    case CLUBS:return 'c';break;
    }
  return '?';
}
void print_card(card_t c) {
  printf("%c%c",value_letter(c),suit_letter(c));
}
card_t card_from_letters(char value_let, char suit_let) {
  card_t temp;
  //if(value_let>=48&&value_let<=57)
  //temp.value=value_let-48;
  if(value_let=='0')
    temp.value=10;
  else if(value_let=='A'||value_let=='K'||value_let=='Q'||value_let=='J')
    {
      switch(value_let)
	{
	case 'A':temp.value=VALUE_ACE;break;
	case 'K':temp.value=VALUE_KING;break;
	case 'Q':temp.value=VALUE_QUEEN;break;
	case 'J':temp.value=VALUE_JACK;
	}
    }
   else
    temp.value=value_let-48;
  switch(suit_let)
    {
    case 'S':
    case 's': temp.suit=SPADES;break;
    case 'H':
    case 'h': temp.suit=HEARTS;break;
    case 'D':
    case 'd': temp.suit=DIAMONDS;break;
    case 'C':
    case 'c': temp.suit=CLUBS;
    }
  assert_card_valid(temp);
  return temp;
}
card_t card_from_num(unsigned c) {
  card_t temp;
  if(c<13)
    {
      temp.value=c+2;
      temp.suit=HEARTS;
    }
  else if(c<26)
    {
      temp.value=c%13+2;
      temp.suit=SPADES;
    }
  else if(c<39)
    {
      temp.value=c%13+2;
      temp.suit=CLUBS;
    }
  else
    {
      temp.value=c%13+2;
      temp.suit=DIAMONDS;
    }
  //assert_card_valid(temp);
  return temp;
}
