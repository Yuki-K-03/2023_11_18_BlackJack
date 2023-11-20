#pragma once
#include "Deck.h"

class CShoe {
private:
	s_card _cardShoe[CARD_MAX];
	int _cardSize;

public:
	CShoe();

public:
	void get_cardShoe(s_card &s_card);
	void Show_cradShoe();
};