#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> arr(4);

int main(){
    int sizep, inpu1, inpu2, inpu3, times, ans = 0;
    cin >> sizep;
    for(int i = 1; i <= 3; i++)
        for(int j = 1; j <= sizep; j++){
            cin >> inpu1;
            arr[i].push_back(inpu1);
        }
    //三个指针用来模拟
    int p1 = 0, p2 = 0, p3 = 0;
    cin >> times;
    while(times--){
        cin >> inpu1 >> inpu2 >> inpu3;
        p1 = (p1 + inpu1) % sizep;
        p2 = (p2 + inpu2) % sizep;
        p3 = (p3 + inpu3) % sizep;
        //超级判断时间⭐
        //这就是史
        if(arr[1][p1] == arr[2][p2] && arr[1][p1] == arr[3][p3]) ans += 200;
        else if(arr[1][p1] == arr[2][p2] - 1 && arr[1][p1] == arr[3][p3] - 2) ans += 200;
        else if(arr[1][p1] == arr[2][p2] || arr[1][p1] == arr[3][p3] || arr[2][p2] == arr[3][p3])
            ans += 100;
        else if((arr[2][p2] == arr[3][p3] + 1 && arr[3][p3] == arr[1][p1] + 1)
            ||  (arr[3][p3] == arr[1][p1] + 1 && arr[1][p1] == arr[2][p2] + 1)
            ||  (arr[2][p2] == arr[1][p1] + 1 && arr[1][p1] == arr[3][p3] + 1)
            ||  (arr[1][p1] == arr[3][p3] + 1 && arr[3][p3] == arr[2][p2] + 1)
            ||  (arr[1][p1] == arr[2][p2] + 1 && arr[2][p2] == arr[3][p3] + 1))
            ans += 100;
    }
    cout << ans;
    return 0;
}