#include<bits/stdc++.h>
using namespace std;

void rabin_carp_(string str,string key){
    int len_str=str.length();
    int len_key=key.length();
    int prime_no=13;
    int hash_key=0;

   // hash value of key
    for(int i=0;i<len_key;i++){
        hash_key=hash_key+(key[i]*pow(prime_no,len_key-(i+1)));
    }

    string sub_str;
    int len_sub_str;
    int flag=0;

    int hash_sub_str;

    //getting sub_string
    for(int j=0;j<len_str;j++){
        hash_sub_str=0;
        sub_str=str.substr(j,len_key);  
        len_sub_str=sub_str.length();

        //hash value of sub_string
        for(int i=0;i<len_sub_str;i++){
            hash_sub_str=hash_sub_str + (sub_str[i]*pow(prime_no,len_sub_str-(i+1)));
        }    

        if(hash_key==hash_sub_str){
            cout<<"Key matched in string!";        
        }
    }


}

int main(){

    string str="Hey Abhay this side";
    string key="Abha";
    rabin_carp_(str,key);


    }

