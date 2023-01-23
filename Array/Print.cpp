#include<bits/stdc++.h>
using namespace std;

void print_array(int arr[],int n){
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
}

void print_vector(vector<int> vec){
    for(int i=0;i<vec.size();i++){
        cout<<vec[i]<<" ";
    }
}

void print_vector_pair(vector<pair<int,int>> vec){
    for(int i=0;i<vec.size();i++){
        cout<<vec[i].first<<" "<<vec[i].second<<endl;
    }
}

void print_2D_vector(vector<vector<int>> vec){
    for(int i=0;i<vec.size();i++){
        cout<<"{ ";
        for(int j=0;j<vec[i].size();j++){
            cout<<vec[i][j]<<" ";        
        }
        cout<<"}"<<" ";
    }  
}