#ifndef DECK_H
#define DECK_H

#include <stdlib.h>

/**
 * enum kind_e - listing of card suits.
 * @CLUB: Clubs to suit.
 * @DIAMOND: Diamonds to suit.
 * @SPADE: Spades to suit.
 * @HEART: Hearts to suit.
 */
typedef enum kind_e
{
	SPADE = 0,
	HEART,
	CLUB,
	DIAMOND
} kind_t;

/**
 * struct card_s - Playing the card
 * @value: Value of an Ace through a King.
 * @kind: Sort of card
 */
typedef struct card_s
{
	const char *value;
	const kind_t kind;
} card_t;

/**
 * struct deck_node_s - Pack of playing cards.
 * @card: Arrow pointing to the node card.
 * @next: Pointer to the list subsequent node.
 * @prev: Identifies pointer to the list first node.
 */
typedef struct deck_node_s
{
	const card_t *card;
	struct deck_node_s *prev;
	struct deck_node_s *next;
} deck_node_t;

void sort_deck(deck_node_t **deck);

#endif /* DECK_H */
