#include"BlackJack.cpp"
using namespace std;

int main()
{
    float n,win=0,lose=0,draw=0;
    int money=50000;
    srand((int)time(0));
    cout<<"WELCOME TO Crane`s CASINO!!!(Type 1 to begin) "<<endl;
    cin>>n;
    while(n==1)
    {
        int chips, choice;
        cout<<"You have"<<money<<"$ now. Choose your chips ( between min 100$ and max 50000$ ) : ";
        cin>>chips;
        if(chips>50000) chips=50000;if(chips<100) chips=100;
        if(chips>money)
        {
            cout<<"You have no more chips to play. But we do provide loan service. Wanna you have a try?(Type 1 to accept; 2 to quit) "<<endl;
            cin>>choice;
            if(choice==2) break;
        }
        money-=chips;
        cardHeap dealer,player;
        dealer.getCard();dealer.getCard();
        player.getCard();player.getCard();
        cout<<" The dealer now has "<<endl;
        dealer.dealerShow();
        cout<<" You now have "<<endl;
        player.playerShow();
        cout<<"now your sum is "<<player.sumMax()<<endl;
        if(player.isBlackJack()==true)
        {
            cout<<"CONGRUATULATIONS~v~,BLACKJACK!!!You win!"<<endl;
            money += 2*chips;
            win++;
        }
        else
        {
            int nxt;
            do
            {
                cout<<"What do you want next?(1 to Hit; 2 to Stand;)"<<endl;
                cin>>nxt;
                switch(nxt)
                {
                case 1:
                    player.getCard();
                    player.playerShow();
                    cout<<"now your sum is "<<player.sumMax()<<endl;
                    if(player.getBust()==true)
                    {
                        cout<<"You get a bust. You lose."<<endl;
                        lose++;
                        nxt=2;
                    }
                    if(player.getSeven()==true)
                    {
                        cout<<"You reach 7. You win!"<<endl;
                        money+= 2*chips;
                        win++;
                        nxt=2;
                    }
                    break;
                case 2:
                    cout<<"Finally your sum is "<<player.sumMax()<<endl;
                    break;
                default: break;
                }
            }while(nxt==1);
            if(player.getBust()==false&&player.getSeven()==false)
            {
                cout<<"Now is the dealer`s turn "<<endl;
                cout<<"Now the dealer`s cards is "<<endl;dealer.playerShow();
                if(dealer.isBlackJack()!=true)
                {
                    while(dealer.sumMax()<=player.sumMax()&&dealer.sumMax()<=16&&dealer.getBust()==false&&dealer.getSeven()==false)
                    {
                        cout<<"Dealer chooses to hit. "<<endl;
                        dealer.getCard();
                        cout<<"Now the dealer`s cards is "<<endl;dealer.playerShow();
                    }
                    if(dealer.getBust()==false) cout<<"Dealer chooses to stand. "<<endl;
                }
            if(dealer.isBlackJack()==true)
            {
                cout<<"Dealer is BlackJack. You lose. "<<endl;
                lose++;
            }
            else if(dealer.getBust()==true)
            {
                cout<<"Dealer gets bust. You win!"<<endl;
                money+= 2*chips;
                win++;
            }
            else if(dealer.getSeven()==true)
            {
                cout<<"Dealer gets seven cards. You lose. "<<endl;
                lose++;
            }
            else
            {
                if(dealer.sumMax()<player.sumMax())
                {
                    cout<<"You`re bigger than dealer. You win!"<<endl;
                    money += 2*chips;
                    win++;
                }
                else if(dealer.sumMax()>player.sumMax())
                {
                    cout<<"Dealer is bigger than you. You lose. "<<endl;
                    lose++;
                }
                else
                {
                    cout<<"Draw for you two ."<<endl;
                    draw++;
                    money+=chips;
                }
            }
            }
        }
        cout<<endl;
        cout<<"Now your money is"<<money<<endl;
        if(money<0)
        {
            cout<<"Give my money back! you ! The Poor!!! "<<endl;
            break;
        }
        cout<<"type 1 to start another play "<<endl;cout<<"--------------------------------"<<endl;
        cin>>n;
    }
    n = win + lose + draw;
    cout<<"Game over. Your final money is "<<money<<"| win/win rate : "<<win<<"/"<<win/n<<" ; lose/lose rate : "<<lose<<"/"<<lose/n<<" ; draw/draw rate : "<<draw<<"/"<<draw/n<<endl;
    return 0;
}
