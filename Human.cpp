#include<iostream>
#include<time.h>
#include<vector>
using namespace std;

class Human{
    public:
        Human(int initial_wager);
        int get_wager();
        void setStrategy(int hard_strategy[22][11], int soft_strategy[21][11], int split_strategy[21][11]);
    private:
        vector<Hand> hands;
        int wager;
        vectot<vector<int> > hard(22, vector<int>(11, 0));;
        vectot<vector<int> > soft(21, vector<int>(11, 0));
        vectot<vector<int> > split(11, vector<int>(11, 0));
};
Human::Human(int initial_wager){
    wager = initial_wager;

}
int Human::get_wager(){
    return wager;
}
void setStrategy(int hard_strategy[22][11], int soft_strategy[21][11], int split_strategy[21][11]){
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

