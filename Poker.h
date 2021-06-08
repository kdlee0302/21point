#ifndef Poker_h
#define Poker_h
#include<string>
#include<ctime>
using namespace std;

class Poker
{
public:
	Poker();
	void rePoker();//洗牌
	string getPokerP();//玩家的牌
	string getPokerM();//莊家的牌
	int getTotalP();//玩家點數總和
	int getTotalM();//莊家點數總和
	void playerNeed();//玩家要牌
	void makerNeed();//莊家要牌
	void inputBet();//下注
	void newGame();//新局
	void Fold();//棄牌後處理
private:
	int money;
	int bet;//賭注
	int pokerCard[53];
	int pokerNum[53];
	string pokerName[53];
	int pokerM[5];//莊家牌
	int pokerP[5];//玩家牌
	int pokerNumM;
	int pokerNumP;
};
#endif