#include<bits/stdc++.h>
using namespace std;

vector<int> Arr1(16, 0), Arr2(16, 0);

void Calcu(unsigned int A){
    for(int Bit = 0; Bit < 32; Bit++){
        int Num = (A >> Bit) & 1;
        if(Bit < 16) Arr1[Bit] = Num;
        else Arr2[Bit - 16] = Num;
    }
}

int main(){
    unsigned int A, Ans = 0, Save = 1;
    cin >> A;
    Calcu(A);
    for(int i = 0; i < 32; i++){
        if(i < 16) Ans += Arr2[i] * Save;
        else Ans += Arr1[i - 16] * Save;
        Save *= 2;
    }

    cout << Ans;
    return 0;
}