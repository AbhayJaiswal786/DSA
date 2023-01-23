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

void sort_str(string s){
    int n=0;
    while(s[n]!='\0'){
        n++;
    }

    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            if(s[i]<s[j]){
                swap(s[j],s[i]);
            }
        }
    }
    cout<<"sorted: "<<s<<endl;
}

void char_arr_sort(char *str_arr, int n){
    char *temp;
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            if(strcmp((str_arr+i),(str_arr+j))>0){
                strcpy((str_arr+i),temp);
                strcpy((str_arr+j),(str_arr+i));
                strcpy(temp,(str_arr+j));
            }
        }
    }
    cout<<"Char_Array after sort:";
    for(int i=0;i<n;i++){
        cout<<str_arr[i];
    }    
}

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

    //getting sub_string
    for(int j=0;j<len_str;j++){
        int hash_sub_str=0;
        sub_str=str.substr(j,len_key);  
        len_sub_str=sub_str.length();

        //hash value of sub_string
        for(int i=0;i<len_sub_str;i++){
            hash_sub_str=hash_sub_str + (sub_str[i]*pow(prime_no,len_sub_str-(i+1)));
        }  
    }
}

void palindromic_string(string str){
    int len_str=str.size();
    int start=0;
    int end=len_str-1;

    string temp=str;

    //reverse the str first
    while(start<end){
        swap(temp[start],temp[end]);
        start++;
        end--;

    }
    // compare rev string with original str
    if(temp==str){
        cout<<str<<" is palindromic!"<<endl;
    }
    else {
        cout<<"It is not palindromic"<<endl;
    }
}

 //maximum repeated character in string with n^2 complexity
void max_repeated_character(string str){
    int max_count=0;
    int count;    
    for(int i=0;i<str.size();i++){
        count=0;        
        for(int j=0;j<str.size();j++){
            if(str[i]==str[j]){
                count++;
            }
        }
        max_count=std::max(max_count,count);
    }
    cout<<"maximum repeated count is: "<<max_count<<endl;
}

//maximum repeated character in string with nlog(n) complexity by sorting string

void max_repeated_character_alternative(string str){
    sort(str.begin(),str.end()); //nlogn 
    int n=str.size();
    
    int max_count=1;
    int count;

    for(int i=1;i<n;i++){
        count=1;
        while(i<n and str[i]==str[i-1]){
            i++;
            count++;
        }
        max_count=std::max(max_count,count);
    }

    cout<<"maximum repeated count is: "<<max_count<<endl;

}

//remove duplicate element or find unique elements
// O(n^2) complexity
void remove_duplicate_character(string str){
    sort(str.begin(),str.end());
    int n=str.size();
    for(int i=1;i<n;i++){  
        while(i<n and str[i]==str[i-1]){
            str.erase(str.begin()+i);  //O(n)
            n--;
        }
    }
    cout<<"String after with unique elements: "<<str<<endl;
}


//remove duplicate element or find unique elements
// O(nlogn) complexity
void remove_duplicate_character_alternative(string str){
    sort(str.begin(),str.end());
    int n=str.size();
    string unique_str;
    unique_str.push_back(str[0]);

    for(int i=1;i<n;i++){  
        while(i<n and str[i]==str[i-1]){
            i++;
        }
        if(i<n){
            unique_str.push_back(str[i]);
        }

    }
    cout<<"String after with unique elements: "<<unique_str<<endl;
}

int main(){

    // string s="Abhay";
    // string s1="jaiswal";

    // str_len(s);
    // str_concatinate(s,s1);
    // reverse(s1);
    // sort_str(s);

    // char str_arr[10][10]={"Abhay","Jaiswal","Abhisek"};
    // int n = sizeof(str_arr)/sizeof(str_arr[0]);
    // char_arr_sort((char *)str_arr,n);

    // string str="Hey Abhay this side";
    // string key="Abha";
    // rabin_carp_(str,key);

    // palindromic_string("abhay");

    // max_repeated_character("abaaccdeeaee");

    // max_repeated_character_alternative("abaaccdeeaee");

    // remove_duplicate_character("abaaccdeeaee");
    
    // remove_duplicate_character_alternative("abaaccdeeaee");

    //using constructor to reverse string 
    // string rev = string(str.rbegin(), str.rend());   

    }

