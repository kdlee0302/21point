#include"Poker.h"
#include<iostream>
#include<string>
#include<ctime>
using namespace std;
#define NUM 1000
int randNum[NUM];
int j = 2;
Poker::Poker()
{
    pokerCard[0] = 0;
    for (int i = 1; i <= 13; i++)
    {
        pokerCard[i] = i;
        pokerCard[i + 13] = i;
        pokerCard[i + 26] = i;
        pokerCard[i + 39] = i;
    }

    pokerNum[0] = 0;
    for (int i = 1; i <= 52; i++)
    {
        if (pokerCard[i] <= 10)  pokerNum[i] = pokerCard[i];
        else              pokerNum[i] = 10;
    }
    pokerName[0] = " ";
    pokerName[1] = "黑桃A";
    pokerName[2] = "黑桃2";
    pokerName[3] = "黑桃3";
    pokerName[4] = "黑桃4";
    pokerName[5] = "黑桃5";
    pokerName[6] = "黑桃6";
    pokerName[7] = "黑桃7";
    pokerName[8] = "黑桃8";
    pokerName[9] = "黑桃9";
    pokerName[10] = "黑桃10";
    pokerName[11] = "黑桃J";
    pokerName[12] = "黑桃Q";
    pokerName[13] = "黑桃K";
    pokerName[14] = "紅心A";
    pokerName[15] = "紅心2";
    pokerName[16] = "紅心3";
    pokerName[17] = "紅心4";
    pokerName[18] = "紅心5";
    pokerName[19] = "紅心6";
    pokerName[20] = "紅心7";
    pokerName[21] = "紅心8";
    pokerName[22] = "紅心9";
    pokerName[23] = "紅心10";
    pokerName[24] = "紅心J";
    pokerName[25] = "紅心Q";
    pokerName[26] = "紅心K";
    pokerName[27] = "方塊A";
    pokerName[28] = "方塊2";
    pokerName[29] = "方塊3";
    pokerName[30] = "方塊4";
    pokerName[31] = "方塊5";
    pokerName[32] = "方塊6";
    pokerName[33] = "方塊7";
    pokerName[34] = "方塊8";
    pokerName[35] = "方塊9";
    pokerName[36] = "方塊10";
    pokerName[37] = "方塊J";
    pokerName[38] = "方塊Q";
    pokerName[39] = "方塊K";
    pokerName[40] = "梅花A";
    pokerName[41] = "梅花2";
    pokerName[42] = "梅花3";
    pokerName[43] = "梅花4";
    pokerName[44] = "梅花5";
    pokerName[45] = "梅花6";
    pokerName[46] = "梅花7";
    pokerName[47] = "梅花8";
    pokerName[48] = "梅花9";
    pokerName[49] = "梅花10";
    pokerName[50] = "梅花J";
    pokerName[51] = "梅花Q";
    pokerName[52] = "梅花K";
    money = 300;
    bet = 0;
    for (int i = 0; i < 5; i++)
    {
        pokerM[i] = 0;
        pokerP[i] = 0;
    }
    pokerNumM = 0;
    pokerNumP = 0;
    srand((int)time(0));
    for (int i = 0; i < NUM; i++)
    {
        randNum[i] = rand() * 51 / 32767 + 1;
    }
}
void Poker::inputBet()
{
    cout << "你現在有" << money << "元，請輸入賭注:";
        do
        {
            cin >> bet;
            if (bet > money)
                cout << "傻瓜，你哪來那麼多錢，重新輸入賭注吧傻子:";
        } while (bet > money);
}
void Poker::rePoker()
{
    cout << "新一局遊戲開始，開始洗牌........" << endl;

    pokerM[0] = randNum[j++];
    pokerM[1] = randNum[j++];
    pokerP[0] = randNum[j++];
    pokerP[1] = randNum[j++];

    pokerNumM = 2;
    pokerNumP = 2;

    cout << "洗牌完成,你的牌為:" << getPokerP() << endl;
}
string Poker::getPokerP()
{
    string result = "";

    for (int i = 0; i < pokerNumP; i++)
        result = result + pokerName[pokerP[i]] + " ";

    return result;
}
string Poker::getPokerM()
{
    string result = "";

    for (int i = 0; i < pokerNumM; i++)
        result = result + pokerName[pokerM[i]] + " ";

    return result;
}
int Poker::getTotalP()
{
    int result = 0;

    for (int i = 0; i < pokerNumP; i++)
        result = result + pokerNum[pokerP[i]];

    return result;
}
int Poker::getTotalM()
{
    int result = 0;

    for (int i = 0; i < pokerNumM; i++)
        result = result + pokerNum[pokerM[i]];
    return result;
}
void Poker::playerNeed()
{
    if (pokerNumP >= 5)
    {
        cout << "你已經過五關了，不能再要牌了" << endl;
        Fold();
    }
    else
    {
        pokerP[pokerNumP++] = randNum[j++];
        cout << "你的牌為:" << getPokerP() << endl;
        if (getTotalP() > 21)
        {
            cout << "你的點數已經爆了，你輸了" << bet << "元" << endl;
            money = money - bet;
            if (money <= 0)
            {
                cout << "你已經沒錢了~，下次努力" << endl;
                cout << "GameOver!" << endl;
                exit(0);
            }
            inputBet();
            rePoker();
        }
        else if (getTotalP() == 21)
        {
            Fold();
        }
    }
}
void Poker::makerNeed()
{
    if (pokerNumM >= 5)
    {
        if (getTotalP() > getTotalM())
        {
            cout << "莊家的牌為" << getTotalM() << endl;
            cout << "你贏了，你贏了" << bet << "元" << endl;
            money = money + bet;
            inputBet();
            rePoker();
        }
        else if (getTotalP() == getTotalM())
        {
            cout << "莊家的牌為" << getTotalM() << endl;
            cout << "你運氣很好喔~~這局平手" << endl;
            inputBet();
            rePoker();
        }
        else if (getTotalP() < getTotalM())
        {
            cout << "莊家的牌為" << getTotalM() << endl;
            cout << "你輸了，你輸了" << bet << "元" << endl;
            money = money - bet;
            if (money <= 0)
            {
                cout << "笑死，怎那麼菜把錢輸光光" << endl;
                cout << "別想再玩了，遊戲結束!!!!!!!!!!!!!!!" << endl;
                exit(0);
            }
            inputBet();
            rePoker();
        }
    }
    else
    {
        pokerM[pokerNumM++] = randNum[j++];
        if (getTotalM() > 21)
        {
            cout << "莊家的牌為" << getTotalM() << endl;
            cout << "莊家爆了，你運氣真好，你贏了:" << bet << "元" << endl;
            money = money + bet;
            inputBet();
            rePoker();
        }
        else Fold();
    }
}

void Poker::newGame()
{
    inputBet();
    rePoker();
    cout << "你得到的牌" << getPokerP() << endl;
}

void Poker::Fold()
{
    if (getTotalM() >= 17)
    {
        if (getTotalM() > getTotalP())
        {
            cout << "莊家的牌為" << getTotalM()<< endl;
            cout << "你輸了，你輸了" << bet << "元" << endl;
            money = money - bet;
            if (money <= 0)
            {
                cout << "笑死，那麼菜把錢輸光光" << endl;
                cout << "別想再玩了，遊戲結束!!!!!!!!!!!!!!!" << endl;
                exit(0);
            }
            inputBet();
            rePoker();
        }
        else if (getTotalM() == getTotalP())
        {
            cout << "莊家的牌為" << getTotalM() << endl;
            cout << "你運氣很好喔~~這局平手" << endl;
            inputBet();
            rePoker();
        }
        else
        {
            cout << "莊家的牌為" << getTotalM() << endl;
            cout << "你贏了，你贏了" << bet << "元" << endl;
            money = money + bet;
            inputBet();
            rePoker();
        }
    }
    else
    {
        makerNeed();
    }
    
}