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

void find_missing_values(){
    // Find missing value in given sorted array
    
}



void find_missing_values_with_binary_src(){

}

void find_no_of_occurences_with_binary_src(){

}

// given with three sorted arrays and find commom elements among them 

void number_of_subsets(int arr[],int n,int sum){
    // Arr[5]={7,12,14,19,13}; given array 
    // Find subsets whose sum is sum(here sum is 19)
    
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
            sum=vec[start].first+vec[end].first;
            if(sum==target){
                output.push_back(vec[start].second);
                output.push_back(vec[end].second);
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

vector<pair<int,int>> frequency_of_element(int arr[],int n){
    sort(arr,arr+n);
    vector<pair<int,int>> vec;
    int count;
    for(int i=1;i<=n;i++){
        count=1;
        while(i<n and arr[i]==arr[i-1]){
            count++;
            i++;
        }
        vec[i-1].first=arr[i-1];
        vec[i-1].second=count;
    }
    return vec;
}

void maximum_element(){

}

void elements_occur_more_than_one(){
    
}

int main(){
    int arr[]={1,9,3,2,3,1,4,5,7};
    int n=sizeof(arr)/sizeof(arr[0]);

    // int arr1[5]={-1,2,3,-2,5};
    // int arr2[5]={1,5,2,5,2};
    // int Arr[5]={7,12,14,19,13};
    // int ord_arr[10]={1,2,3,4,5,6,8,9,10};

    // linear_search(arr,n,1);
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

    // Two_Sum Problem
    // vector<int> nums={1,2,3,4,5};
    // int target_sum=5;
    // vector<int> Index_Output=twoSum(nums,target_sum);
    // cout<<"Output is :"<<endl;
    // for(int i=0;i<Index_Output.size();i++){
    //     cout<<Index_Output[i]<<" ";
    // }

    //First_Palindromic_String_In_Array
    // vector<string> string_={"abc","car","ada","racecar","cool"};
    // string first_palindromic_string=first_palindromic_string_in_array(string_);
    // cout<<first_palindromic_string;

    //frequency_of_element
    vector<pair<int,int>> output=frequency_of_element(arr,n);
    print_vector_pair(output);



}


