## 原题链接
[998. 起床困难综合症](https://www.acwing.com/problem/content/1000/)

## 生锈的单核CPU理解
~~本人脑子不是很好用理解慢也理解不是很透彻望理解也请大佬轻喷orz（跪）~~

这里用的是位运算，~~我刚开始学这本书~~
题目说要通过n扇门，等于n次操作
对于某个数，可以把其二进制的每一位单独拎出来算
但是我们求的不是这个数，而是在m范围内最大的攻击力
于是代码如下（可能注释还有补充一些）

## 代码
```cpp
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
```

