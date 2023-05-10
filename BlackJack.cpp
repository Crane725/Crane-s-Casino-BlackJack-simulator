#include"BlackJack21.h"


void cardHeap::getCard()
{
    int r = (rand()%13)+1;
    if(r>10) r=10;
    card[cardNum]=r;
    cardNum++;
}


bool cardHeap::getBust()
{
    int add=0;
    for(int i=0;i<cardNum;i++) add+=card[i];
    if(add>21) return true;
    else return false;
}


bool cardHeap::getSeven()
{
    if(getBust()==false&&cardNum==7) return true;
    else return false;
}


bool cardHeap::isBlackJack()
{
    if(cardNum==2&&(card[0]==1&&card[1]==10)||(card[0]==10&&card[1]==1)) return true;
    else return false;
}


int cardHeap::sumMax()
{
    int numA=0,Max=0;
    for(int i=0;i<cardNum;i++)
    {
        if(card[i]==1) numA++;
        Max+=card[i];
    }
    while(Max+10<=21&&numA>0)
    {
        Max+=10;
        numA--;
    }
    return Max;
}


void cardHeap::dealerShow()
{
    cout<<"*"<<" ";
    for(int i=1;i<cardNum;i++) cout<<card[i]<<" ";
    cout<<endl;
}

void cardHeap::playerShow()
{
    for(int i=0;i<cardNum;i++) cout<<card[i]<<" ";
    cout<<endl;
}
