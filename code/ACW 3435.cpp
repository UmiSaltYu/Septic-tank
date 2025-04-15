#include<bits/stdc++.h>
using namespace std;

const unsigned short MAX_NUM = 32768;

int main(){
    unsigned short a, b;
    while(cin >> a >> b){
        int judge = 0;
        for(int i = 0; i < 16; i++){
            if(a & MAX_NUM) a = (a << 1) + 1;
            else a = a << 1;
            if(a == b){
                judge = 1;
                break;
            }
        }
        if(judge == 1) cout << "YES" << endl;
        else cout << "NO" << endl;
    }
    return 0;
}