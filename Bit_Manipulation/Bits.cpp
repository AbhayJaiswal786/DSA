#include<bits/stdc++.h>
#include "C:\\Users\\asus1\\OneDrive\\Attachments\\__Programming\\Winning Camp\\DSA\\_Shortcut.cpp"
using namespace std;


//Problem on XOR
// Find that single number which is repeating once in array , other elements repeating exactly twice 
    // TC : O(n) 
    // there is an optimal approach also which is taking only O(logn)
int find_Non_Repeating_Num(vector<int> arr){
    int ans = 0;

    for(int i=0; i<arr.size(); i++){
        ans = ans^arr[i];  // here, we are using logic : n^n = 0 ; same numbers on applying xor gives zero, even times repeating numbers will cut each other
    } 

    return ans;
}

// Swap two numbers without using any third variable
void Swap_Two_Num_without_third_variable(int &var1, int &var2){

    cout<<"before swapping "<<var1<<" "<<var2<<endl;
    var1 = var1 ^ var2;
    var2 = var1 ^ var2; // var2 = (var1 ^ var2) ^ var2 
    var1 = var1 ^ var2; // var1 = (var1 ^ var2) ^ var1 ;
    cout<<"after swapping "<<var1<<" "<<var2<<endl;
}

// Given N, print the xor of  1 to N ;  1^2^3^…^N
    // TC : O(1)
    // There is pattern to solve this question ... after every four consecutive number , same pattern repeating
int xor_of_number_between_1_to_N(int N){
    int xor_;
    if(N%4 == 1) xor_ = 1;
    else if(N%4 == 2) xor_ = N+1;
    else if(N%4 == 3) xor_ = 0;
    else if(N%4 == 0) xor_ = N;

    return xor_;
}

int Missing_Number(vector<int> nums){
    int N = *max_element(nums.begin(), nums.end());

    int xor_N = xor_of_number_between_1_to_N(N);

    for(int i=0; i<nums.size(); i++){
        xor_N^=nums[i];  //we will remove elements that are present in nums vector from xor_N using xor operator to get at last one missing number 
    }

    return xor_N;
}

void bits_representation(int n, string &binary){
    while(n){
        binary += to_string(n&1);
        n = (n>>1);
    }
    reverse(binary.begin(), binary.end());
}


bool power_of_2(int N){
    if((N&(N-1)) == 0) return true; //main condition to be power of 2
    else return false;

}


bool power_of_4(int N){
    int zeroes = 0; 
    int N_copy = N;

    while(N_copy){
        if((N_copy&1) == 0) zeroes++;  //counting number of zero bit in N 
        N_copy = (N_copy>>1);
    }

    if((N&(N-1)) == 0 && zeroes%2 == 0) return true; //main condition to be power of 4
    else return false;
}






vector<vector<int>> subsets_using_bits(vector<int> nums){
    int len = nums.size();
    vector<vector<int>> powerset;

    for(int i=0; i<pow(2,len); i++){ // this loop is for numbers 0 to 2^n -1
        vector<int> subset;
        int n = i;
        for(int j = 0; j<len; j++ ){ // this loop is for iterating bit of numbers
            if(n&1) subset.push_back(nums[len-j-1]);  // condition to check set bit
            n = n>>1; //shifting next bit 
        }
        powerset.push_back(subset);
    }
    return powerset;   
}


int main(){

// Note: 
    // decimal_num >> i == int(decimal_num / pow(2,i))  ; right-shift operator 
    cout<<((10>>3) == int(10/pow(2,3)))<<endl;

    // decimal_num << i == decimal_num * pow(2,i)  ; left-shift operator 
    cout<<((10<<4) == 10*pow(2,4))<<endl;

    // decimal_num & 1 == decimal_num % 2;
    cout<<((11&1) == 11%2)<<endl;



//Problems on XOR(^)

// 1.Find that single number which is repeating odd times in array , other elements repeating exactly even times

    // vector<int> arr = {2,1,2,3,1,3,4,5,6,5,6};
    // cout<<"Single number repeating with odd times : "<<find_Non_Repeating_Num(arr)<<endl;

// 2. Swap two numbers without using any third variable
    
    // int var1 = 6;
    // int var2 = 5;
    // Swap_Two_Num_without_third_variable(var1,var2);
    // cout<<endl;

    
// 3. Given N, print the total xor of  1 to N ;  1^2^3^…^N
    // TC : O(1)
    // Brute force approach : TC : O(N)

    // int N = 10;
    // cout << "xor of all number between 1 to " << N << " is " << xor_of_number_between_1_to_N(N) << endl;
    
// 4. Given range (L,R), print the total xor of number between L to R
    // TC : O(1)
    // Logic : (1^2^3^4^5^6^7^8^9^10) ^ (1^2) = (3^4^5^6^7^8^9^10) 

    // int L = 3;
    // int R = 10;

    // cout << "xor of all number between " << L << " to " << R << " is " << (xor_of_number_between_1_to_N(R) ^  xor_of_number_between_1_to_N(L-1))  << endl;
    
// 5. A Missing Number in range (1,N)
    // TC : O(N)

    // vector<int> nums = {8,6,5,2,7,9,3,1,0};
    // cout<<"Missing number in given range : "<< Missing_Number(nums)<<endl;



//Problem Based on and(&) operator

// Power of 2
    int N = 16;
    // power_of_2(N)? cout<<N<<" is power of 2"<<endl : cout<<N<<" is not power of 2"<<endl;

// Power of 4
    // power_of_4(N)? cout<<N<<" is power of 4"<<endl : cout<<N<<" is not power of 4"<<endl;

// Check if the ith bit is set
    


// Subset using bits 

    // vector<int> nums = {1,2};
    // cout<<"Subsets are: "<<endl;
    // print_2D_vector(subsets_using_bits(nums));

}