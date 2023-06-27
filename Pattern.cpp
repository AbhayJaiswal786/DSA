#include<bits/stdc++.h>
using namespace std;

int main(){
    string name = "Abhay";
    int name_len = name.length();
    int N = 20;

    cout<<endl<<endl;

    //For first half
    for(int i = 0; i<N/2-1; i++){
        for(int j = 0; j<N/2-i; j++){
            cout<<"*"<<" ";
        }
        for(int k = 0; k<2*i; k++){
            cout<<"  ";
        }

        for(int j = N/2-i; j>0; j--){
            cout<<"*"<<" ";
        }
        cout<<endl;
    }

    // for second half
    for(int i = N/2-1; i>=0; i--){
        
        //for name line
        if(i == N/2-1){
            for(int j = N/2-i; j>0; j--){
            cout<<"*"<<" ";
            }
            //space before name
            if(name_len%2 == 0){
                for(int k = 0; k<((2*i)-name_len)/2+1; k++){
                    cout<<"  ";
                }
            }
            else{
                for(int k = 0; k<((2*i)-name_len)/2+1; k++){
                    cout<<"  ";
                }
            }

            // Name
            for(int k = 0; k<name_len; k++){
                cout<<name[k]<<" ";
            }

            //space after name
            if(name_len%2 == 0){
                for(int k = 0; k<((2*i)-name_len)/2+1; k++){
                    cout<<"  ";
                }
            }
            else{
                for(int k = 0; k<((2*i)-name_len)/2; k++){
                    cout<<"  ";
                }
            }
            
            for(int j = 0; j<N/2-i; j++){
                cout<<"*"<<" ";
            }
        }
        
        // other lines than name
        else{
            for(int j = N/2-i; j>0; j--){
            cout<<"*"<<" ";
            }
            for(int k = 0; k<2*i; k++){
                cout<<"  ";
            }
            for(int j = 0; j<N/2-i; j++){
                cout<<"*"<<" ";
            }
        }
        cout<<endl;
    }

    cout<<endl<<endl;
}