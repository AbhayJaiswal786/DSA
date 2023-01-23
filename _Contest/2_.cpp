#include<bits/stdc++.h>
using namespace std;
int main(){
    string S="abcbac";
    int N=6;
    vector<int> vec;
    for(int i=1;i<N;i++){
        int count=0;
        for(int j=1;j+i<=N;j++){
            if(!(S[j-1]==S[j+i-1])){
                count++;      
            }
            else{
                break;                
            }
        }
        vec.push_back(count);
    }

    
    for(int i=0;i<vec.size();i++){
        cout<<vec[i]<<endl;
    }


}