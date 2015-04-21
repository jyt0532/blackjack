#include<iostream>
#include<stdio.h>
#include<time.h>
#include<vector>
#include "Cards.cpp"
#include "Strategy.h"
//#define VERBOSE 1
#define MAX_SPLIT_HANDS 4
using namespace std;
#ifndef HAND_CLASS
#define HAND_CLASS
class Hand{
    public:
        Hand(DeckOfCard &doc, int money_to_bet);
        Hand(DeckOfCard &doc, int money_to_bet, Card initial_card);
        void check_cards(DeckOfCard &doc, Card dealer_card, int num_of_hands, int hard[22][11], int soft[22][11],  int split[11][11]);
        int get_total();
        int get_wager();
        void set_wager();
        bool split_or_not();
        vector<Card> cards;
        bool is_blackjack();
    private:
        void take_card(DeckOfCard &doc);
        void check_total();
        int total;
        int wager;
        int num_of_cards;
        int num_of_aces;
        int num_of_aces_count_as_one;
        bool is_split;
};
Hand::Hand(DeckOfCard &doc, int money_to_bet, Card initial_card){
    is_split = false;
    num_of_cards = 1;
    wager = money_to_bet;
    total = initial_card.get_number();
    cards.push_back(initial_card);
}
Hand::Hand(DeckOfCard &doc, int money_to_bet){
    is_split = false;
    wager = money_to_bet;
    total = 0;
    num_of_cards = 0;
    num_of_aces = 0;
    num_of_aces_count_as_one = 0;
    take_card(doc);
    take_card(doc);
}
int Hand::get_total(){
    return total;
}
int Hand::get_wager(){
    return wager;
}
bool Hand::split_or_not(){
    if(!is_split){
        return false;
    }else{
        return true;
    }
}
bool Hand::is_blackjack(){
    if(num_of_cards == 2){
        if(cards[0].get_number() == 1 && cards[1].get_number() == 10){
            return true;
        }
        if(cards[0].get_number() == 10 && cards[1].get_number() == 1){
            return true;
        }
    }
    return false;
}
void Hand::take_card(DeckOfCard &doc){
    Card next = doc.get_next();
    #ifdef VERBOSE
        printf("take %d\n", next.get_number());
    #endif
    total += next.get_number();
    cards.push_back(next);
    num_of_cards++;
    if(next.get_number()== 1){
        num_of_aces++;
        total += 10;
    }
}
void Hand::check_total(){
   if(num_of_aces == 0 || num_of_aces == num_of_aces_count_as_one){
        if(total > 21){
            #ifdef VERBOSE
                printf("burst\n");
            #endif
            total = 0;
        }
    }else{//num_of_aces > num_of_aces_count_as_one 
        if(total > 21){
            total -= 10;
            num_of_aces_count_as_one++;
            check_total();
        }
    }

}
void Hand::check_cards(DeckOfCard &doc, Card dealer_card, int num_of_hands, int hard[22][11], int soft[22][11], int split[11][11]){
    int nextAction;
    if(num_of_cards == 1 && cards[0].get_number() == 1){
        Card next = doc.get_next();
        #ifdef VERBOSE
            printf("take %d\n", next.get_number());
        #endif
        total = 11 + next.get_number();
        num_of_cards++;
        cards.push_back(next);
        nextAction = STAND;
    }else if(num_of_cards == 2 && cards[0].get_number() == cards[1].get_number() && num_of_hands < MAX_SPLIT_HANDS){
        nextAction = split[cards[0].get_number()][dealer_card.get_number()];
    }else if(num_of_aces == 0 || num_of_aces == num_of_aces_count_as_one){
        if(total > 21){
            #ifdef VERBOSE
                printf("burst\n");
            #endif
            total = 0;
        }else{
            nextAction = hard[total][dealer_card.get_number()];
        }
    }else{//num_of_aces > num_of_aces_count_as_one 
        if(total > 21){
            total -= 10;
            num_of_aces_count_as_one++;
            check_cards(doc, dealer_card, num_of_hands, hard, soft, split);
        }else{
            nextAction = soft[total][dealer_card.get_number()];
        }
    }
    switch(nextAction){
        case SPLIT:
            #ifdef VERBOSE
                printf("split\n");
            #endif
            is_split = true;
            break;
        case HIT:
            #ifdef VERBOSE
                printf("hit\n");
            #endif
            take_card(doc);
            check_cards(doc, dealer_card, num_of_hands, hard, soft, split);
            break;
        case STAND:
            #ifdef VERBOSE
                printf("stand\n");
            #endif
            break;
        case D_S:
            if(num_of_cards == 2){
                #ifdef VERBOSE
                    printf("double\n");
                #endif
                wager *= 2;
                take_card(doc);
                check_total();
            }else{
                #ifdef VERBOSE
                    printf("stand\n");
                #endif
            }
            break;
        case D_H:
            if(num_of_cards == 2){
                #ifdef VERBOSE
                    printf("double\n");
                #endif
                wager *= 2;
                take_card(doc);
                check_total();
            }else{
                #ifdef VERBOSE
                    printf("hit\n");
                #endif
                take_card(doc);
                check_cards(doc, dealer_card, num_of_hands, hard, soft, split);
            }
            break;
    }
}
#endif
