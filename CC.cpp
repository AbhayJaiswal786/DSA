#include <bits/stdc++.h>
using namespace std;

int main(){
//Driving Fare 

    // string DN;
    // string DL;
    // string Taxi_num;
    // float km;

    // cout<<endl<<"Enter your Name: ";
    // cin>>DN;

    // cout<<endl<<"Enter your DL: ";
    // cin>>DL;

    // cout<<endl<<"Enter taxi number: ";
    // cin>>Taxi_num;

    // cout<<endl<<"Enter KM driven: ";
    // cin>>km;

    // float fair = 0;

    // if(km>=1 && km<=10) fair = 5000 + 15*km;

    // else if(km>=11 && km<=50) fair = 5000 + 14*(km-10) + 15*10;

    // else if(km>=51 && km<=100) fair = 5000 + 12*(km-50) + 14*40 + 15*10;

    // else if(km>=101 && km<=1000) fair = 5000 + 11*(km-100) + 12*50 + 14*40 + 15*10;

    // else if(km>1000) fair = 5000 + 10*(km-1000) + 11*900 + 12*50 + 14*40 + 15*10;

    // float total_fair = fair + (0.18*fair);
    // total_fair += (0.12*total_fair);

    // cout<<endl<<"Driver Name: "<<DN<<endl;
    // cout<<"Driving License: "<<DL<<endl;
    // cout<<"Taxi Number: "<<Taxi_num<<endl;
    // cout<<"Total KM driven: "<<km<<endl;
    // cout<<fixed<<setprecision(20)<<"Total fair: "<<total_fair;


    // 	Case 1 : 
    // i. Km = 3 ;  fare = 6667.47216796875
    // ii. Km  = 7 ;    fare = 6746.76806640625
    // iii. Km = 0 ;  fare = 0;

    // Case 2: 
    // i. Km = 12 ;  fare = 6843.24462890625
    // ii. Km  = 37 ;    fare = 7305.804687500
    // iii. Km = 43 ;  fare = 7416.81933593750 

    // Case 3:
    // i. Km = 54 ;  fare = 7609.77294921875
    // ii. Km  = 87 ;    fare = 8133.12646484375
    // iii. Km = 100 ;  fare = 8339.29589843750;

    // Case 4:
    // i. Km = 193 ;  fare = 9691.29296875
    // ii. Km  = 397 ;    fare = 6746.76806640625
    // iii. Km = 899 ;  fare = 0;


// //Merge Array

    // int len1, len2;
    // cout<<"Enter elements in first array: ";
    // cin>>len1;

    // cout<<"Enter elements in second array: ";
    // cin>>len2;

    // int *arr1 = new int(len1);
    // int *arr2 = new int(len2);

    // for(int i=0; i<len1; i++){
    //     cout<<i<<" value in array: ";
    //     cin>>arr1[i];
    // }

    // for(int i=0; i<len2; i++){
    //     cout<<i<<" value in array: ";
    //     cin>>arr2[i];
    // }

    // int merge_arr[len1+len2];

    // for(int i = 0; i<len1; i++){
    //     merge_arr[i] = arr1[i];
    // }

    // for(int i = 0; i<len2; i++){
    //     merge_arr[len1+i] = arr2[i];
    // }

    // cout<<"Merge Array:"<<endl;
    // for(int i = 0; i<len1+len2; i++){
    //     cout<<merge_arr[i]<<endl;
    // }


// //Theatre Ticket Booking

    // string arr[8][15] ;

    // for(int i = 0; i<8; i++){
    //     for(int j = 0; j<15; j++){
    //         if((i+j)%2 == 0) arr[i][j] = "Booked";
    //         else arr[i][j] = "Vaccant";
    //     }
    // }

    // for(int i = 0; i<8; i++){
    //     for(int j = 0; j<15; j++){
    //         cout<<arr[i][j]<<"  ";
    //     }cout<<endl;
    // }

// // Matrix 

    int mat[4][4] = {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16};

    //right diagonal
    for(int i = 0; i<4; i++){
        for(int j = 0; j<4; j++){
            if(i==j) cout<<mat[i][j]<<"  ";
        }cout<<endl;
    }



}
