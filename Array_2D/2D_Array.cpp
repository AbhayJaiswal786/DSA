#include<bits/stdc++.h>
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

// void prefix_sum_2D(int arr[4][4]){
//     int prefix_sum[4][4];
//     for(int i=0;i<4;i++){
//         int sum=0;
//         for(int j=0;j<4;j++){
//             sum=
//         }    
// }

//search in a 2D Array I array having numbers in increasing order and sorted manner
bool search_2D_Array_I(vector<vector<int>>& matrix, int target){
    int row=matrix.size();
    int col=matrix[0].size();

    int low=0;
    int high=row*col-1;

    int mid;

    while(low<=high){
        mid=low+(high-low)/2;

        int mid_element=matrix[mid/col][mid%col]; 

        if(mid_element==target){
            return true;
        }

        else if(mid_element>target){
            high=mid-1;
        }

        else{
            low=mid+1;
        }
    }
    return false;
}

//search in a 2D Array II;
// This array has the following properties:

// Integers in each row are sorted in ascending from left to right.
// Integers in each column are sorted in ascending from top to bottom.

bool search_2D_Array_II(vector<vector<int>>& matrix, int target) {
    int row=matrix.size();
    int col=matrix[0].size();

    int row_index=0;
    int col_index=col-1;


    while(row_index < row && col_index >= 0){

        int element=matrix[row_index][col_index];

        if(element==target){
            return true;
        }

        else if(element>target){
            col_index--;
        }

        else{
            row_index++;
        }
    }       
    return false;
}

int main(){
    int arr[3][3]={{2,4,7},{5,7,8},{4,5,6}};


    // sum(arr);
    // row_sum(arr);
    // col_sum(arr);
    // transpose(arr);

//search in 2D array I

    vector<vector<int>> arrayI=
    {{1,3,5,7},
    {10,11,16,20},
    {23,30,34,60}};

    int targetI=6;
    
    string resultI=search_2D_Array_I(arrayI,targetI)?"Element Found!": "Element Not Found!";
    cout<<resultI<<endl;


//search in 2D array II

    vector<vector<int>> arrayII=
    {{1,4,7,11,15},
    {2,5,8,12,19},
    {3,6,9,16,22},
    {10,13,14,17,24},
    {18,21,23,26,30}};

    int targetII=5;
    
    string resultII=search_2D_Array_II(arrayII,targetII)?"Element Found!": "Element Not Found!";
    cout<<resultII<<endl;




    

}

