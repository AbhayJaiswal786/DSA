#include<bits/stdc++.h>
using namespace std;

void str_len(string s){
    //length of string
    int i=0;
    while(s[i]!='\0'){
        i++;
    }
    cout<<i<<endl;

}

void str_concatinate(string s1,string s2){
    //concatination

    string conc_str="";
    int j=0,z=0;
    while(s1[j]!='\0'){
        conc_str+=s1[j];
        j++;
    }

    while(s2[z]!='\0'){
        conc_str+=s2[z];
        z++;

    }
    cout<<conc_str<<endl;

}

void reverse(string s){
    int i=0;
    while(s[i]!='\0'){
        i++;
    }
    int start=0;
    int end=i-1;
    while(start<end){
        swap(s[start],s[end]);
        start++;
        end--;
    }

    cout<<s<<endl;
}


int main(){

    string s="Abhay";
    string s1="jaiswal";

    str_len(s);
    str_concatinate(s,s1);
    reverse(s1);


    }

