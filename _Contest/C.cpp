#include<bits/stdc++.h>
using namespace std;
int main(){
    string S="CB";
    int len=S.length();
    long value=0;
    for(int i=0;i<len;i++){
        value=value+((int(S[i])-64)*pow(26,len-i-1));
    }

    cout<<value;
}