#include<bits/stdc++.h>
using namespace std;

int main(){
    unsigned int a;
    while(cin >> a){
        if(a == 0){
            cout << 0 << endl;
            continue;
        }
        vector<int> arr;
        while(a){
            arr.insert(arr.begin(), a & 1);
            a >>= 1;
        }
        for(int i = 0; i < arr.size(); i++) cout << arr[i];
        cout << endl;
        arr.clear();
    }
    return 0;
}