#include <iostream>
#include <time.h>
#include <vector>
#include "Hand.cpp"
using namespace std;
#ifndef HUMAN_CLASS
#define HUMAN_CLASS
class Human{
    public:
        Human(int initial_wager);
        int get_wager();
        void set_strategy(int hard_strategy[22][11], int soft_strategy[22][11], int split_strategy[11][11]);
        vector<Hand> hands;
        int hard[22][11];
        int soft[22][11];
        int split[11][11];
        void check_hand(int hand_index, DeckOfCard &doc, Card dealer_card);
    protected:
        int wager;
};
Human::Human(int initial_wager){
    wager = initial_wager;
}
int Human::get_wager(){
    return wager;
}
void Human::set_strategy(int hard_strategy[22][11], int soft_strategy[22][11], int split_strategy[11][11]){
    for(int i = 0; i < 22; i++){
        for(int j = 0; j < 11; j++){
            hard[i][j] = hard_strategy[i][j];
        }
    }
    for(int i = 0; i < 21; i++){
        for(int j = 0; j < 11; j++){
            soft[i][j] = soft_strategy[i][j];
        }
    }
    for(int i = 0; i < 11; i++){
        for(int j = 0; j < 11; j++){
            split[i][j] = split_strategy[i][j];
        }
    }
}
void Human::check_hand(int hand_index, DeckOfCard &doc, Card dealer_card){
    hands[hand_index].check_cards(doc, dealer_card, hands.size(), hard, soft, split);
    return;
}
#endif
