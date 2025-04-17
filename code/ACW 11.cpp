#include<bits/stdc++.h>
using namespace std;

const int MAX_NUM = 1e9 + 7;
int dp[1005][1005], dpv[1005][1005], itv[1005], itw[1005], ans = 0;

int main(){
    int n, v;
    cin >> n >> v;
    for(int i = 1; i <= n; i++) cin >> itv[i] >> itw[i];
    for(int i = 1; i <= n; i++)
        for(int j = 0; j <= v; j++){
            dp[i][j] = dp[i - 1][j];
            if(j >= itv[i]) dp[i][j] = max(dp[i][j], dp[i - 1][j - itv[i]] + itw[i]);
        }
    // 相当于要两次dp，一次是整理价值，一次是整理方案数目
    // 先学会朴素写法再说，然后看看如何优化到一维
    dpv[0][0] = 1;
    for(int i = 1; i <= n; i++)
        for(int j = 0; j <= v; j++){
            // 三种情况（？）
            if(dp[i][j] == dp[i - 1][j]) dpv[i][j] = (dpv[i][j] + dpv[i - 1][j]) % MAX_NUM;
            if(j >= itv[i] && dp[i][j] == dp[i - 1][j - itv[i]] + itw[i]) dpv[i][j] = (dpv[i][j] + dpv[i - 1][j - itv[i]]) % MAX_NUM;
        }
    for(int i = 0; i <= v; i++)
        if(dp[n][i] == dp[n][v]) ans = (ans + dpv[n][i]) % MAX_NUM;

    cout << ans % MAX_NUM;
    return 0;
}   