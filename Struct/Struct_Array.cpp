#include<bits/stdc++.h>
using namespace std;

struct Array{
    int arr[100];
    int i=0;

    void push_back(int val){
        arr[i]=val;
        i++;
    }    

    void pop_back(){
        i--;
    }

    int val(int index){
        return arr[index];
    }

    int size_(){
        return i;
    }

    void print(){
        for(int j=0;j<3;j++){
            cout<<arr[j]<<" ";
        }
    }
};

int main(){
    struct Array arr;
    arr.push_back(10);
    arr.push_back(20);
    arr.push_back(30);

    int val=arr.val(0);
    cout<<val<<endl;

    arr.print();


}