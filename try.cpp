#include<bits/stdc++.h>
using namespace std;

bool test(int n, int arr[], int k){
    for(int i =0; i<n; i++){
        int len = 0;
        int sum = 0;
        for(int j = i; j<n ; j++){
            sum+=arr[j];
            len++;
            // std::cout<<sum<<" "<<len<<endl;
            if(sum % k == 0 && len>=2) return true;
        }
    }
    return false;
}

int main(){
    int n;
    cin>>n;

    int k;
    cin>>k;

    int arr[n];
    //input array
    for(int i = 0; i<n; i++){
        cin>>arr[i];
    }

    bool ans = test(n,arr,k);
    return ans;
}