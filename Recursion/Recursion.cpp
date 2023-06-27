#include<bits/stdc++.h>
#include "C:\Users\asus1\OneDrive\Attachments\__Programming\Winning Camp\DSA\_Shortcut.cpp"

using namespace std;

void reverse(vector<int> &arr, int l, int r){
    //base case
    if(l>=r) return ;

    swap(arr[l], arr[r]);
    reverse(arr, l+1, r-1);
}

void rev_arr_2(vector<int> arr, int i, int n){
    //base case
    if(i>n/2) return ;

    swap(arr[i], arr[n-i-1]);
    rev_arr_2(arr,i+1,n);
}



int pow(int base, int power){
    //base case
    if(power==0)return 1;

    //recursive relation    
    return base*pow(base,power-1);
}


//optimized way to find power(a^b)
//a^b=(a^b/2)*(a^b/2) ; if b is even 
// a^b=a*(a^b/2)*(a^b/2) ; if b is odd
int pow_alternative(int base, int power){
    //base case
    if(power==0)return 1;

    //recusrive call
    int ans=pow_alternative(base,power/2);

    if(power%2==0){
        return ans*ans;
    }
    else{
        return base*ans*ans;
    }
}

int sum_n_natural_number(int n){
    //base case
    if(n==0)return 0;

    //recursive relation
    return n+sum_n_natural_number(n-1);
}

void print_upto_n_inc_order(int n){
    //base case
    if(n==0)return ;

    //head recursion
    print_upto_n_inc_order(n-1);
    cout<<n<<" ";
}

void print_upto_n_dec_order(int n){
    //base case

    if(n==0) return ;

    cout<<n<<" ";
    
    //recursive relation
    print_upto_n_dec_order(n-1);
}

int fibonacci(int n){
    if(n==0){
        return 0;
    }
    if(n==1){
        return 1;
    }
    return fibonacci(n-1)+fibonacci(n-2);
}

long double factorial(long double n){
    if(n==1) return 1;

    return n*factorial(n-1);
}


void say_digits(int n, string digits_to_words[]){
    // base case
    if(n==0)return ;

    //recursive call
    say_digits(n/10,digits_to_words);
    
    //Proccessing
    int digit=n%10;
    cout<<digits_to_words[digit]<<" ";

}

bool arraySortedOrNot(int arr[], int n) {
    //base case
    if(n==0||n==1)return true;
    
    //process
    if(arr[0]>arr[1])return false;
    
    //recursive relation
    return arraySortedOrNot(arr+1,n-1);  //arr+1 give an start with arr[1]
}

int sum_of_array(int arr[],int n){
    if((n-1)==0)return arr[0];
    return arr[n-1]+sum_of_array(arr,n-1);
}

int sum_of_array_2(int arr[],int n){
    if(n==0){
        return 0;
    }
    if(n==1){
        return arr[0];
    }
    
    int sum=arr[0] + sum_of_array_2(arr+1,n-1);

    return sum;
}


bool linear_search_rec(int arr[],int n,int key){
    //base case 
    //element not found
    if(n==0){    //searching till n become 0 that means searching till there is no element left
        return false;
    }
    //element found
    if(arr[0]==key){
        return true;
    }
    //recursive relation
    return linear_search_rec(arr+1,n-1,key);
}
 
// int linear_search_rec_(int arr[],int n,int key){
//     //base case
//     //element not found 
//     if(n==0){
//         return -1;
//     }
//     //element found
//     if(arr[n-1]==key){ 
//         return n-1;
//     }

//     //recursive relation
//     else{
//         return linear_search_rec(arr,n--,key);
//     }
// }


// int binary_search_rec(int arr[],int high,int low,int key){
//     //base case 
//     //element not found
//     if(low>high){
//         return -1; //if element not found return -1
//     }
//     //element found
//     int mid=low+(high-low)/2;
//     if(arr[mid]==key){
//         return mid;
//     }

//     //recursive relation
//     if(key<arr[mid]){
//         binary_search_rec(arr,mid-1,low,key);
//     }
//     else{
//         binary_search_rec(arr,high,mid+1,key);
//     }
// }


//using two pointer
void reverse_str(string &str,int low,int high){ // we are passing string as reference whatever changes happen it will directly change in original string 
    if(low>high)return;
    else{
        swap(str[low],str[high]);

        reverse_str(str,low+1,high-1);
    }
}

// using single pointer
void reverse_str_(string &str,int i,int high){ // we are passing string as reference whatever changes happen it will directly change in original string 
    if(i>high/2) return;
    else{
        swap(str[i],str[high-i]);

        reverse_str(str,i+1,high);
    }
}

string checkPalindrome(string str,int i,int high){
    if(i>=high) return "Palindrome";

    if(str[i]==str[high]){
        return checkPalindrome(str,i+1,high-1);
    }

    else{
        return "Not Palindrome";
    }
}

void binaryRepresentation(int N,string &binary){
    if(N==0) return ;
    else{
        binary+=to_string(N%2);
        N=N/2;
        binaryRepresentation(N,binary);
    }
}

// Check If Binary Representation of a Number is Palindrome

void Checking_Binary_Representation_of_N_is_Palindrome(int N){
    string binary="";

    binaryRepresentation(N,binary); //actually the binary representation we are getting here is reverse of true binary representation. So, we are storing it in reverse_binary 

    string reverse_binary=binary;
    
    reverse(binary.begin(),binary.end()); //reversing the binary string to get true binary representaion
        
    string result=(binary==reverse_binary)?"Palindrome!":"Not Palindrome!";

    cout<<"Binary Representation of "<<N<<" is "<<result;
}


void bubble_sort_using_rec(int *array,int n){
    if(n==0 || n==1) return ;

    for(int i=1;i<n;i++){
        if(array[i-1]>array[i]){
            swap(array[i-1],array[i]);
        }
    }
    return bubble_sort_using_rec(array,n-1);
}

//Subsets

void subsets(vector<int> arr, vector<int> subset, vector<vector<int>> &power_set, int index){
    // base case
    if(index>=arr.size()){
        power_set.push_back(subset);
        return ;
    }

    //exclude
    subsets(arr,subset,power_set,index+1);

    //include
    subset.push_back(arr[index]);
    subsets(arr,subset,power_set,index+1);

}

//All Subsets without duplicate subsets 

void all_subsets_without_duplicate_subsets(vector<int> arr, vector<int> subset, vector<vector<int>> &power_set, int index){
    // base case
    if(index>=arr.size()){
        if((find(power_set.begin(), power_set.end(), subset))==power_set.end()){
                power_set.push_back(subset);
        }
        return ;
    }

    //exclude
    all_subsets_without_duplicate_subsets(arr,subset,power_set,index+1);

    //include
    subset.push_back(arr[index]);
    all_subsets_without_duplicate_subsets(arr,subset,power_set,index+1);

}


//Number of subsets whose sum is sum.
void number_of_subsets_equals_sum(vector<int> arr,int sum,vector<int> subset,int index,int &count){
    if(index>=arr.size()){
        if(subset.size()>0 && ((*max_element(subset.begin(), subset.end()) +
            *min_element(subset.begin(), subset.end()) )) <=sum ){ 
                count++;
        }
        return ;
    }

    //exclude
    number_of_subsets_equals_sum(arr,sum,subset,index+1,count);

    //include
    subset.push_back(arr[index]);
    number_of_subsets_equals_sum(arr,sum,subset,index+1,count);    
}


//Number of pair whose sum is sum.
void number_of_pair_equals_sum(vector<int> arr,int sum,vector<int> subset,vector<vector<int>> &pair_set_equals_sum,int index,int &count){
    if(index>=arr.size()){
        if(accumulate(subset.begin(),subset.end(),0)==sum && subset.size()==2){ //checking the sum of elements of subset having size 2(pair subset) equals to sum or not 
            count++;
            pair_set_equals_sum.push_back(subset);
        }
        return ;
    }

    //exclude
    number_of_pair_equals_sum(arr,sum,subset, pair_set_equals_sum,index+1,count);

    //include
    subset.push_back(arr[index]);
    number_of_pair_equals_sum(arr,sum,subset, pair_set_equals_sum,index+1,count);    

}


void subsequnces(string str, string subsequnce, vector<string> &Subsequences, int index){
    //base case
    if(index>=str.length()){
        if(subsequnce.length()>0){ // we are using this condition to not insert blank string "" as subsequence
            Subsequences.push_back(subsequnce);
        }
        return ;
    }

    //exclude
    subsequnces(str,subsequnce,Subsequences,index+1);

    //include
    subsequnce+=str[index];
    subsequnces(str,subsequnce,Subsequences,index+1);

}


void Phone_Keypad_Problem(string digits,vector<string> &combinations, string mapping[],string output, int index){
    //base case
    if(index>=digits.length()){
        combinations.push_back(output);
        return ;
    }
    int digit=digits[index]-'0'; // substracting '1' from '0' will give int value of 1

    string value=mapping[digit]; //value is digit mapped string 

    for(int i=0;i<value.length();i++){
        output.push_back(value[i]);
        Phone_Keypad_Problem(digits, combinations, mapping, output, index+1);
        output.pop_back();  // 
    }

}


void Permutation(string str, vector<string>&permutations,int index){
    if(index>=str.length()){
        permutations.push_back(str);
        return ;
    }

    for(int i=index;i<str.length();i++){
        swap(str[index],str[i]);
        Permutation(str,permutations,index+1);

        swap(str[i],str[index]);//backtrack to original str by reverse swapping
    }
}



int main(){
    // cout<<pow(2,10)<<endl;

    // cout<<pow_alternative(2,10)<<endl;

    // cout<<sum_n_natural_number(4)<<endl;
    
    // print_upto_n_inc_order(5);
    // cout<<endl;
    
    // print_upto_n_dec_order(5);
    // cout<<endl;

    // cout<<fibonacci(6);
    // cout<<endl;

    cout<<factorial(100)<<endl;

// Say Digits Problem
    // int num=412;
    // string digits_in_words[10]={"Zero","One","Two","Three","Four","Five","Six","Seven","Eight","Nine"};
    // say_digits(num,digits_in_words);
    // cout<<endl;

//isSortedOrNot
    // int arr[]={1,3,5,7,9};
    // int len=sizeof(arr)/sizeof(arr[0]);
    // cout<<arraySortedOrNot(arr,len)<<endl;

//sum_of_elements_of_array -- adding element from end of array
    // cout<<"Sum of array : "<<sum_of_array(arr,len)<<endl;

//sum_of_elements_of_array_2 -- adding element from starting of array
    // cout<<"Sum of array : "<<sum_of_array_2(arr,len)<<endl;

//linear search using recursion 

    // cout<<linear_search_rec(arr,len,9)<<endl;

    // cout<<"Key found at index: "<<linear_search_rec_(arr,len,1)<<endl; 

//binary search using recursion

    // cout<<"Key found at index: "<<binary_search_rec(arr,len-1,0,9)<<endl;

//reverse string
    // string str="abhay";
    // int len_str=str.length();
    // reverse_str(str,0,len_str-1);
    // cout<<"Reverse of string: "<<str<<endl;

    //using single pointer

    // string str_="abhay";
    // int len_str_=str_.length();
    // reverse_str_(str_,0,len_str_-1);
    // cout<<"Reverse of string: "<<str_<<endl;
    
//checking palindrome 
    // string str="ada",original_str,result;

    // original_str=str; 

    // int len_str=str.length();

    // reverse_str(str,0,len_str-1);

    // result=(str==original_str)?"Palindrome!":"Not Palindrome!";

    // cout<<result<<endl;

    // cout<<checkPalindrome(str,0,len_str-1);


//Check If Binary Representation of a Number is Palindrome
    // int N=15;
    // Checking_Binary_Representation_of_N_is_Palindrome(N);
    

//Bubble Sort
    // int arr[]={9,7,50,10,1,2,0},n;
    // n=sizeof(arr)/sizeof(arr[0]);

    // bubble_sort_using_rec(arr,n);
    // print_array(arr,n);


//Subsets 
// Power Set is set of all subsets ; number of elements in it 2^n including blank array (n is number of elements in array)

//It is for array with unique elements , and if array with unique elements then it will give unique subsets

// If we'll give array with duplicate elements then it will give duplicate subsets too

    // vector<int> arr={1,2,3,-2,5},subset;
    // vector<vector<int>>power_set;

    // subsets(arr,subset,power_set,0);

    // cout<<"\nSubsets are:"<<endl;
    // print_2D_vector(power_set);
    // cout<<endl;


//Number of subsets whose sum is sum.
    // vector<int> Arr={3,5,6,7},subset;
    // int sum=9; 
    // int count=0,index=0;
    // number_of_subsets_equals_sum(Arr,sum,subset,index,count);
    // cout<<"Number of Subsets that equals to "<<sum<<" are "<<count;
    
//Number of pair whose sum is sum.
    // vector<int> Arr={1,1,1,1},subset;
    // int sum=2; 

    // vector<vector<int>>pair_set_equals_sum;
    // int count=0,index=0;

    // number_of_pair_equals_sum(Arr,sum,subset,pair_set_equals_sum,index,count);

    // cout<<"Number of Pairs that equals to "<<sum<<" are "<<count<<endl;
    // cout<<"Pairs are:"<<endl;
    // print_2D_vector(pair_set_equals_sum);
    

//All Subsets without duplicate subsets ;
//It is for array with duplicate elements and want unique subset
// Note: (1,2,2) or (2,2,1) or (2,1,2) ; all are duplicate subset of (1,2,2)

    // vector<int> arr={1,2,3,-2,5},subset;
    // vector<vector<int>>power_set;

    // //wrong output , it is still giving duplicate subsets
    // all_subsets_without_duplicate_subsets(arr,subset,power_set,0);

    // cout<<"\nSubsets are:"<<endl;
    // print_2D_vector(power_set);
    // cout<<endl;
    

//Subsequences 
// if size of string is n then Number of subsequences are 2^n - 1 excluding blank string ("")
    
    // string str="abcd",subsequnce="";
    // vector<string> Subsequences;

    // subsequnces(str,subsequnce,Subsequences,0);

    // cout<<"\nSubsequences are:"<<endl;

    // cout<<"[ ";
    // for(int j=0;j<Subsequences.size();j++){
    //     cout<<"\""<<Subsequences[j]<<"\""<<" ";        
    // }
    // cout<<"]"<<endl;



//Phone Keypad Problem -- Letter Combinations of Phone Number 

    // string digits="236";
    // vector<string> combinations;
    // string mapping[10]={"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
    // string output="";
    // int index=0;

    // Phone_Keypad_Problem(digits,combinations,mapping,output,index);

    // cout<<"Combinations are: "<<endl;
    // for(int i=0;i<combinations.size();i++){
    //     cout<<"\""<<combinations[i]<<"\""<<" ";
    // }
    // cout<<endl;

    
//Permutations of string 
// If number of characters in string is n then Number of Permutations will be n!

//    string str="abcde";
//    vector<string>permutations;

//    Permutation(str,permutations,0);

//    cout<<"Permutations are:"<<endl;
//    cout<<"[ ";
//    for(int j=0;j<permutations.size();j++){
//         cout<<"\""<<permutations[j]<<"\""<<"  ";        
//    }
//    cout<<"]"<<endl;



}