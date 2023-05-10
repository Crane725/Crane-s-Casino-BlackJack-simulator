#ifndef BLACKJACK21_H_INCLUDED
#define BLACKJACK21_H_INCLUDED
#include<iostream>
#include<stdlib.h>
#include<ctime>
using namespace std;
class cardHeap
{
private:
    int *card;
    int cardNum;
public:
    cardHeap(){card=new int[7];cardNum=0;}
    ~cardHeap(){delete [] card;}
    void getCard();

    bool getSeven();
    bool getBust();
    bool isBlackJack();
    int sumMax();
    void dealerShow();
    void playerShow();
};
#endif // BLACKJACK21_H_INCLUDED




