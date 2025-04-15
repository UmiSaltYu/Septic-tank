#include<bits/stdc++.h>
using namespace std;

typedef unsigned long long ll;
ll calcu(ll a, ll b, ll p){
    ll ans = 0, num = 1;
    for(; b; b >>= 1){
        // a * b == a * 2^i1 + a * 2^i2 + .....
        // 相当于a乘2的次数
        if(b & 1) ans = (ans + a) % p;
        a = (a * 2) % p;
    }
    return ans;
}


int main(){
    ll a, b, p;
    cin >> a >> b >> p;
    cout << calcu(a, b, p);
    return 0;
}