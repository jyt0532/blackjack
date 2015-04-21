#include<iostream>
#include<time.h>
#include<vector>
#include"Human.cpp"
using namespace std;

class Player : public Human{
    public:
        Player(int initial_wager);
        void create_hand(DeckOfCard doc, Card initial_card);
        void add_money(double amount);
        double get_money();
    private:
        double money;
};
Player::Player(int initial_wager) : Human(initial_wager){
    money = 0;
}
void Player::create_hand(DeckOfCard doc, Card initial_card){
    Hand newHand(doc, get_wager(), initial_card);
    hands.push_back(newHand);
}
void Player::add_money(double amount){
    money += amount;
    return;
}
double Player::get_money(){
    return money;
}
