#include<iostream>
using namespace std;

void sum(int arr[3][3]){
    int sum=0;
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            sum+=*(arr[i]+j);
        }
    }
    cout<<"sum:"<<sum<<endl;
}

void row_sum(int arr[3][3]){
    for(int i=0;i<3;i++){
        int sum=0;
        for(int j=0;j<3;j++){
            sum+=*(arr[i]+j);
        }
        cout<<"row "<<i<<" sum:"<<sum<<endl;
    }

}

void col_sum(int arr[3][3]){
    for(int i=0;i<3;i++){
        int sum=0;
        for(int j=0;j<3;j++){
            sum+=*(arr[j]+i);
        }
        cout<<"col "<<i<<" sum:"<<sum<<endl;
    }   

}

void transpose(int arr[3][3]){
    
}

int main(){
    int arr[3][3]={{2,4,7},{5,7,8},{4,5,6}};


    // sum(arr);
    // row_sum(arr);
    // col_sum(arr);
    // transpose(arr);

    

}

