#include<bits/stdc++.h>
using namespace std;

int main(){
    int a, ct = 0;
    cin >> a;
    unsigned int A = a;
    while(A) ct += -A & 1, A >>= 1;
    cout << ct;
    return 0;
}