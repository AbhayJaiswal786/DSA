#include <bits/stdc++.h>

using namespace std;

int main()
{
    int num=5;
    int num2=10;
    int num3=15;

    int *q=&num;  //storing address to pointer

    cout<<"&num :"<<&num<<endl; //address of num will be returned
    cout<<"&num2 :"<<&num2<<endl; // address of num + four byte 
    cout<<"&num3 :"<<&num3<<endl; // address of num + four byte + four byte 
    
    cout<<endl;
    
    cout<<"num :"<<num<<endl; 
    cout<<"num2 :"<<num2<<endl; 
    cout<<"num3 :"<<num3<<endl; 

    cout<<endl;
    
    cout<<"q :"<<q<<endl;  //address of num will be returned 
    cout<<"q+1 :"<<q+1<<endl; // address of num + four byte will  be returned  (note: four byte for int ) 
    cout<<"q+2 :"<<q+2<<endl; // address of num + four byte + four byte 
    
    cout<<endl;
    
    cout<<"*q :"<<*q<<endl; //it will point to value store at num
    cout<<"*(q+1) :"<<*(q+1)<<endl; //address of num2 and address of q+1 is same, So it will point to value store at address of num2
    cout<<"*(q+2) :"<<*(q+2)<<endl; //address of num3 and address of q+2 is same, So it will point to value store at address of num3

    cout<<endl;
      
    // the same way compiler do in array , it stores elements in contageous manner 
    
    int arr[3]={10,20,30};
    
    cout<<"arr :"<<arr<<endl;   //address of 0th element
    cout<<"&arr[0] :"<<&arr[0]<<endl; //address of 0th element 
    
    cout<<endl;
    
    cout<<"*(arr) :"<<*(arr)<<endl;  //point to value at this address that is 0th element
    cout<<"arr[0] :"<<arr[0]<<endl;  //value at 0th element
    
    cout<<endl;
    
    cout<<"arr+1 :"<<arr+1<<endl;   //address of 1th element ||  we can say address of 0th element + 4 byte ; because "int of 1" is equal to 4 byte
    cout<<"&arr[1] :"<<&arr[1]<<endl;  //address of 1th element ||  we can say address of 0th element + 4 byte 
    
    cout<<endl;
    
    cout<<"*(arr+1) :"<<*(arr+1)<<endl;  //point to value at this address that is 1th element || point to value at address of (0th element + 4 byte) ; because "int of 1" is equal to 4 byte 
    cout<<"arr[1] :"<<arr[1]<<endl;      //value at 1th element 
    
    cout<<endl;
    
    cout<<"arr+2 :"<<arr+2<<endl;   //address of 2th element ||  we can say address of 0th element + 4 byte + 4 byte ; because "int of 2" is equal to 4+4 byte
    cout<<"&arr[2] :"<<&arr[2]<<endl;  //address of 2th element
    
    cout<<endl;
    
    cout<<"*(arr+2) :"<<*(arr+2)<<endl;  //point to value at this address that is 2th element || point to value at address of (0th element + 4 byte + 4 byte) ; because "int of 2" is equal to 4+4 byte
    cout<<"arr[2] :"<<arr[2]<<endl;      //value at 2th element
    
    
    // Note: means we can derive that address of arr+i and &arr[i] will be equal ;  value for *(arr+i) and arr[i] will be equal.
    
    
    cout<<endl;
    
    cout<<"0[arr] :"<<0[arr]<<endl; // it is same as arr[0]  || compiler read it as *(0+arr)
    cout<<"1[arr] :"<<1[arr]<<endl; // it is same as arr[1]  || compiler read it as *(1+arr)
    
    // Note: we can also write arr[i] as i[arr] ; value for *(i+arr) , i[arr] , arr[i] will be equal.
    
    return 0; 
}

