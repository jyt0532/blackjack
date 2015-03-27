#include<iostream>
#include<time.h>
#include<vector>
using namespace std;
enum Suit{
    club, diamond, heart, spade
};
/*enum Number{
    1,2,3,4,5,6,7,8,9,10,j,q,k
};*/
enum Number{
    Ace, Two, Three, Four, Five, Six, Seven, Eight, Nine, Ten, Jack, Queen, King
};

class Card{
    public:
        Card(Suit s, Number n){
            suit = s;   
            number = n;
        }
        void operator= (const Card & other){
            suit = other.suit;
            number = other.number;
        }
        Suit getSuit();
        Number getNumber();
    private:
        Suit suit;
        Number number;
};
Suit Card::getSuit(){
    return suit;
}
Number Card::getNumber(){
    if(number < 10){
        return number;
    }else{
        return 10;
    }
}
class DeckOfCard{
    public:
        DeckOfCard(int n);
        int get_num_of_decks();
        void shuffle();
        void print();
        Card get_next();
    private:
        int card_index;
        int num_of_decks;
        vector<Card> cards;
        void swapCard(Card &card1, Card &card2);
};
DeckOfCard::DeckOfCard(int n){
    num_of_decks = n;
    card_index = 0;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < 52; j++){
            Card card((Suit)(j/13), (Number)(j%13));
            cards.push_back(card);
        }
    }
}
int DeckOfCard::get_num_of_decks(){
    return num_of_decks;
}
void DeckOfCard::shuffle(){
    for(int i = 51; i >= 0; i--){
        int r = rand()%(i+1);
        swapCard(cards[i], cards[r]);
    }
}
void DeckOfCard::swapCard(Card &card1, Card &card2){
    Card tmp = card1;
    card1 = card2;
    card2 = tmp;
    return;
}
Card DeckOfCard::get_next(){
    Card nextCard = cards[card_index];
    card_index++;
    if(num_of_decks*52 - card_index < 30){
        shuffle();
        card_index = 0;
    }
    return nextCard;
}
void DeckOfCard::print(){
    for(int i = 0; i < num_of_decks*52; i++){
        cout << (int)cards[i].getSuit() << " " << (int)cards[i].getNumber() << endl;
    }
    return;
}
int main(){
    DeckOfCard doc(3);
    doc.print();
    doc.shuffle();
    doc.print();
    return 0;
}
