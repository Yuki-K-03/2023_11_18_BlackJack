#include <cstdio>
#include <iostream>
#include<ctime>
#include "Deck.h"
#include "PlayerDeck.h"
#include "DealerDeck.h"
#include "Shoe.h"
#define DEBUG
using namespace std;

const char* CARD_NUMBER[] = { "  ", " A", " 2", " 3", " 4", " 5", " 6", " 7", " 8", " 9", "10", " J", " Q", " K" };
const char* CARD_SUIT[] = { "  heart", "diamond", "  spade", "   club" };

void Deal(CPlayerDeck& cPlayer, CDealerDeck& cDealer, CShoe& cShoe);
void Play(CPlayerDeck& cPlayer, CShoe& cShoe);
void Play(CDealerDeck& cDealer, CShoe& cShoe);
void ShowHand(CDeck& pRef);
void Result(CPlayerDeck cPlayer, CDealerDeck cDealer);

int main() {
	CShoe cShoe;
	CPlayerDeck cPlayer;
	CDealerDeck cDealer;

#ifdef DEBUG
	cShoe.Show_cradShoe();
	printf("\n");
#endif // DEBUG

	// ディール
	Deal(cPlayer, cDealer, cShoe);

#ifdef DEBUG
	printf("\n");
	cShoe.Show_cradShoe();
	printf("\n");
#endif // DEBUG

	// プレイヤ
	printf("\n----- プレイヤのターン -----\n");
	Play(cPlayer, cShoe);

	// ディーラー
	printf("\n---- ディーラーのターン ----\n");
	Play(cDealer, cShoe);

	// 勝利判定
	Result(cPlayer, cDealer);

#ifdef DEBUG
	printf("\n");
	cShoe.Show_cradShoe();
	printf("\n");
#endif // DEBUG

	return 0;
}


void Deal(CPlayerDeck& cPlayer, CDealerDeck& cDealer, CShoe& cShoe) {
	printf("--------- ディール ---------\n");
	// 初手ディーラー
	cDealer.Hit_card(cShoe, 2);
	// アップカード
	printf("アップカード\n");
	printf("num:%s, suit:%s\n", CARD_NUMBER[cDealer.GetHand(0).cardNum], CARD_SUIT[cDealer.GetHand(0).cardSuit]);
	// スコア表示
	printf("Score:%s + a\n\n", CARD_NUMBER[cDealer.GetHand(0).cardNum]);

	// 初手プレイヤ
	cPlayer.Hit_card(cShoe, 2);
	// 手札表示
	printf("プレイヤ手札\n");
	ShowHand(cPlayer);
	// スコア表示
	printf("Score:%d\n", cPlayer.SumScore());
	printf("\n");
}

void Play(CPlayerDeck& cPlayer, CShoe& cShoe) {
	int select = 0;

	do {
		printf("1 > スタンド\n2 > ヒット\n> ");
		cin >> select;
		if (select == 2) {
			printf("ヒット\n");
			cPlayer.Hit_card(cShoe);
		}
		ShowHand(cPlayer);
		printf("Score:%d\n", cPlayer.SumScore());
		if (cPlayer.SumScore() > 21) {
			printf("バースト\n");
		}
	} while (select != 1 && cPlayer.SumScore() <= 21);
}

void Play(CDealerDeck& cDealer, CShoe& cShoe) {
	ShowHand(cDealer);
	printf("Score:%d\n", cDealer.SumScore());
	while (cDealer.SumScore() < 17) {
		cDealer.Hit_card(cShoe);
		ShowHand(cDealer);
		printf("Score:%d\n", cDealer.SumScore());
		if (cDealer.SumScore() > 21) {
			printf("バースト\n");
		}
	}
}

void ShowHand(CDeck& pRef) {
	for (int i = 0; i < pRef.Get_hamdSize(); i++) {
		printf("num:%s, suit:%s\n", CARD_NUMBER[pRef.GetHand(i).cardNum], CARD_SUIT[pRef.GetHand(i).cardSuit]);
	}
}

void Result(CPlayerDeck cPlayer, CDealerDeck cDealer) {
	printf("\n---------- 勝　敗 ----------\n");
	if (cPlayer.SumScore() > 21) {
		printf("ディーラーの勝利\n");
	}
	else if (cDealer.SumScore() > 21) {
		printf("プレイヤの勝利\n");
	}
	else if (cPlayer.SumScore() > cDealer.SumScore()) {
		printf("プレイヤの勝利\n");
	}
	else if (cDealer.SumScore() > cPlayer.SumScore()) {
		printf("ディーラーの勝利\n");
	}
	else {
		printf("プッシュ\n");
	}
}