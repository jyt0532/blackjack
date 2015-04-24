#include<iostream>
#include<time.h>
#include<vector>
#include"Human.cpp"
using namespace std;

class Dealer : public Human{
    public:
        Dealer();
};
Dealer::Dealer() : Human(){}

