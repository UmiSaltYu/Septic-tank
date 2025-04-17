// #include<bits/stdc++.h>
// using namespace std;

// int cur = 0;
// vector<int> arr;

// void idkwhat(int maxn, int n, int step, int last){
//     if(step > maxn){
//         for(int i = 0; i < arr.size(); i++){
//             cout << arr[i] << ' ';
//         }
//         cout << endl;
//         return;
//     }

//     for(int i = 1; i <= n; i++){
//         if(i > last){
//             arr.push_back(i);
//             idkwhat(maxn, n, step + 1, i);
//             arr.pop_back();
//         }
//     }
// }

// int main(){
//     int n;
//     cin >> n;
//     for(int i = 0; i <= n; i++){
//         if(i == 0) cout << endl;
//         else{
//             idkwhat(i, n, 1, 0);
//         }
//     }
//     return 0;
// }

//简化
//这个思路真的好巧妙
#include<bits/stdc++.h>
using namespace std;

int n;
vector<int> arr;

void idkwhat(int cur){
    if(cur > n){
        for(int i = 0; i < arr.size(); i++)
            cout << arr[i] << ' ';
        cout << endl;
        return;
    }

    idkwhat(cur + 1);

    arr.push_back(cur);
    idkwhat(cur + 1);
    arr.pop_back();
}

int main(){
    cin >> n;
    idkwhat(1);
    return 0;
}