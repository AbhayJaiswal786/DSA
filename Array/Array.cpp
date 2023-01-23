#include<bits/stdc++.h>
#include "C:\\Users\\asus1\\OneDrive\\Attachments\\__Programming\\Winning Camp\\DSA\\Array\\Print.cpp"
using namespace std;

void linear_search(int arr[],int n,int k){
    for(int i=0;i<n;i++){
        if(arr[i]==k){
            cout<<"key match at index: "<<i;
        }
    }
}

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
        if(i+1<n){  //checking for alternative element is in n range for swapping.
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


void array_concatenate(vector<int> arr){
    int n=arr.size();
    for(int i=0;i<n;i++){
        arr.push_back(arr[i]);
    }
    print_vector(arr);
}


void seperate_neg_pos(int *arr, int n){
    for(int i=0;i<n;i++){
        for(int j=1;j<n-i;j++){
            if(arr[j-1]>arr[j]){
                swap(arr[j-1],arr[j]);
            }
        }
    }
    print_array(arr,n);
}

//O(nlogn)
void kth_smallest_element(int *arr,int k,int len){
    sort(arr,arr+len);

    cout<<"\n"<<k<<"th smallest element is: "<<arr[k-1];

}

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

// given with three sorted arrays and find commom elements among them 

int isCommon(int *stu_list, int strength, int key){
    
    int low=0, high=strength-1, result=0;
    
    while(low<=high){

        int mid = low+(high-low)/2;

        if(stu_list[mid]==key){
            result = 1;
            break;
        }
        
        else if(stu_list[mid]<key){
            low=mid+1;
        }

        else{
            high=mid-1;
        }
    }

    return result;
}

// can be solved also by using 3 ptrs

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


int main(){
    // int arr[]={1,1,1,1};
    // int k=2;
    // int n=sizeof(arr)/sizeof(arr[0]);
    // int max_element_=*(max_element(arr,arr+n));
    // vector<int> hashtable(max_element_+1,0);
    
    // for(int i=0;i<n;i++){
    //     hashtable[arr[i]]++;
    // }

    // print_vector(hashtable);

    // int count=0;
    // for(int j=0;j<n;j++){
    //     if(k-arr[j]>0 && hashtable[k-arr[j]]>0){
    //         count++;
    //     }
    // }
    
    // cout<<"\n"<<count;

    // int sorted_arr[]={1,3,5,7,9,10,15};
    // int len_sorted_arr=sizeof(sorted_arr)/sizeof(sorted_arr[0]);
    

    // int arr1[5]={-1,2,3,-2,5};
    // int len=sizeof(arr1)/sizeof(arr1[1]);
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
    // seperate_neg_pos(arr1,len);
    // kth_smallest_element(arr,4,n);
    

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
    // int array[]={1,5,7,1};
    // int target_sum=6;
    // int n=sizeof(array)/sizeof(array[0]);
    // two_sum_alternative(array,target_sum,n);

    // vector<int> vec={1,2,3,4};
    // array_concatenate(vec);

// given with three sorted arrays and find commom elements among them 

    // int DBMS[] = {1911,1913,1929,1939,1987,2682,7328};
    // int JAVA[] = {1913,1939,1987,2682};
    // int DSA[] = {1911,1913,1929,1939,1987,2682,7328};
    
    // int strength_DBMS = sizeof(DBMS)/sizeof(DBMS[0]);
    // int strength_JAVA = sizeof(JAVA)/sizeof(JAVA[0]);
    // int strength_DSA = sizeof(DSA)/sizeof(DSA[0]);
    
    // for(int i=0 ; i<strength_DBMS ; i++){
    //     if(isCommon(JAVA,strength_JAVA,DBMS[i]) && isCommon(DSA,strength_DSA,DBMS[i])){
    //         cout<<DBMS[i]<<" ";
    //     }
    // }

//Remove Duplicates From Sorted Array
    // vector<int> nums={7,7,8,8,8,9,9,10,10,10,11};
    // //Naive Approach
    // print_vector(removeDuplicates_Naive_App(nums));
    // //Two Pointer Approach
    // vector<int> num={7,7,8,8,8,9,9,10,10,10,11};
    // print_vector(removeDuplicates_Two_Pointer_App(num));

}