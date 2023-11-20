#pragma once

class CShoe;

struct s_card
{
	int cardNum;
	int cardSuit;
};

const int NUMBER_MAX = 13;
const int CARD_MAX = 52;
extern const char* CARD_SUIT[4];
extern const char* CARD_NUMBER[14];

class CDeck {
protected:
	s_card _cardHand[20] ;
	int _handSize;

public:
	CDeck();

public:
	void Hit_card(CShoe& cShoe, int size = 1);
	int Get_hamdSize() const;
	s_card GetHand(int n) const;
	int SumScore();
};