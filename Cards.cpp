#include<iostream>
#include<stdio.h>
#include<time.h>
#include<vector>
using namespace std;
#ifndef Card_CLASS
#define Card_CLASS
enum Suit{
    club, diamond, heart, spade
};
/*enum Number{
    1,2,3,4,5,6,7,8,9,10,j,q,k
};*/

class Card{
    public:
        Card(Suit s, int n){
            suit = s;   
            number = n;
        }
        void operator= (const Card & other){
            suit = other.suit;
            number = other.number;
        }
        Suit get_suit();
        int get_number();
        void print_card();
    private:
        Suit suit;
        int number;
};
Suit Card::get_suit(){
    return suit;
}
int Card::get_number(){
    if(number < 10){
        return number+1;
    }else{
        return 10;
    }
}
void Card::print_card(){
    cout <<  get_suit() << " " << get_number() << endl;
}
class DeckOfCard{
    public:
        DeckOfCard(int n);
        DeckOfCard();
        int get_num_of_decks();
        void shuffle();
        void make_up();
        void print();
        Card get_next();
        void set_num_of_decks(int n);
        void set_shuffle_percent(double percent_of_cards_to_shuffle);
    private:
        int card_index;
        int num_of_decks;
        double pocts;
        vector<Card> cards;
        void swap_card(Card &card1, Card &card2);
        void create_deck_of_cards(int n);
};
DeckOfCard::DeckOfCard(){
    create_deck_of_cards(1);
}
DeckOfCard::DeckOfCard(int n){
    create_deck_of_cards(n);
}
void DeckOfCard::set_shuffle_percent(double percent_of_cards_to_shuffle){
    pocts = percent_of_cards_to_shuffle;
}
void DeckOfCard::create_deck_of_cards(int n){
    num_of_decks = n;
    card_index = 0;
    cards.clear();
    for(int i = 0; i < n; i++){
        for(int j = 0; j < 52; j++){
            Card card((Suit)(j/13), (int)(j%13));
            cards.push_back(card);
        }
    }
}
void DeckOfCard::set_num_of_decks(int n){
    create_deck_of_cards(n);
}
int DeckOfCard::get_num_of_decks(){
    return num_of_decks;
}
void DeckOfCard::shuffle(){
    srand(time(NULL));
    for(int i = 52*num_of_decks-1; i >= 0; i--){
        int r = rand()%(i+1);
        swap_card(cards[i], cards[r]);
    }
}
void DeckOfCard::make_up(){
    swap_card(cards[0], cards[41]);//3
    swap_card(cards[1], cards[46]);//8
    swap_card(cards[2], cards[59]);//8
    swap_card(cards[3], cards[72]);//8
    swap_card(cards[4], cards[52]);//1
    swap_card(cards[5], cards[110]);//7
    swap_card(cards[6], cards[113]);//10
    swap_card(cards[7], cards[123]);//7
    swap_card(cards[8], cards[122]);//6
    swap_card(cards[9], cards[124]);//8
    swap_card(cards[10], cards[125]);//9
    swap_card(cards[11], cards[136]);//7
    swap_card(cards[12], cards[138]);//9
    swap_card(cards[13], cards[58]);//7
    swap_card(cards[14], cards[152]);//1
    swap_card(cards[15], cards[85]);//8
    swap_card(cards[16], cards[98]);//8
    swap_card(cards[17], cards[111]);//8
    swap_card(cards[18], cards[107]);//4
    swap_card(cards[19], cards[184]);//1
    swap_card(cards[20], cards[109]);//6
    swap_card(cards[21], cards[133]);//10
    swap_card(cards[22], cards[126]);//10
    swap_card(cards[23], cards[125]);//9
}

void DeckOfCard::swap_card(Card &card1, Card &card2){
    Card tmp = card1;
    card1 = card2;
    card2 = tmp;
    return;
}
Card DeckOfCard::get_next(){
    Card nextCard = cards[card_index];
    card_index++;
    if(num_of_decks*52 - card_index < (int)(num_of_decks*52*pocts)){
        shuffle();
        card_index = 0;
    }
    return nextCard;
}
void DeckOfCard::print(){
    for(int i = 0; i < num_of_decks*52; i++){
        cout << (int)cards[i].get_suit() << " " << (int)cards[i].get_number() << endl;
    }
    return;
}
/*
int main(){
    DeckOfCard doc;
    doc.set_num_of_decks(8);
//    doc.print();
//    doc.shuffle();
    doc.make_up();
    doc.print();
//    doc.get_next().printCard();
    return 0;
}*/
#endif
