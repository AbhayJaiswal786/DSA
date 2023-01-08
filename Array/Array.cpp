#include<bits/stdc++.h>
using namespace std;

void print_array(int arr[],int n){
    cout<<"\nArray is:"<<endl;
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
}

void print_vector(vector<int> vec){
    cout<<"\nVector is:"<<endl;
    for(int i=0;i<vec.size();i++){
        cout<<vec[i]<<" ";
    }
}

void print_vector_pair(vector<pair<int,int>> vec){
    cout<<"\nVector Pair is:"<<endl;
    for(int i=0;i<vec.size();i++){
        cout<<vec[i].first<<" "<<vec[i].second<<endl;
    }
}

// void print_vector(vector<int> vec,int n){
//     cout<<"\nVector is:"<<endl;
//     for(int i=0;i<n;i++){
//         cout<<vec[i]<<" ";
//     }
// }


void linear_search(int arr[],int n,int k){
    for(int i=0;i<n;i++){
        if(arr[i]==k){
            cout<<"key match at index: "<<i;
        }
    }
}

// int binary_search(int arr[],int key,int len_arr){
//     int low=0,high=len_arr-1;

//     while(low<=high){
//         int mid=low+(high-low)/2;

//         if(arr[mid]==key){
//             return mid;
//         }

//         else if(key<arr[mid]){
//             high=mid-1;
//         }

//         else{
//             low=mid+1;
//         }
//     }
//     return 0;
// }

void binary_search(int arr[],int key,int len_arr){
    int low=0,high=len_arr-1;

    while(low<=high){
        int mid=low+(high-low)/2;

        if(arr[mid]==key){
            cout<<"Key match at index: "<<mid;
            break;
        }

        else if(key<arr[mid]){
            high=mid-1;
        }

        else{
            low=mid+1;
        }
    }
}

void max_value(int arr[], int n){
    int max=INT_MIN; 
    for(int i=0;i<n;i++){
        if(arr[i]>max){
            max=arr[i];
        }
    }
    cout<<"maximum value: "<<max<<endl;
}

void min_value(int arr[],int n){
    int min=INT_MAX;
    for(int i=0;i<n;i++){
        if(arr[i]<min){
            min=arr[i];
        }
    }
    cout<<"minimum value: "<<min<<endl;

}

void reverse(int arr[],int n){
    int start=0; //starting of array
    int end=n-1; //end of array
    while(start<end){
        swap(arr[start],arr[end]); //swapping starting and ending element
        start++;     
        end--;
    }

    cout<<"After Reverse Array is:"<<endl;
    print_array(arr,n);
}


void swap_alternative(int arr[],int n){
    int i=0;
    while(i<n){
        if(i+1<n){  //checking for alternate element for swapping is in n range.
            swap(arr[i],arr[i+1]);
        }
        i+=2; //jump to next to next element.
    }
    cout<<"After Swapping Alternative Elements Array is:"<<endl;
    print_array(arr,n);
}


void odd_even(int *arr,int n){
    int ec=0;
    int oc=0;
    for(int i=0;i<n;i++){
        if(*(arr+i)/2==0){
            ec++;
        }

        if(*(arr+i)/2!=0){
            oc++;
        }

    }
    cout<<"even:"<<ec<<endl;
    cout<<"odd:"<<oc<<endl;
}

void sum(int *arr,int n){
    int sum=0;
    for(int i=0;i<n;i++){
        sum+=*(arr+i);
    }
    cout<<"sum:"<<sum<<endl;
}

// void seperate_neg_pos(int *arr, int n){
//     for(int i=0;i<n;i++){
//         for(int j=i+1;j<n;j++){
            
//         }
        
//     }

// void kth_smallest_element(int *arr,int k){
    
// }

void cyclic_rotation(int *arr, int n){
    int last_element=arr[n-1];
    for(int i=n-1;i>0;i--){
        arr[i]=arr[i-1];
    }

    arr[0]=last_element;

    cout<<"Cyclic Rotated Array:"<<endl;
    for(int i=0;i<n;i++){
        cout<<arr[i];
    }
}

void cyclic_rotation_Anticlock(int *arr, int n){
    int first_element=arr[0];
    for(int i=0;i<n;i++){
        arr[i]=arr[i+1];
    }
    arr[n-1]=first_element;

    cout<<"\nAnticlockWise Cyclic Rotated Array:"<<endl;
    for(int i=0;i<n;i++){
        cout<<arr[i];
    }
}

void kth_cyclic_rotation(int *arr,int n,int k){
    for(int i=0;i<k;i++){
        int last_element=arr[n-1];
        for(int i=n-1;i>0;i--){
            arr[i]=arr[i-1];
        }
        
        arr[0]=last_element;
    }
    cout<<"\nCyclic Rotated Array after "<<k<<"Rotation:"<<endl;
        for(int i=0;i<n;i++){
            cout<<arr[i];
        }

}

// Selection Sort:- Find The minimum element in unsorted array and swap it with element at beginning.

// Algorithm for Selection Sorting.
// 12 45 23 51 19 8  : Given Unsorted array {First Iteration Process: 8 is minimum element and it will swap with first element of unsorted array,.i.e. 12}
// 8 45 23 51 19 12  : 1st Iteration Done (by taking element 8) (after 8 had been sorted; 45 23 51 19 12 were part of unsorted array and 8 was part of sorted array){Second Iteration Process :12 is minimum element and it will swap with first element of remaining unsorted array ,.i.e. 45 }
// 8 12 23 51 19 45  : 2nd Iteration Done (by taking element 12) (after 8 12 had been sorted; 23 51 19 45 were part of unsorted array and 8 12 were part of sorted array) {Third Iteration Process :19 is minimum element and it will swap with first element of remaining unsorted array ,.i.e. 23 }
// 8 12 19 51 23 45  : 3rd Iteration Done (by taking element 19) (after 8 12 19 had been sorted; 51 23 45 were part of unsorted array and 8 12 19 were part of sorted array) {Fourth Iteration Process :23 is minimum element and it will swap with first element of remaining unsorted array ,.i.e. 51 }
// 8 12 19 23 51 45  : 4th Iteration Done (by taking element 23) (after 8 12 19 23 had been sorted; 51 45 were part of unsorted array and 8 12 19 23 were part of sorted array) {Fifth Iteration Process :45 is minimum element and it will swap with first element of remaining unsorted array ,.i.e. 51 }
// 8 12 19 23 45 51  : 5th Iteration Done (by taking element 45)

void Selection_Sort(int arr[], int n){
    for(int i=0;i<n;i++){
        int min_index=i;  //Taking first element as minimum value and its index as minimum index 
        for(int j=i+1;j<n;j++){
            if(arr[j]<arr[min_index]){ //compare it to next element if next element is small then make its index is minimum index.
                min_index=j;
            }
        }
        swap(arr[i],arr[min_index]); //after each iteration ith position element will be swapped with minimum value
    }

    cout<<"After Sorting Array is:"<<endl;
    print_array(arr,n);
}

// Best and Worst Case Complexity O(n^2)
// Space Complexity O(1)
// Selection sort use for small size of array/vector/list.

void Bubble_Sort(int arr[], int n){
    for(int i=0;i<n-1;i++){ //passes will be till n-1 times
        for(int j=0;j<n-i;j++){ //compare each elements to its next element in each pass and in each pass largest element will be placed at end so comparison till n-i in each pass.
            if(arr[j+1]<arr[j]){//if next element is small then swap it to previous element.
                swap(arr[j+1],arr[j]);
            }
        }
    }

    cout<<"After Sorting Array is:"<<endl;
    print_array(arr,n);
}

void Insertion_Sort(int arr[],int n){
    int i,key,j;


}

void Merge_Sort(int arr[],int n){

}

void Quick_Sort(int arr[], int n){

}

//O(nlog(n))
vector<int> twoSum(vector<int> &nums_vector, int target) {
        int len=nums_vector.size();

        vector<pair<int,int>> vec;

        for(int i=0;i<len;i++){
            vec.push_back({nums_vector[i],i});
        }

        sort(vec.begin(),vec.end());

        int start=0,end=len-1;
        vector<int> output;
        int sum=0;

        // window sliding or two pointer approach used here and it is best for telling  
        while(start<end){
            cout<<"Loop"<<endl;
            sum=vec[start].first+vec[end].first;
            if(sum==target){
                output.push_back(vec[start].second);
                output.push_back(vec[end].second);
                break;
            }
            else if(sum>target){
                end--;
            }
            else{
                start++;
            }
        }
        return output;
}
        

string first_palindromic_string_in_array(vector<string> &words){
    int len_w=words.size();
        
        int len_str;
        int start;
        int end;
        string output;
        string temp,reverse;
        for(int i=0;i<len_w;i++){
            len_str=words[i].size();
            start=0;
            end=len_str-1;

            temp=words[i];

            while(start<end){
                swap(words[i][start],words[i][end]);
                start++;
                end--;
            }

            if(words[i]==temp){
                output=temp;
                break;
            }
        }
        return output;
}

// O(nlog(n))
void frequency_of_element(int arr[],int n){
    sort(arr,arr+n); //O(nlogn)
    vector<pair<int,int>> vec;
    int count;
    for(int i=1;i<=n;i++){
        count=1;
        while(i<n and arr[i]==arr[i-1]){
            count++;
            i++;
        }
        vec.push_back({arr[i-1],count});
    }

    // cout<<"\nVector Pair is:"<<endl;
    // for(int i=0;i<vec.size();i++){
    //     cout<<vec[i].first<<" "<<vec[i].second<<endl;
    // }
    print_vector_pair(vec);
}

//by using hashing
// O(n)
void frequency_of_element_alternative(int arr[],int n){
    int max=*(max_element(arr,arr+n)); //maximum element

    int freq_arr[max+1]={};   //freq array of size of maximum element of array to store frequency of element  and this array elements are 0 that is freq_arr[]={0,0,0,0,0,0,0,0,0,0}

    for(int i=0;i<n;i++){
        freq_arr[arr[i]]++;
    }

    //printing
    for(int j=0;j<=max;j++){
        if(freq_arr[j]>0){
            cout<<j<<" : "<< freq_arr[j]<<" times occur"<<endl;
        }
    }
}

//by using hashing
void maximum_number_occuring_element(int arr[],int n){
    int max=*(max_element(arr,arr+n));

    int freq_arr[max+1]={};

    for(int i=0;i<n;i++){
        freq_arr[arr[i]]++;
    }

    //index of maximum value of freq_arr is max_occuring_element
    
    int max_value_freq_arr=INT_MIN;
    int max_occuring_element;
    for(int j=0;j<max+1;j++){
        if(freq_arr[j]>max_value_freq_arr){
            max_value_freq_arr=freq_arr[j];
            max_occuring_element=j;
        }
    }
    cout<<"Maximum Time Occuring Element: "<< max_occuring_element<<endl;

}

//by using hashing
void elements_occur_more_than_one(int arr[],int n){
    int max=*(max_element(arr,arr+n)); //maximum element

    int freq_arr[max+1]={};   //freq array of size of maximum element of array to store frequency of element  and this array elements are 0 that is freq_arr[]={0,0,0,0,0,0,0,0,0,0}

    for(int i=0;i<n;i++){
        freq_arr[arr[i]]++;
    }

    //printing
    cout<<"Elements occur more than one time:"<<endl;
    for(int j=0;j<=max;j++){
        if(freq_arr[j]>1){
            cout<<j<<" ";            
        }
    }
    
}

//by using hashing
void arr2_subset_of_arr1(int arr1[],int arr1_size ,int arr2[],int arr2_size){
    int max_elem_arr1=*(max_element(arr1,arr1+arr1_size));

    int freq_arr[max_elem_arr1+1]={};

    for(int i=0;i<arr1_size;i++){
        freq_arr[arr1[i]]++;
    }
    bool flag;
    for(int j=0;j<arr2_size;j++){
        flag=false;
        if(arr2[j]<max_elem_arr1+1 and freq_arr[arr2[j]]>=1){
            flag=true;
        }
        if(flag==false){
            cout<<"Arr2 is not subset of Arr1"<<endl;
            break;
        }
    }
    if(flag==true){
        cout<<"Arr2 is subset of Arr1"<<endl;
    }

}

// by using hashing
//O(n)
void two_sum_alternative(int arr[],int target,int n){

    int max_elem_arr=*(max_element(arr,arr+n));    

    int freq_arr[max_elem_arr+1]={};

    for(int i=0;i<n;i++){
        freq_arr[arr[i]]++;
    }

    vector<pair<int,int>> vec;
    for(int j=0;j<n;j++){
        if(target-arr[j]>=0 and target-arr[j]<=max_elem_arr){
             if((freq_arr[target-arr[j]])>=1){
                vec.push_back({arr[j], target-arr[j]});
            }
        }
    }
    print_vector_pair(vec);
}

void array_concatenate(vector<int> arr){
    int n=arr.size();
    for(int i=0;i<n;i++){
        arr.push_back(arr[i]);
    }
    print_vector(arr);
}

// given with three sorted arrays and find commom elements among them 

void number_of_subsets(int arr[],int n,int sum){
    // Arr[5]={7,12,14,19,13}; given array 
    // Find subsets whose sum is sum(here sum is 19)
}

//Remove duplicates from sorted array
//Naive Approach
vector<int> removeDuplicates_Naive_App(vector<int> &nums){
    for(int i=0;i<(nums.size()-1);i++){  
        for(int j=i+1;j<(nums.size());j++){
            if(nums.at(i)==nums.at(j)){
                nums.erase(nums.begin()+j);   //remove element and reduce num.size() by moving all elements
                --j;
            } 
            if(nums.at(i)!=nums.at(j)){
                break;
            }
        }
    }
    return nums;
}

//Two Pointer Approach 
vector<int> removeDuplicates_Two_Pointer_App(vector<int> &nums){
    int j;
    for(int i=0;i<nums.size()-1;i++){
        j=i+1;
        if(nums.at(i)==nums.at(j)){
            nums.erase(nums.begin()+j);
            --i;
        }
    }
    return nums;
}


//Binary Search Problems
int peakIndexInMountainArray(vector<int>& arr) {
    // solution for this question is to find index of peak element in array
    int low=0;int high=arr.size()-1;
    
    while(low<high){
        int mid=(high+low)/2;
        if(arr[mid]<arr[mid+1]){
            low=mid+1;
        }
        else{
            high=mid;
        }
    }
    return low;
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
    
    if(first_position-1>=0 && first_position-1<len){
        while(nums[first_position-1]==target){
            positions[0]=first_position-1;
            first_position--;
            if(first_position-1<0){
                break;
            }
        }
    }


    if(last_position+1>=0 && last_position+1<len){
        while(nums[last_position+1]==target ){
            positions[1]=last_position+1;
            last_position++;
            if(last_position+1>=len){
                break;
            }
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
vector<int> findKthPositive(vector<int>& arr, int k) {
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

int main(){
    int arr[]={1,3,2,3,1,4,5,7};
    int n=sizeof(arr)/sizeof(arr[0]);

    int sorted_arr[]={1,3,5,7,9,10,15};
    int len_sorted_arr=sizeof(sorted_arr)/sizeof(sorted_arr[0]);
    

    // int arr1[5]={-1,2,3,-2,5};
    // int arr2[5]={1,5,2,5,2};
    // int Arr[5]={7,12,14,19,13};
    // int ord_arr[10]={1,2,3,4,5,6,8,9,10};

    // linear_search(arr,n,1);
    // binary_search(sorted_arr,5,len_sorted_arr);

    // max_value(arr,n);
    // min_value(arr,n);
    // reverse(arr,n);
    // swap_alternative(arr,n);

    // sum(arr,n);
    // odd_even(arr,n);
    // // seperate_neg_pos(arr1,n);
    // // kth_smallest_element(arr,4);
    

    // cyclic_rotation(arr,n);
    
    // // now arr[5]={8,1,3,5,7} after rotation 

    // cyclic_rotation_Anticlock(arr2,n);

    // kth_cyclic_rotation(arr,n,4);

    // Selection_Sort(arr,n);
    // Bubble_Sort(arr,n);

// Two_Sum Problem with O(nlog(n))
    // vector<int> nums={1,2,3,4,5};
    // int target_sum=7;
    // print_vector(twoSum(nums,target_sum));

//First_Palindromic_String_In_Array
    // vector<string> string_={"abc","car","ada","racecar","cool"};
    // string first_palindromic_string=first_palindromic_string_in_array(string_);
    // cout<<first_palindromic_string;

// frequency_of_element with O(nlog(n)) complexity
    // frequency_of_element(arr,n);

//frequency_of_element alternative approach with O(n) complexity using hashing
    // frequency_of_element_alternative(arr,n);

    // maximum_number_occuring_element(arr,n);

    // elements_occur_more_than_one(arr,n);

    // int arr1[]={2,3,4,1,1,2};
    // int arr2[]={2,1,3,4};
    // int arr1_size=sizeof(arr1)/sizeof(arr1[0]);
    // int arr2_size=sizeof(arr2)/sizeof(arr2[0]);
    // arr2_subset_of_arr1(arr1,arr1_size,arr2,arr2_size);

// Two_Sum Problem with O(n) time complexity
    // int array[]={2,3,4,1,1,2};
    // int target_sum=5;
    // int n=sizeof(array)/sizeof(array[0]);
    // two_sum_alternative(array,target_sum,n);

    // vector<int> vec={1,2,3,4};
    // array_concatenate(vec);

//Remove Duplicates From Sorted Array
    // vector<int> nums={7,7,8,8,8,9,9,10,10,10,11};
    // //Naive Approach
    // print_vector(removeDuplicates_Naive_App(nums));
    // //Two Pointer Approach
    // vector<int> num={7,7,8,8,8,9,9,10,10,10,11};
    // print_vector(removeDuplicates_Two_Pointer_App(num));

//Binary Search Problems

//1.peak index in mountain array

    // vector<int> mountain_array={2,50,30,5,3,2,1,0};
    // cout<<"Peak Index: "<<peakIndexInMountainArray(mountain_array)<<endl;

//2.Find First and Last Position of Element in Sorted Array with binary_src

    vector<int> nums={5,7,7,8,8,10};
    int target=8;
    cout<<"First and Last Position of "<<target<<" : "<<endl;
    print_vector(first_last_position_of_element(nums,target)); 


//3. Arranging the coins as stair's steps
    // int coins=298888090;

// //Naive Approach
    // cout<<"NA_Number of stairs in "<<coins<<" coins :  "<<arrangeCoins_naiveApproach(coins)<<endl;

// //Binary Search Approach
//     cout<<"BS_Number of stairs in "<<coins<<" coins :  "<<arrangeCoins_Bin_Src_Approach(coins)<<endl;

//4.Kth Missing Positive Number
    // vector<int> vec={2,3,4,7,11};
    // print_vector(findKthPositive(vec,5));

}

