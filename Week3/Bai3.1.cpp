// Sok Sokong 20211005

#include<iostream>
using namespace std;

int lucas(int n) {
    if(n==0) return 2;
    if(n==1) return 1;

    else return lucas(n-1)+lucas(n-2);
}