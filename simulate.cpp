#include<iostream>
#include <unistd.h>
#include "BlackjackGame.cpp"
#define NUM_OF_ROUNDS 1000000
using namespace std;
int main(){
    BlackjackGame game(8, 0.25, 1);
    Player p1(10, 1);
    p1.set_strategy(hard, soft, split);
    Player p2(10, 5);
    p2.set_strategy(hard, soft, split);
/*
 *Modify any stragety as you want to see the expected return
 * 
 *   hard[12][3] = STAND;
 *   soft[13][4] = D_H;
 *   split[8][10] = HIT;
 *   split[8][1] = HIT;
*/
    Player p3(10, 0);
    p3.set_strategy(hard, soft, split);

    game.add_player(p1);
    game.add_player(p2);
    game.add_player(p3);
    for(int i = 0; i < NUM_OF_ROUNDS; i++){
        game.play_round();
        game.players[0].modify_bet_by_count(game.doc.get_running_count());
    }

    cout << "1:" << game.players[0].get_money() << endl;
    cout << "2:" << game.players[1].get_money() << endl;
    cout << "3:" << game.players[2].get_money() << endl;
    cout << "1:" << game.players[0].get_sidebet_money() << endl;
    cout << "2:" << game.players[1].get_sidebet_money() << endl;
    cout << "3:" << game.players[2].get_sidebet_money() << endl;

    return 0;
}
