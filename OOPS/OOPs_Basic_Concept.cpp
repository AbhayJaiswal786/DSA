#include<bits/stdc++.h>
using namespace std;

class Hero{
    public:
    int health;
    char level;
    char *name = new char[100];
    
    Hero(int health, char level, char name[]){
        this->health = health;
        this->level = level;
        this->name  = name;
    }
    // string s;
    // char ch1;
    // int i2;
    // char ch2,ch3;
};

int main(){
    char name[5] = "Abhi";
    Hero *h1 = new Hero(10,'A',name);

    Hero h2(*h1);

    cout<<"h1->health : "<<h1->health<<" , ";
    cout<<"h1->level : "<<h1->level<<endl;

    cout<<"h2->health : "<<h2.health<<" , ";
    cout<<"h2->level : "<<h2.level<<endl;

    h1->health = 11;

    cout<<"h1->health : "<<h1->health<<" , ";
    cout<<"h1->level : "<<h1->level<<endl;

    cout<<"h2->health : "<<h2.health<<" , ";
    cout<<"h2->level : "<<h2.level<<endl;
    
    
}