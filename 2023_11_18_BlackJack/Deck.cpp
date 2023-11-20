#include <iostream>
#include "Deck.h"
#include "Shoe.h"

CDeck::CDeck() {
	for (int i = 0; i < 20; i++) {
		_cardHand[i].cardNum = 0;
		_cardHand[i].cardSuit = 0;
	}
	_handSize = 0;
}

void CDeck::Hit_card(CShoe& cShoe, int size) {
	for (int i = 0; i < size; i++) {
		cShoe.get_cardShoe(_cardHand[_handSize++]);
	}
}

int CDeck::Get_hamdSize() const{
	return _handSize;
}

void CDeck::ShowHand() {
	for (int i = 0; i < _handSize; i++) {
		printf("num:%s, suit:%s\n", CARD_NUMBER[_cardHand[i].cardNum], CARD_SUIT[_cardHand[i].cardSuit]);
	}
}

int CDeck::SumScore() {
	int sumScore = 0;
	bool b_Ace = false;
	for (int i = 0; i < _handSize; i++) {
		if (_cardHand[i].cardNum == 1) {
			b_Ace = true;
			sumScore += 11;
		}
		else if (_cardHand[i].cardNum >= 10) {
			sumScore += 10;
		}
		else {
			sumScore += _cardHand[i].cardNum;
		}

		if (sumScore > 21 && b_Ace) {
			sumScore -= 10;
			b_Ace = false;
		}
	}

	return sumScore;
}
