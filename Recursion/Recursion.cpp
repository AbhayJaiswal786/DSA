#include<bits/stdc++.h>
using namespace std;

int pow(int base, int power){
    //base case
    if(power==0)return 1;

    //recursive relation    
    return base*pow(base,power-1);
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

//wrong
int fibonacci(int n){
    if(n==0){
        return 0;
    }
    if(n==1){
        return 1;
    }
    return fibonacci(n-1)+fibonacci(n-2);
}

int factorial(int n){
    if(n==1) return 1;

    return n*factorial(n-1);
}

void say_digits(int n,string digits_to_words[]){
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


int binary_search_rec(int arr[],int high,int low,int key){
    //base case 
    //element not found
    if(low>high){
        return -1; //if element not found return -1
    }
    //element found
    int mid=low+(high-low)/2;
    if(arr[mid]==key){
        return mid;
    }

    //recursive relation
    if(key<arr[mid]){
        binary_search_rec(arr,mid-1,low,key);
    }
    else{
        binary_search_rec(arr,high,mid+1,key);
    }
}

void reverse_str(string &str,int low,int high){
    if(low>high)return ;

    swap(str[low],str[high]);

    reverse_str(str,low+1,high-1);
}


int main(){
    cout<<pow(4,3)<<endl;

    cout<<sum_n_natural_number(4)<<endl;
    
    print_upto_n_inc_order(5);
    cout<<endl;
    
    print_upto_n_dec_order(5);
    cout<<endl;

    cout<<fibonacci(6);
    cout<<endl;

    cout<<factorial(4)<<endl;

    // Say Digits Problem
    int num=412;
    string digits_in_words[10]={"Zero","One","Two","Three","Four","Five","Six","Seven","Eight","Nine"};
    say_digits(num,digits_in_words);
    cout<<endl;

    //isSortedOrNot
    int arr[]={1,3,5,7,9};
    int len=sizeof(arr)/sizeof(arr[0]);
    cout<<arraySortedOrNot(arr,len)<<endl;

    //sum_of_elements_of_array -- adding element from end of array
    cout<<"Sum of array : "<<sum_of_array(arr,len)<<endl;

    //sum_of_elements_of_array_2 -- adding element from starting of array
    cout<<"Sum of array : "<<sum_of_array_2(arr,len)<<endl;

    //linear search using recursion 
    cout<<linear_search_rec(arr,len,9)<<endl;

    // cout<<"Key found at index: "<<linear_search_rec_(arr,len,1)<<endl; 

    //binary search using recursion

    cout<<"Key found at index: "<<binary_search_rec(arr,len-1,0,9)<<endl;

    //reverse string
    string str="abcde";
    int len_str=str.length();
    reverse_str(str,0,len_str-1);
    cout<<"Reverse of string: "<<str<<endl;
}