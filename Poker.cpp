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
    pokerName[1] = "�®�A";
    pokerName[2] = "�®�2";
    pokerName[3] = "�®�3";
    pokerName[4] = "�®�4";
    pokerName[5] = "�®�5";
    pokerName[6] = "�®�6";
    pokerName[7] = "�®�7";
    pokerName[8] = "�®�8";
    pokerName[9] = "�®�9";
    pokerName[10] = "�®�10";
    pokerName[11] = "�®�J";
    pokerName[12] = "�®�Q";
    pokerName[13] = "�®�K";
    pokerName[14] = "����A";
    pokerName[15] = "����2";
    pokerName[16] = "����3";
    pokerName[17] = "����4";
    pokerName[18] = "����5";
    pokerName[19] = "����6";
    pokerName[20] = "����7";
    pokerName[21] = "����8";
    pokerName[22] = "����9";
    pokerName[23] = "����10";
    pokerName[24] = "����J";
    pokerName[25] = "����Q";
    pokerName[26] = "����K";
    pokerName[27] = "���A";
    pokerName[28] = "���2";
    pokerName[29] = "���3";
    pokerName[30] = "���4";
    pokerName[31] = "���5";
    pokerName[32] = "���6";
    pokerName[33] = "���7";
    pokerName[34] = "���8";
    pokerName[35] = "���9";
    pokerName[36] = "���10";
    pokerName[37] = "���J";
    pokerName[38] = "���Q";
    pokerName[39] = "���K";
    pokerName[40] = "����A";
    pokerName[41] = "����2";
    pokerName[42] = "����3";
    pokerName[43] = "����4";
    pokerName[44] = "����5";
    pokerName[45] = "����6";
    pokerName[46] = "����7";
    pokerName[47] = "����8";
    pokerName[48] = "����9";
    pokerName[49] = "����10";
    pokerName[50] = "����J";
    pokerName[51] = "����Q";
    pokerName[52] = "����K";
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
void Poker::rePoker()
{
    cout << "�s�@���C���}�l�A�}�l�~�P........" << endl;

    pokerM[0] = randNum[j++];  
    pokerM[1] = randNum[j++]; 
    pokerP[0] = randNum[j++]; 
    pokerP[1] = randNum[j++]; 

    pokerNumM = 2;
    pokerNumP = 2;

    cout << "�~�P����,�A���P��:" << getPokerP() << endl;
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
        result = result + pokerName[pokerP[i]] + " ";

    return result;
}
int Poker::getTotalM()
{
    int result = 0;

    for (int i = 0; i < pokerNumP; i++)
        result = result + pokerName[pokerP[i]] + " ";
    return result;
}
void Poker::playerNeed()
{
    if (pokerNumP >= 5)
    {
        cout << "�A�w�g�L�����F�A����A�n�P�F" << endl;
        Fold();
    }
    else
    {
        pokerP[pokerNumP++] = randNum[j++];
        cout << "�A���P��:" << getPokerP() << endl;
        if (getTotalP() > 21)
        {
            cout << "�A���I�Ƥw�g�z�F�A�A��F"<<bet<<"��"<< endl;
            money = money - bet;
            if (money <= 0)
            {
                cout << "�A�w�g�S���F~�A�U���V�O"<<endl;
                cout << "GameOver!" << endl;
                exit(0);
            }
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
            cout<<"���a���P��"
        }
    }
}