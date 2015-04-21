#include<iostream>
#include <unistd.h>
#include "BlackjackGame.cpp"
using namespace std;
unsigned int microseconds;
int main(){
    BlackjackGame game(8, 0.25);
    Player p1(10);
    p1.set_strategy(hard, soft, split);
    Player p2(10);
    soft[13][3] = D_H;
    soft[13][4] = D_H;
    p2.set_strategy(hard, soft, split);
    Player p3(10);
    hard[12][3] = STAND;
    hard[12][3] = STAND;
    p3.set_strategy(hard, soft, split);

    //cout << p1.get_wager() << endl;
    game.add_player(p1);
    game.add_player(p2);
    game.add_player(p3);
//    game.addPlayer(p2);
    for(int i = 0; i < 10; i++){
        game.play_round();
        //cout << game.players[0].get_money() << endl;
        //usleep(10000);
//        cout << "1:" << game.players[0].get_money() << endl;
//        cout << "2:" << game.players[1].get_money() << endl;
//        cout << "3:" << game.players[2].get_money() << endl;
        cout << i << endl;
    }
    cout << "1:" << game.players[0].get_money() << endl;
    cout << "2:" << game.players[1].get_money() << endl;
    cout << "3:" << game.players[2].get_money() << endl;

    return 0;
}
