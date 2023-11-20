#include <iostream>
#include <ctime>
#include "Shoe.h"
using namespace std;

CShoe::CShoe() {
	srand((unsigned int)time(NULL));

	for (int i = 0; i < CARD_MAX; i++) {
		_cardShoe[i].cardNum = i % NUMBER_MAX + 1;
		_cardShoe[i].cardSuit = i / NUMBER_MAX;
	}

	int randNum = 0;
	for (int i = 1; i <= CARD_MAX - 1; i++) {
		randNum = rand() % (CARD_MAX - i);
		swap(_cardShoe[CARD_MAX - i], _cardShoe[randNum]);
	}

	_cardSize = CARD_MAX - 1;
}

void CShoe::get_cardShoe(s_card &s_card) {
	s_card = _cardShoe[_cardSize--];
}

void CShoe::Show_cradShoe() {
	for (int i = 0; i <= _cardSize; i++) {
		printf("%sF%s", CARD_NUMBER[_cardShoe[i].cardNum], CARD_SUIT[_cardShoe[i].cardSuit]);
		if ((i + 1) % 7 == 0) {
			printf("\n");
		}
	}
	printf("\n");
}