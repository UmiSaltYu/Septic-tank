#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
pair<string, ll> op[114514];
ll n, m;
// 这里计算的是某一位是1 | 0的时候，对最终结果的影响
ll calcu(int bit, int cur){
    for(int i = 0; i < n; i++){
        int x = op[i].second >> bit & 1;
        if(op[i].first == "AND") cur &= x;
        else if(op[i].first == "OR") cur |= x;
        else cur ^= x;
    }
    return cur;
}

int main(){
    ll val = 0, ans = 0;
    cin >> n >> m;
    for(int i = 0; i < n; i++){
        string inpu1;
        ll inpu2;
        cin >> inpu1 >> inpu2;
        op[i] = make_pair(inpu1, inpu2);
    }
    // 为什么是29？规定的1e9约等于2^30, 二进制下约等于第30位前面位全为1的值（不包括第三十位）
    // 即为2^30 - 1
    for(int i = 29; i >= 0; i--){
        ll res1 = calcu(i, 1);
        ll res0 = calcu(i, 0);
        // 选择1的条件是，加上所选的值以后不超过m，且选1的价值大于选0
        if(val + (1 << i) <= m && res1 > res0)
            val += 1 << i, ans += res1 << i;
        else
            ans += res0 << i;
        // 因为求的是价值（攻击力），这里的意思是选择0作为第i位，res0求的就是这一位用0的影响
    }
    cout << ans;
}