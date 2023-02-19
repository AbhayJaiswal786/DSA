#include <bits/stdc++.h>
using namespace std;

int main(){
    string DN;
    string DL;
    string Taxi_num;
    float km;

    // cout<<endl<<"Enter your Name: ";
    // cin>>DN;

    // cout<<endl<<"Enter your DL: ";
    // cin>>DL;

    // cout<<endl<<"Enter taxi number: ";
    // cin>>Taxi_num;

    cout<<endl<<"Enter KM driven: ";
    cin>>km;

    float fair = 0;

    if(km>=1 && km<=10) fair = 5000 + 15*km;

    else if(km>=11 && km<=50) fair = 5000 + 14*(km-10) + 15*10;

    else if(km>=51 && km<=100) fair = 5000 + 12*(km-50) + 14*40 + 15*10;

    else if(km>=101 && km<=1000) fair = 5000 + 11*(km-100) + 12*50 + 14*40 + 15*10;

    else if(km>1000) fair = 5000 + 10*(km-1000) + 11*900 + 12*50 + 14*40 + 15*10;

    float total_fair = fair + (0.18*fair);
    total_fair += (0.12*total_fair);

    // cout<<endl<<"Driver Name: "<<DN<<endl;
    // cout<<"Driving License: "<<DL<<endl;
    // cout<<"Taxi Number: "<<Taxi_num<<endl;
    // cout<<"Total KM driven: "<<km<<endl;
    cout<<fixed<<setprecision(20)<<"Total fair: "<<total_fair;


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


    int N = 10;
    string name = "Abhay";
    int len = name.length();

    for(int i = 0; i<N; i++){
        for(int j = 0; j<N ; j++){

        }

        

        for(int )
        
    }
}
