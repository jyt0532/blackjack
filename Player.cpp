#include<iostream>
#include<time.h>
#include<vector>
#include"Human.cpp"
using namespace std;

class Player : public Human{
    public:
        Player(int initial_wager, int initial_sidebet_wager);
        void create_hand(DeckOfCard doc, Card initial_card);
        void add_money(double amount);
        void add_sidebet_money(double amount);
        double get_money();
        int get_sidebet_wager();
        double get_sidebet_money();
    private:
        double money;
        int sidebet_wager;
        double sidebet_money;
};
Player::Player(int initial_wager, int initial_sidebet_wager) : Human(initial_wager){
    money = 0;
    sidebet_wager = initial_sidebet_wager;
}
void Player::create_hand(DeckOfCard doc, Card initial_card){
    Hand newHand(doc, get_wager(), initial_card);
    hands.push_back(newHand);
}
void Player::add_money(double amount){
    money += amount;
    return;
}
void Player::add_sidebet_money(double amount){
    sidebet_money += amount;
    return;
}
double Player::get_money(){
    return money;
}
double Player::get_sidebet_money(){
    return sidebet_money;
}
int Player::get_sidebet_wager(){
    return sidebet_wager;
}
