#ifndef COUNTING
#define COUNTING

/*
 *The value in positive_count[5] = 5
 *means we should bet 5*bet_unit when the count is +5 
 * */
int positive_count[20] = 
/* 0    1   2   3   4   5   6   7   8   9*/
{  1,   1,  2,  3,  4,  5,  5,  5,  5,  5, 
/*10   11  12  13  14  15  16  17  18  19*/
   5,   5,  5,  5,  5,  5,  5,  5,  5,  5};

int negative_count[20] = 
/*  0   -1  -2  -3  -4  -5  -6  -7  -8  -9*/
{   1,   1,  1,  1,  1,  1,  1,  1,  1,  1, 
/*-10  -11 -12 -13 -14 -15 -16 -17 -18 -19*/
    1,   1,  1,  1,  1,  1,  1,  1,  1,  1};


#endif
