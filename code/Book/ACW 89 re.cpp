#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
ll calcu(ll a, ll b, ll p){
    int ans = 1 % p;
    for(; b; b >>= 1){
        if(b & 1) ans = (ans * a) % p;
        a = (a * a) % p;
    }

    return ans;
}

int main(){
    int a, b, p;
    cin >> a >> b >> p;
    cout << calcu(a, b, p);
    return 0; 
}