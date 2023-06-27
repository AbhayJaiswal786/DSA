#include<bits/stdc++.h>
#include "C:\Users\asus1\OneDrive\Attachments\__Programming\Winning Camp\DSA\_Shortcut.cpp"

using namespace std;

//Binary Search Problems

int peakIndexInMountainArray(vector<int>& nums) {
    // solution for this question is to find index of peak element in array
    int low = 0, high = nums.size()-1;
    
    while(low<=high){
        int mid = low + (high-low)/2;
        
        if(nums[mid]<nums[mid+1]){
            low = mid+1;
        }
        else if(nums[mid]>nums[mid+1]){
            high = mid-1;
        }

    }
    return low;
}

//it is similar finding peak in mountain array but it also involve case of peak at end not only in middle
int findPeakElement(vector<int>& nums) {
    int low = 0, high = nums.size()-1;
    
    while(low<=high){
        int mid = low + (high-low)/2;
        
        if(low ==  nums.size()-1) return low;
        
        if(nums[mid]<nums[mid+1]){
            low = mid+1;
        }
        else if(nums[mid]>nums[mid+1]){
            high = mid-1;
        }
    }
    return nums[low];
}

void find_missing_values(){
    // Find missing value in given sorted array
    
}

void find_missing_values_with_binary_src(){

}

void find_no_of_occurences_with_binary_src(){

}

// Find First and Last Position of Element in Sorted Array with binary_src
// it is running in infinite loop

// vector<int> first_last_position_of_element(vector<int>& nums, int target) {
//     int low=0,high=nums.size()-1,mid;
//     vector<int> positions(2,-1);  //initializing vector of size two with all value -1.
//     while(low<=high){
//         cout<<"Outer while loop"<<endl;
//         mid=low+(high-low)/2;
//         int first_position=mid,last_position=mid;
//         if(nums[mid]==target){
//             cout<<nums[mid]<<"target match"<<endl;
//             while(nums[--first_position]==target && first_position>=0){
//                 cout<<"checking for first position"<<endl;
//                 positions[0]=first_position;
//                 // break;
//             }
//             while(nums[++last_position]==target && first_position>=0){
//                 cout<<"checking for last position"<<endl;
//                 positions[1]=last_position;
//                 // break;
//             }
//         }
//         else if(nums[mid]>target){
//             high=mid-1;
//         }
//         else{
//             low=mid+1;
//         }
//     }
//     return positions;
// }

// Find First and Last Position of Element in Sorted Array with binary_src
//code after every corner case is checked and passed

vector<int> first_last_position_of_element(vector<int>& nums, int target) {
    int len=nums.size(),low=0,high=len-1,mid,first_position,last_position;

    vector<int> positions(2,-1);  //initializing vector of size two with all value -1.

    if(len==0){
        return positions;
    }

    if(len==1){
        if(nums[0]==target){
            positions[0]=0;
            positions[1]=0;
            return positions;
        }
        else{
            return positions;
        }
    }

    while(low<=high){
        mid=low+(high-low)/2;

        if(nums[mid]==target){
            first_position=mid;
            last_position=mid;

            positions[0]=first_position;
            positions[1]=last_position;

            break;
        }
        
        else if(nums[mid]>target){
            high=mid-1;
        }
        
        else if(nums[mid]<target){
            low=mid+1;
        }
        
    }
    
    
    while((first_position-1>=0 && first_position-1<len) && nums[first_position-1]==target){
        positions[0]=first_position-1;
        first_position--;
        if(first_position-1<0){
            break;
        }
    }
    
    
    
    while((last_position+1>=0 && last_position+1<len) && nums[last_position+1]==target ){
        positions[1]=last_position+1;
        last_position++;
        if(last_position+1>=len){
            break;
        }
    }

    return positions;
}


//Arranging the coins as stair's steps
// o
// o o 
// o o o 
// o o o o  

//Give the k numbers of stair's step completely formed with given n coins

//naive approach 
int arrangeCoins_naiveApproach(int coins){
    int stairs=0,n=coins;

    if(coins==1 || coins==2) return 1;
    if(coins==3) return 2;

    for(int i=1;i<n/2;i++){  //we are runnning loop till n/2 (n=number of coins) to reduce search space but it create problem for coins=1 and coins=3
        if(i<=coins){
            stairs++;
            coins-=i; //remaining coins after each steps
        }
    }
    return stairs;
}

//Binary Search Approach 
// We use formula here s*(s+1)//2==coins  , here s = number of stairs
int arrangeCoins_Bin_Src_Approach(int coins){
    long low=0,high=coins,mid,value; 

    while(low<=high){
        mid=low+(high-low)/2; //choosing middle element as s to reduce search space

        value=mid*(mid+1)/2; //value of formula 

        if(value==coins){
            return mid;
        }

        else if(value>coins){
            high=mid-1;
        }

        else{
            low=mid+1;
        }
    }
    return high;
}

// Kth Missing Positive Number 

//Naive Approach
vector<int> findKthPositive_NA(vector<int>& arr, int k) {
    int len=arr.size();
    vector<int> missing_numbers;

    for(int i=1;i<=arr[len-1];i++){
        for(int j=0;j<=i;j++){
            if(i!=arr[j]){
                missing_numbers.push_back(i);
            }
        } 
    }
    return missing_numbers;
}

//BS Approach
int findKthPositive_BS(vector<int>& arr, int k) {
    int low=0, high=arr.size()-1, mid, ans;

    while(low<=high){
        int mid=low+(high-low)/2;
        
        if(arr[mid]-(mid+1)<k){
            low=mid+1;
            ans=low+k;
        }

        else{
            high=mid-1;
        }
    }
    return ans;
}


//Search Insert Position
int searchInsert(vector<int>& nums, int target) {
    int low=0;
    int high=nums.size()-1;

    while(low<=high){
        int mid=high-(high-low)/2; 

        if(target==nums[mid]){
            return mid;
        }

        else if(target<nums[mid]){
            high=mid-1;
            
        }

        else{
            low=mid+1;
        }
    }    
    return low;    
}


//Valid Perfect Square
bool isPerfectSquare(int num) {
    if(num==1) return true;
    int low=2,high=num/2;
    while(low<=high){
        long long mid=low+(high-low)/2;
        if(mid*mid==num){
            return true;
        }
        else if(mid*mid>num){
            high=mid-1;
        }
        else{
            low=mid+1;
        }
    }
    return false;
}


// Sqrt(x)
int mySqrt(int num) {
    if(num==0)return 0;
    if(num==1)return 1;
    int low=1,high=num/2,mid,ans;

    while(low<=high){
        mid=low+(high-low)/2;
        if(mid==num/mid){  //mid*mid==num can be written as mid==num/mid to reduce int size 
            return mid;
        }
        else if(mid<num/mid){ //mid*mid<num can be written as mid<num/mid to reduce int size 
            low=mid+1;
            ans=mid; 
        }
        else{
            high=mid-1;
        }
    }   
    return ans;     
}



// Find Smallest Letter Greater Than Target
char nextGreatestLetter(vector<char>& letters, char target) {
    int len=letters.size(),low=0,high=len-1,mid;
    char ans;

    while(low<=high){
        mid=low+(high-low)/2;
        if(!(letters[len-1]>target)){
            ans=letters[0];
        }
        if(letters[mid]>target){
            ans=letters[mid];
            high=mid-1;
        }
        else{
            low=mid+1;
        }
    }  
    return ans;  
}


//Find the Distance Value Between Two Arrays

// Naive Approach
int findTheDistanceValue_NA(vector<int>& arr1, vector<int>& arr2, int d) {

    int count=arr1.size();
    for(int i=0;i<arr1.size();i++){
        for(int j=0;j<arr2.size();j++){
            int dif=abs(arr1[i]-arr2[j]);
            if(dif<=d){
                count-=1;
                break;
            }
        }
    }
    return count;
}

 //Binary Search 
int findTheDistanceValue_BS_A(vector<int>& arr1, vector<int>& arr2, int d){
   
    sort(arr2.begin(),arr2.end());

    int len1=arr1.size(), count=len1;

    for(int i=0;i<len1;i++){

        int low=0, high=arr2.size()-1; // for every new value of arr1 , arr2 start again 

        while(low<=high){
            int mid=low+(high-low)/2;

            int diff=abs(arr1[i]-arr2[mid]);

            if(diff<=d){
                count--;
                break;
            }
            
            else if(arr2[mid]<arr1[i]){
                low=mid+1;  //agar arr2[mid] value chhoti hai arr1[i] se to arr2[mid] se right side ki values ko check krenge 
            }
            
            else{
                high=mid-1;  // vice-versa
            }
        }
    }
    return count;
}


int Pivot_Index_in_Rotated_Sorted_Array(vector<int>& arr) {

    int low=0;int high=arr.size()-1;
    
    while(low<high){
        int mid=low+(high-low)/2;
        
        if(arr[mid]>arr[0]){
            low=mid+1;
        }
        else{
            high=mid;
        }
    }
    return low;
} 

// int BS(vector<int> arr, int low, int high, int target){
//     int mid;
//     while(low<=high){
//         mid=low+(high-low)/2;

//         if(target==arr[mid]){
//             return mid;
//         }

//         else if(arr[mid]>target){
//             high=mid-1;
//         }

//         else{
//             low=mid+1;
//         }
//     }
//     return -1;
// }

//This approach is not passing all test cases but logic is correct

// int Search_in_Rotated_Sorted_Array(vector<int>& nums, int target) {
//     int pivot = Pivot_Index_in_Rotated_Sorted_Array(nums);

//     int len=nums.size();

//     if(target>= nums[pivot] && target<=nums[len-1]) {
//         return BS(nums, pivot, len-1, target);
//     }

//     else{
//         return BS(nums, 0, pivot-1 , target);   
//     }

// }

int Search_in_Rotated_Sorted_Array(vector<int>& nums, int target) {

    int low=0, high=nums.size()-1, mid;
    
    while(low<=high){
        mid = low+(high-low)/2;

        if(nums[mid]==target) return mid;

        else if(nums[mid]>target){
            int idx = mid;
            while(idx<=high){
                if(nums[idx]==target) return idx;
                idx++;
            }
            high=mid-1;
        }

        else{
            int idx = mid;
            while(idx>=0){
                if(nums[idx]==target) return idx;
                idx--;
            }
            low=mid+1;
        }

    }
    return -1;
}


int singleNonDuplicate(vector<int>& nums) {
    int low = 0, high = nums.size()-1;

    while(low<high){

        int mid = low + (high-low)/2;
    
        if(((mid & 1) == 0) && (nums[mid]!=nums[mid+1]) ){
            high = mid;
        }
            
        else if(((mid & 1) != 0  && (nums[mid]!=nums[mid-1]))){
            high = mid;
        }
            
        else{
            low = mid+1;
        }
    }

    return nums[low];
}


int main(){

    //Binary Search Problems

//Peak index in mountain array

    vector<int> mountain_array={2,50,30,5,3,2,1,0};
    cout<<"Peak Index: "<<peakIndexInMountainArray(mountain_array)<<endl;

//Find Peak Element in Array
    vector<int> array={2,50,30,5,3,1};



//Find First and Last Position of Element in Sorted Array with binary_src

    // vector<int> nums={5,7,7,8,8,10};
    // int target=8;
    // cout<<"First and Last Position of "<<target<<" : "<<endl;
    // print_vector(first_last_position_of_element(nums,target)); 


// Arranging the coins as stair's steps
    // int coins=298888090;

    // //Naive Approach
    // cout<<"NA_Number of stairs in "<<coins<<" coins :  "<<arrangeCoins_naiveApproach(coins)<<endl;

    // //Binary Search Approach
   // cout<<"BS_Number of stairs in "<<coins<<" coins :  "<<arrangeCoins_Bin_Src_Approach(coins)<<endl;


//Kth Missing Positive Number
    // vector<int> vec={2,3,4,7,11};
    // print_vector(findKthPositive(vec,5));

//Find the Distance Value Between Two Arrays
    // vector<int> arr1={-3,10,2,8,0,10};
    // vector<int> arr2={-9,-1,-4,-9,-8};
    // int d=9;

    //Naive Approach
    // cout<<"count: "<< findTheDistanceValue_BS_A(arr1, arr2, d)<<endl;

    //BS Approach
    // cout<<"count: "<< findTheDistanceValue_NA(arr1, arr2, d)<<endl;


//Pivot_Index_in_Rotated_Sorted_Array
//     vector<int> array={1,5,3};  // not working for cases such as array={5,1,3} ; {3,1} key=1; 
//     cout<<"Pivot Index: "<<Pivot_Index_in_Rotated_Sorted_Array(array)<<endl;

// // Search_in_Rotated_Sorted_Array
//    int ans = Search_in_Rotated_Sorted_Array(array,1);

//    string result=(ans==-1)?"Key not found!":"Key found!";

//    cout<<result<<endl;


// Single Element in a Sorted Array
    vector<int> vec = {1,1,3,3,5,5,7,8,8};
    cout << "Element that occurring once : " << singleNonDuplicate(vec) << endl;

}