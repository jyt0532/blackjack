#include<iostream>
#include<stdio.h>
#include<time.h>
#include<vector>
#include "config.cpp"
#include "Strategy.h"
#include "DealerStrategy.h"
#include "Player.cpp"
#include "Dealer.cpp"
#include "SideBet_LuckyLucky.cpp"
using namespace std;

class BlackjackGame{
    public:
        BlackjackGame(int num_of_decks, double percent_of_cards_to_shuffle, int sidebet);
        void add_player(Player new_player);
        void play_round();
        vector<Player> players;
    private:
        DeckOfCard doc;
        bool any_survivors_on_table();
        int sidebet_index;
        void check_sidebet(int sidebet_index, Dealer dealer);
        void LuckyLucky(Dealer dealer);
};
BlackjackGame::BlackjackGame(int num_of_decks, double percent_of_cards_to_shuffle, int sidebet){
    sidebet_index = sidebet;
    doc.set_num_of_decks(num_of_decks);
    doc.set_shuffle_percent(percent_of_cards_to_shuffle);
    //doc.make_up();
    doc.shuffle();
}
void BlackjackGame::add_player(Player new_player){
    players.push_back(new_player);
    return;
}
void BlackjackGame::play_round(){
    Dealer dealer(0);
    dealer.set_strategy(dealer_hard, dealer_soft, dealer_split);
    Hand dealer_hand(doc, 0);
    dealer.hands.push_back(dealer_hand);
    #ifdef VERBOSE
        printf("dealer has: %d\n", dealer.hands[0].get_total());
    #endif
    for(int i = 0; i < players.size(); i++){
        Hand player_hand(doc, players[i].get_wager());
        players[i].hands.push_back(player_hand);
        #ifdef VERBOSE
            printf("player %d has: %d\n", i+1, players[i].hands[0].get_total());
        #endif
    }
    if(dealer.hands[0].is_blackjack()){
        #ifdef VERBOSE
            printf("Dealer BlackJack\n");
        #endif
        for(int i = 0; i < players.size(); i++){
            if(!players[i].hands[0].is_blackjack()){
                #ifdef VERBOSE
                    printf("Player %d lose\n", i+1);
                #endif
                players[i].add_money(-1*players[i].hands[0].get_wager());
            }else{
                #ifdef VERBOSE
                    printf("Player %d push\n", i+1);
                #endif
            }
        }
        check_sidebet(sidebet_index, dealer);
        for(int i = 0; i < players.size(); i++){
            players[i].hands.clear();        
        }
        dealer.hands.clear();
        return;
    }
    for(int i = 0; i < players.size(); i++){
        if(players[i].hands[0].is_blackjack()){
            players[i].add_money(BLACKJACK_PAYS*players[i].hands[0].get_wager());
        }
    }
    Card dealer_up_card = dealer.hands[0].cards[0];
    #ifdef VERBOSE
        printf("=======\n");
        printf("Player check cards, dealer's up card is %d\n", dealer_up_card.get_number());
    #endif
    check_sidebet(sidebet_index, dealer);
    for(int i = 0; i < players.size(); i++){
        int hand_index = 0;
        while(hand_index < players[i].hands.size()){
        #ifdef VERBOSE
            printf("Player %d\t\t%dth hand, total = %d\n", i+1, hand_index+1, players[i].hands[hand_index].get_total());
        #endif
            players[i].check_hand(hand_index, doc, dealer_up_card);
            if(players[i].hands[hand_index].split_or_not()){
                if(players[i].hands.size() < MAX_SPLIT_HANDS){
                    players[i].create_hand(doc, players[i].hands[hand_index].cards[0]);
                    players[i].create_hand(doc, players[i].hands[hand_index].cards[1]);
                    players[i].hands.erase(players[i].hands.begin() + hand_index);
                }else{
                    #ifdef VERBOSE
                        printf("you cannot have more than %d hands", MAX_SPLIT_HANDS);
                    #endif
                }
                continue;
            }
            hand_index++;
        }
    }

    if(any_survivors_on_table()){
        #ifdef VERBOSE
            printf("=======\n");
            printf("Dealer check card\n");
        #endif
        dealer.check_hand(0, doc, dealer_up_card);
    }
    #ifdef VERBOSE
        printf("Dealer has %d\n", dealer.hands[0].get_total());
    #endif
    for(int i = 0; i < players.size(); i++){
        if(players[i].hands[0].is_blackjack() && players[i].hands.size() == 1){
            continue;
        }
        #ifdef VERBOSE
            printf("Player %d\n", i+1);
        #endif
        for(int j = 0; j < players[i].hands.size(); j++){
        #ifdef VERBOSE
            printf("\t%dth hand, total = %d\n",j+1, players[i].hands[j].get_total());
        #endif
            if(players[i].hands[j].get_total() == 0){
                #ifdef VERBOSE
                    printf("\t\tBurst\n");
                #endif
                players[i].add_money(-1*players[i].hands[j].get_wager());
            }else{
                if(players[i].hands[j].get_total() > dealer.hands[0].get_total()){
                    #ifdef VERBOSE
                        printf("\t\tPlayer win\n");
                    #endif
                    players[i].add_money(players[i].hands[j].get_wager());
                }else if(players[i].hands[j].get_total() < dealer.hands[0].get_total()){
                    #ifdef VERBOSE
                        printf("\t\tDealer win\n");
                    #endif
                    players[i].add_money(-1*players[i].hands[j].get_wager());
                }else{
                     #ifdef VERBOSE
                        printf("\t\tPush\n");
                    #endif
                }
            }
        }
    }
    for(int i = 0; i < players.size(); i++){
        players[i].hands.clear();        
    }
    dealer.hands.clear();
}
bool BlackjackGame::any_survivors_on_table(){
    for(int i = 0; i < players.size(); i++){
        for(int j = 0; j < players[i].hands.size(); j++){
            if(players[i].hands[j].get_total() != 0 && !players[i].hands[j].is_blackjack()){
                return true;
            }
        }
    }
    return false;
}
void BlackjackGame::check_sidebet(int sidebet_index, Dealer dealer){
    if(sidebet_index == 1){
        LuckyLucky(dealer);
    }
}
void BlackjackGame::LuckyLucky(Dealer dealer){
    Card card1 = dealer.hands[0].cards[0];
    for(int i = 0; i < players.size(); i++){
        Card card2 = players[i].hands[0].cards[0];
        Card card3 = players[i].hands[0].cards[1];
        if(suited777(card1, card2, card3)){
            players[i].add_sidebet_money(200*players[i].get_sidebet_wager());    
        }else if(suited678(card1, card2, card3)){
            players[i].add_sidebet_money(100*players[i].get_sidebet_wager());    
        }else if(unsuited777(card1, card2, card3)){
            players[i].add_sidebet_money(50*players[i].get_sidebet_wager());    
        }else if(unsuited678(card1, card2, card3)){
            players[i].add_sidebet_money(30*players[i].get_sidebet_wager());    
        }else if(suited21(card1, card2, card3)){
            players[i].add_sidebet_money(15*players[i].get_sidebet_wager());    
        }else if(unsuited21(card1, card2, card3)){
            players[i].add_sidebet_money(3*players[i].get_sidebet_wager());    
        }else if(any20(card1, card2, card3) || any19(card1, card2, card3)){
            players[i].add_sidebet_money(2*players[i].get_sidebet_wager());    
        }else{
            players[i].add_sidebet_money(-1*players[i].get_sidebet_wager());    
        }
    }
}
