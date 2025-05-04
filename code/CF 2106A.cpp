#include<bits/stdc++.h>
using namespace std;

int main(){
    string inpu;
    int n, len;
    cin >> n;
    while(n--) {
        int num = 0;
        cin >> len >> inpu;
        for(int i = 0; i < len; i++) {
            string copys = inpu;
            if(copys[i] == '0') copys[i] = '1';
            else copys[i] = '0';
            for(int i = 0; i < len; i++) if(copys[i] == '1') num++;
        }
        cout << num << endl;
    }
    return 0;
}