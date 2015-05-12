#Blackjack simulation

Should I really split 8-pair against 10?

Why should I hit 16 against 10?

Is counting really helps?

What is the expected return of side bet?

Seeing is believing. You can find all of this answer by yourself.

#Usage

It is a simulation tool of blackjack implemented in c++. After compile, you can just run it.

If you want to see the detailed hand one by one, uncomment the MACRO VERBOSE defined in config.cpp
```
> g++ simulation.cpp
> ./a.out

```
##Strategy

you have three 2-d array which are: hard, soft and split. The format is understandable as below:
```
int hard[22][11] = {
/*  Dealer  0        A       2       3       4       5       6       7       8       9      10
Player*/
/*0*/      {0,       0,      0,      0,      0,      0,      0,      0,      0,      0,      0}
/*1*/    , {0,       0,      0,      0,      0,      0,      0,      0,      0,      0,      0}
/*2*/    , {0,     HIT,    HIT,    HIT,    HIT,    HIT,    HIT,    HIT,    HIT,    HIT,    HIT}
/*3*/    , {0,     HIT,    HIT,    HIT,    HIT,    HIT,    HIT,    HIT,    HIT,    HIT,    HIT}
/*4*/    , {0,     HIT,    HIT,    HIT,    HIT,    HIT,    HIT,    HIT,    HIT,    HIT,    HIT}
/*5*/    , {0,     HIT,    HIT,    HIT,    HIT,    HIT,    HIT,    HIT,    HIT,    HIT,    HIT}
/*6*/    , {0,     HIT,    HIT,    HIT,    HIT,    HIT,    HIT,    HIT,    HIT,    HIT,    HIT}
/*7*/    , {0,     HIT,    HIT,    HIT,    HIT,    HIT,    HIT,    HIT,    HIT,    HIT,    HIT}
/*8*/    , {0,     HIT,    HIT,    HIT,    HIT,    HIT,    HIT,    HIT,    HIT,    HIT,    HIT}
/*9*/    , {0,     HIT,    HIT,    D_H,    D_H,    D_H,    D_H,    HIT,    HIT,    HIT,    HIT}
/*10*/   , {0,     HIT,    D_H,    D_H,    D_H,    D_H,    D_H,    D_H,    D_H,    D_H,    HIT}
/*11*/   , {0,     D_H,    D_H,    D_H,    D_H,    D_H,    D_H,    D_H,    D_H,    D_H,    D_H}
/*12*/   , {0,     HIT,    HIT,    HIT,  STAND,  STAND,  STAND,    HIT,    HIT,    HIT,    HIT}
/*13*/   , {0,     HIT,  STAND,  STAND,  STAND,  STAND,  STAND,    HIT,    HIT,    HIT,    HIT}
/*14*/   , {0,     HIT,  STAND,  STAND,  STAND,  STAND,  STAND,    HIT,    HIT,    HIT,    HIT}
/*15*/   , {0,     HIT,  STAND,  STAND,  STAND,  STAND,  STAND,    HIT,    HIT,    HIT,    HIT}
/*16*/   , {0,     HIT,  STAND,  STAND,  STAND,  STAND,  STAND,    HIT,    HIT,    HIT,    HIT}
/*17*/   , {0,   STAND,  STAND,  STAND,  STAND,  STAND,  STAND,  STAND,  STAND,  STAND,  STAND}
/*18*/   , {0,   STAND,  STAND,  STAND,  STAND,  STAND,  STAND,  STAND,  STAND,  STAND,  STAND}
/*19*/   , {0,   STAND,  STAND,  STAND,  STAND,  STAND,  STAND,  STAND,  STAND,  STAND,  STAND}
/*20*/   , {0,   STAND,  STAND,  STAND,  STAND,  STAND,  STAND,  STAND,  STAND,  STAND,  STAND}
/*21*/   , {0,   STAND,  STAND,  STAND,  STAND,  STAND,  STAND,  STAND,  STAND,  STAND,  STAND}
};
```
You can change any strategy you want and see the expected return(or house edge).

##Rules

1.Dealer hit on soft 17.(You can modify it on DealerStrategy.h)

2.Nun of decks is assigned in BlackjackGame constructor.

3.Player can double after split.

4.Player can resplit to 4 hands(defined in config.cpp)

5.Player cannot hit split aces or resplit aces.

6.No surrender.

7.Blackjack pays defined in config.cpp

##Counting

Your bet unit is assigned when declaring player. You can define the unit of betting with respect to the running count of the remaining deck.
```
int positive_count[20] = 
/* 0    1   2   3   4   5   6   7   8   9*/
{  1,   1,  2,  3,  4,  5,  5,  5,  5,  5, 
/*10   11  12  13  14  15  16  17  18  19*/
int negative_count[20] = 
/*  0   -1  -2  -3  -4  -5  -6  -7  -8  -9*/
{   1,   1,  1,  1,  1,  1,  1,  1,  1,  1, 
/*-10  -11 -12 -13 -14 -15 -16 -17 -18 -19*/
    1,   1,  1,  1,  1,  1,  1,  1,  1,  1};
```
###Note: A positive count gives you about 0.5% advantage against dealer. So you normally raise your bet when the running count is 2 or higher.

##Sidebet 
Now I implemented the luckylucky sidebet. You can place your sidebet when declaring your player.
It can be easily implemented by yourself of any blackjack sidebet.

```
Player p2(10, 5); // 10 dollar main bet and 5 dollar side bet
```

