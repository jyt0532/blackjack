#define HIT 1
#define STAND 2
#define DOUBLE 3
#define SPLIT 4
/*
  0 A 2 3 4 5 6 7 8 9 10 
0
1
2
3
4
5
6
7
8
9
10
11
12
13
14
15
16
17
18+

*/
int hard[22][11] = {
/*  Dealer  0        A       2       3       4       5       6       7       8       9      10
Player*/
/*0*/      {0,       0,      0,      0,      0,      0,      0,      0,      0,      0,      0}
/*1*/    , {0,       0,      0,      0,      0,      0,      0,      0,      0,      0,      0}
/*2*/    , {0,       0,      0,      0,      0,      0,      0,      0,      0,      0,      0}
/*3*/    , {0,       0,      0,      0,      0,      0,      0,      0,      0,      0,      0}
/*4*/    , {0,     HIT,    HIT,    HIT,    HIT,    HIT,    HIT,    HIT,    HIT,    HIT,    HIT}
/*5*/    , {0,     HIT,    HIT,    HIT,    HIT,    HIT,    HIT,    HIT,    HIT,    HIT,    HIT}
/*6*/    , {0,     HIT,    HIT,    HIT,    HIT,    HIT,    HIT,    HIT,    HIT,    HIT,    HIT}
/*7*/    , {0,     HIT,    HIT,    HIT,    HIT,    HIT,    HIT,    HIT,    HIT,    HIT,    HIT}
/*8*/    , {0,     HIT,    HIT,    HIT,    HIT,    HIT,    HIT,    HIT,    HIT,    HIT,    HIT}
/*9*/    , {0,     HIT,    HIT, DOUBLE, DOUBLE, DOUBLE, DOUBLE,    HIT,    HIT,    HIT,    HIT}
/*10*/   , {0,     HIT, DOUBLE, DOUBLE, DOUBLE, DOUBLE, DOUBLE, DOUBLE, DOUBLE, DOUBLE,    HIT}
/*11*/   , {0,  DOUBLE, DOUBLE, DOUBLE, DOUBLE, DOUBLE, DOUBLE, DOUBLE, DOUBLE, DOUBLE, DOUBLE}
/*12*/   , {0,     HIT,    HIT,    HIT,  STAND,  STAND,  STAND,    HIT,    HIT,    HIT,    HIT}
/*13*/   , {0,     HIT,  STAND,  STAND,  STAND,  STAND,  STAND,    HIT,    HIT,    HIT,    HIT}
/*14*/   , {0,     HIT,  STAND,  STAND,  STAND,  STAND,  STAND,    HIT,    HIT,    HIT,    HIT}
/*15*/   , {0,     HIT,  STAND,  STAND,  STAND,  STAND,  STAND,    HIT,    HIT,    HIT,    HIT}
/*16*/   , {0,     HIT,  STAND,  STAND,  STAND,  STAND,  STAND,    HIT,    HIT,    HIT,    HIT}
/*17*/   , {0,   STAND,  STAND,  STAND,  STAND,  STAND,  STAND,  STAND,  STAND,  STAND,  STAND}
/*18*/  , {0,   STAND,  STAND,  STAND,  STAND,  STAND,  STAND,  STAND,  STAND,  STAND,  STAND}
/*19*/  , {0,   STAND,  STAND,  STAND,  STAND,  STAND,  STAND,  STAND,  STAND,  STAND,  STAND}
/*20*/  , {0,   STAND,  STAND,  STAND,  STAND,  STAND,  STAND,  STAND,  STAND,  STAND,  STAND}
/*21*/  , {0,   STAND,  STAND,  STAND,  STAND,  STAND,  STAND,  STAND,  STAND,  STAND,  STAND}
};
int soft[21][11] = {
/*  Dealer  0        A       2       3       4       5       6       7       8       9      10
Player*/
/*0*/      {0,       0,      0,      0,      0,      0,      0,      0,      0,      0,      0}
/*1*/    , {0,       0,      0,      0,      0,      0,      0,      0,      0,      0,      0}
/*2*/    , {0,       0,      0,      0,      0,      0,      0,      0,      0,      0,      0}
/*3*/    , {0,       0,      0,      0,      0,      0,      0,      0,      0,      0,      0}
/*4*/    , {0,       0,      0,      0,      0,      0,      0,      0,      0,      0,      0}
/*5*/    , {0,       0,      0,      0,      0,      0,      0,      0,      0,      0,      0}
/*6*/    , {0,       0,      0,      0,      0,      0,      0,      0,      0,      0,      0}
/*7*/    , {0,       0,      0,      0,      0,      0,      0,      0,      0,      0,      0}
/*8*/    , {0,       0,      0,      0,      0,      0,      0,      0,      0,      0,      0}
/*9*/    , {0,       0,      0,      0,      0,      0,      0,      0,      0,      0,      0}
/*10*/   , {0,       0,      0,      0,      0,      0,      0,      0,      0,      0,      0}
/*11*/   , {0,       0,      0,      0,      0,      0,      0,      0,      0,      0,      0}
/*12*/   , {0,       0,      0,      0,      0,      0,      0,      0,      0,      0,      0}
/*13*/   , {0,     HIT,    HIT,    HIT,    HIT, DOUBLE, DOUBLE,    HIT,    HIT,    HIT,    HIT}
/*14*/   , {0,     HIT,    HIT,    HIT,    HIT, DOUBLE, DOUBLE,    HIT,    HIT,    HIT,    HIT}
/*15*/   , {0,     HIT,    HIT,    HIT, DOUBLE, DOUBLE, DOUBLE,    HIT,    HIT,    HIT,    HIT}
/*16*/   , {0,     HIT,    HIT,    HIT, DOUBLE, DOUBLE, DOUBLE,    HIT,    HIT,    HIT,    HIT}
/*17*/   , {0,     HIT,    HIT, DOUBLE, DOUBLE, DOUBLE, DOUBLE,    HIT,    HIT,    HIT,    HIT}
/*18*/   , {0,     HIT, DOUBLE, DOUBLE, DOUBLE, DOUBLE, DOUBLE,  STAND,  STAND,    HIT,    HIT}
/*19*/   , {0,   STAND,  STAND,  STAND,  STAND,  STAND, DOUBLE,  STAND,  STAND,  STAND,  STAND}
/*20*/  , {0,   STAND,  STAND,  STAND,  STAND,  STAND,  STAND,  STAND,  STAND,  STAND,  STAND}
/*21*/  , {0,   STAND,  STAND,  STAND,  STAND,  STAND,  STAND,  STAND,  STAND,  STAND,  STAND}
};
int split[11][11] = {
/*  Dealer  0        A       2       3       4       5       6       7       8       9      10
Player*/
/*0,0*/    {0,       0,      0,      0,      0,      0,      0,      0,      0,      0,      0}
/*1,1*/  , {0,   SPLIT,  SPLIT,  SPLIT,  SPLIT,  SPLIT,  SPLIT,  SPLIT,  SPLIT,  SPLIT,  SPLIT}
/*2,2*/  , {0,     HIT,  SPLIT,  SPLIT,  SPLIT,  SPLIT,  SPLIT,  SPLIT,    HIT,    HIT,    HIT}
/*3,3*/  , {0,     HIT,  SPLIT,  SPLIT,  SPLIT,  SPLIT,  SPLIT,  SPLIT,    HIT,    HIT,    HIT}
/*4,4*/  , {0,     HIT,    HIT,    HIT,    HIT,  SPLIT,  SPLIT,    HIT,    HIT,    HIT,    HIT}
/*5,5*/   , {0,    HIT, DOUBLE, DOUBLE, DOUBLE, DOUBLE, DOUBLE, DOUBLE, DOUBLE, DOUBLE,    HIT}
/*6,6*/  , {0,     HIT,  SPLIT,  SPLIT,  SPLIT,  SPLIT,  SPLIT,    HIT,    HIT,    HIT,    HIT}
/*7,7*/  , {0,     HIT,  SPLIT,  SPLIT,  SPLIT,  SPLIT,  SPLIT,  SPLIT,    HIT,    HIT,    HIT}
/*8,8*/  , {0,   SPLIT,  SPLIT,  SPLIT,  SPLIT,  SPLIT,  SPLIT,  SPLIT,  SPLIT,  SPLIT,  SPLIT}
/*9,9*/  , {0,   STAND,  SPLIT,  SPLIT,  SPLIT,  SPLIT,  SPLIT,  STAND,  SPLIT,  SPLIT,  STAND}
/*10,10*/, {0,   STAND,  STAND,  STAND,  STAND,  STAND,  STAND,  STAND,  STAND,  STAND,  STAND}
};

