#include<bits/stdc++.h>
using namespace std;

int main(){
    int n, l, r;
    cin >> n >> l >> r;
    int L = (n >> l) & 1;
    int R = (n >> r) & 1;
    // cout << L << endl << R << endl;
    if(L == R){
        cout << n;
        return 0;
    }
    else{
        if(L == 1) n = n - pow(2, l) + pow(2, r);
        else n = n - pow(2, r) + pow(2, l);
    }
    cout << n;
    return 0;
}