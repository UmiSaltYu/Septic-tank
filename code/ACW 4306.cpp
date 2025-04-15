#include<bits/stdc++.h>
using namespace std;

vector<int> arr;
int vis[6005];
// 我觉得是史山，因为感觉上太暴力了
int main(){
    int n, sum = 0, inpu;
    cin >> n;
    while(n--){
        cin >> inpu;
        arr.push_back(inpu);
        vis[inpu]++;
    }
    for(int i = 0; i < arr.size(); i++){
        while(vis[arr[i]] > 1){
            int save = arr[i];
            while(vis[arr[i]] != 0) arr[i]++, sum++;
            vis[arr[i]]++, vis[save]--;
        }
    }
    cout << sum;
    return 0;
}