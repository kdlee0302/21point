#ifndef Poker_h
#define Poker_h
#include<string>
#include<ctime>
using namespace std;

class Poker
{
public:
	Poker();
	void rePoker();//�~�P
	string getPokerP();//���a���P
	string getPokerM();//���a���P
	int getTotalP();//���a�I���`�M
	int getTotalM();//���a�I���`�M
	void playerNeed();//���a�n�P
	void makerNeed();//���a�n�P
	void inputBet();//�U�`
	void newGame();//�s��
	void Fold();//��P��B�z
private:
	int money;
	int bet;//��`
	int pokerCard[53];
	int pokerNum[53];
	string pokerName[53];
	int pokerM[5];//���a�P
	int pokerP[5];//���a�P
	int pokerNumM;
	int pokerNumP;
};
#endif