#include<iostream>
#include<time.h>
#include<vector>
#include"Human.cpp"
using namespace std;

class Dealer : public Human{
    public:
        Dealer(int initial_wager);
//        Dealer();
};
Dealer::Dealer(int initial_wager) : Human(initial_wager){}
//Dealer::Dealer() : Human(0){}

