#include<iostream>
#include<time.h>
#include<vector>
using namespace std;

class Dealer{
    public:
        Dealer(DeckOfard doc);
        Card get_up_card();
        void take_cards();
        void check_cards();
        int get_total();
    private:
        Card upcard, downcard;
        int total;
        int num_of_aces;
        int num_of_aces_count_as_one;
};
Dealer::Dealer(DeckOfard doc){
    upcard = doc.get_next();
    downcard = doc.get_next();
    total = (upcard.getNumber() + 1) + (downcard.getNumber() + 1);
    num_of_aces = 0;
    num_of_aces_count_as_one = 0;
    if(upcard.getNumber() + 1 == 1){
        num_of_aces++;
        total += 10;
    }
    if(downcard.getNumber() + 1 == 1){
        num_of_aces++;
        total += 10;
    }

}
Card Dealer::get_up_card(){
    return upcard;
}
int Dealer::get_total(){
    return total;
}
void Dealer::take_cards(DeckOfard doc){
    Card next = doc.get_next();
    total += next.getNumber() + 1;
    if(next.getNumber() + 1 == 1){
        num_of_aces++;
        total += 10;
    }
}
void Dealer::check_cards(DeckOfard doc){
    if(total > 21){
        if(num_of_aces == num_of_aces_count_as_one){
            total = 0;
        }else{
            total -= 10;
            num_of_aces_count_as_one++;
            take_cards(doc);
            check_cards(doc);
        }
    }else if(total >= 18){
        return;
    }else if(total == 17 && num_of_aces == num_of_aces_count_as_one){
        return;
    }else if(total == 17 && num_of_aces > num_of_aces_count_as_one){//soft17
        total -= 10;
        num_of_aces_count_as_one++;
        take_cards(doc);
        check_cards(doc);
    }else{
        take_cards(doc);
        check_cards(doc);
    }
}

