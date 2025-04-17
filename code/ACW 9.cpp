#include<bits/stdc++.h>
using namespace std;

struct itdata{
    int v, w;
}inpu;

vector<itdata> items[105];
int dp[105][105];


int main(){
    int n, v, num;
    cin >> n >> v;
    for(int i = 1; i <= n; i++){
        cin >> num;
        while(num--){
            cin >> inpu.v >> inpu.w;
            items[i].push_back(inpu);
        }
    }// 输入部分
    for(int i = 1; i <= n; i++)
        for(int k = 1; k <= v; k++){
            dp[i][k] = dp[i - 1][k];// 请时刻注意i是组，k才是容量
            for(int j = 0; j < items[i].size(); j++)
                if(k >= items[i][j].v)
                    dp[i][k] = max(dp[i][k], dp[i - 1][k - items[i][j].v] + items[i][j].w);
        }
    cout << dp[n][v];
    return 0;
}