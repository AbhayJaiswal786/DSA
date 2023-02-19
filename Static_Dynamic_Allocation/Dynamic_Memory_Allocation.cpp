#include<bits/stdc++.h>
using namespace std;

int main(){

    int n;
    cin>>n;
    int arr[n]; // creating array at runtime … it will create in stack … and input size can be greater than size allocated to stack memory … that can crash our program … that's why we have allocate memory dynamically.
        
// Allocating Memory Dynamically:
	char *ch = new char;  // new keyword create character of 1 byte memory dynamically in heap but 8 byte memory will be taken in stack for "ch" pointer that will point address of char that present in heap.
	
	int *i = new int;  // new keyword create integer of 4 byte memory dynamically in heap but 8 byte memory will be taken in stack for "i" pointer that will point address of integer  that present in heap.
	
	cin >> n;
	int *arr = new int[n]; // new keyword create int array of (nx4) byte memory dynamically in heap but 8 byte memory will be taken in stack for "arr" pointer that will point address of arr[n]  that present in heap.
	

    // creating 2D_Array dynamically
    int row, col;
    cout<<"row: ";
    cin>>row;

    cout<<"\ncol: ";
    cin>>col;

    int **arr_2D = new int*[row]; //rows 

    for(int i=0; i<row; i++){ //assiging column to rows
        arr_2D[i] = new int[col];
    }

    //2D array creation done

    //taking input

    for(int i=0; i<row; i++){
        for(int j=0; j<col; j++){
            cin>>arr_2D[i][j];
        }
    }

    //printing 
    cout<<endl;
    for(int i=0; i<row; i++){
        for(int j=0; j<col; j++){
            cout<<arr_2D[i][j]<<" ";
        }cout<<endl;
    }


    // Note: 
		// ○ In static , memory release automatically .
		// ○ But in heap, we have to release memory manually, by using "delete" keyword
		// Example:
			delete ch; // for deletion of single element
			delete i; // for deletion of single element
			delete []arr; // for deletion of array
            
            // For deletion in 2D Array:
            for(int i=0; i<row; i++){ //deleting column memory first
                delete []arr_2D[i];
            }
            delete []arr_2D; //deleting row memory 



    
}