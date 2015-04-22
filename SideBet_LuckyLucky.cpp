#include<iostream>
#include<vector>
#include<algorithm>
#include"Cards.cpp"
using namespace std;

bool suited777(Card card1, Card card2, Card card3){
    if(card1.get_number() == 7 && card2.get_number() == 7 && card3.get_number() == 7){
        if(card1.get_suit() == card2.get_suit() && card2.get_suit() == card3.get_suit()){
            return true;
        }
    }
    return false;
}
bool is678(int num1, int num2, int num3){
    vector<int> num;
    num.push_back(num1);
    num.push_back(num2);
    num.push_back(num3);
    sort(num.begin(), num.end());
    if(num[0] == 6 && num[1] == 7 && num[2] == 8){
        return true;
    }
    return false;
}

bool suited678(Card card1, Card card2, Card card3){
    if(card1.get_suit() == card2.get_suit() && card2.get_suit() == card3.get_suit()){
        if(is678(card1.get_number(), card2.get_number(), card3.get_number())){
            return true;
        }
    }
    return false;
}
bool unsuited777(Card card1, Card card2, Card card3){
    if(card1.get_number() == 7 && card2.get_number() == 7 && card3.get_number() == 7){
        if(!(card1.get_suit() == card2.get_suit() && card2.get_suit() == card3.get_suit())){
            return true;
        }
    }
    return false;
}
bool unsuited678(Card card1, Card card2, Card card3){
    if(!(card1.get_suit() == card2.get_suit() && card2.get_suit() == card3.get_suit())){
        if(is678(card1.get_number(), card2.get_number(), card3.get_number())){
            return true;
        }
    }
    return false;
}
bool sum_up_to(int num1, int num2, int num3, int target){
    if(num1 + num2 + num3 == target){
        return true;
    }
    if(num1 == 1 || num2 == 1 || num3 == 1){
        if(num1 + num2 + num3 + 10 == target){
            return true;
        }
    }
    return false;

}
bool suited21(Card card1, Card card2, Card card3){
    if(sum_up_to(card1.get_number(), card2.get_number(), card3.get_number(), 21)){
        if(card1.get_suit() == card2.get_suit() && card2.get_suit() == card3.get_suit()){
            return true;
        }
    }
    return false;
}
bool unsuited21(Card card1, Card card2, Card card3){
    if(sum_up_to(card1.get_number(), card2.get_number(), card3.get_number(), 21)){
        if(!(card1.get_suit() == card2.get_suit() && card2.get_suit() == card3.get_suit())){
            return true;
        }
    }
    return false;
}
bool any20(Card card1, Card card2, Card card3){
    if(sum_up_to(card1.get_number(), card2.get_number(), card3.get_number(), 20)){
        return true;
    }
    return false;
}
bool any19(Card card1, Card card2, Card card3){
    if(sum_up_to(card1.get_number(), card2.get_number(), card3.get_number(), 19)){
        return true;
    }
    return false;
}
/*int main(){
    cout << is678(6,8,7) << endl;
}*/
