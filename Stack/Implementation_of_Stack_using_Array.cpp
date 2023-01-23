#include<iostream>
using namespace std;

class Stack{

    public:
    int *array; //array for implementation
    int size;  //variable for array size
    int top_index;   //top_index variable 


    //constructor

    Stack(int size){ //we will get size when stack will be created
        this -> size = size;  //storing that user input size as size of array
        array = new int[size];  //giving array a size
        top_index=-1;  
    }

    //push function
    void push(int element){
        if(top_index==size-1){
            cout<<"Stack overflow!"<<endl;
        }

        else{
            top_index++;
            array[top_index]=element;
        }
    }

    //pop function
    void pop(){
        if(top_index>=0){
            top_index--;
        }

        else{
            cout<<"Stack underflow!"<<endl;
        }
    }

    //top function
    int top(){
        if(top_index>=0){
            return array[top_index];
        }

        else{
            cout<<"Stack underflow!"<<endl;
            return -1;
        }
    }

    //empty function
    bool empty(){
        if(top_index==-1){
            return true;
        }

        else{
            return false;
        }
    }

};

int main(){

    Stack st(3);

    st.push(1);
    st.push(2);
    st.push(3);
    st.push(4);

    cout<<"top: "<<st.top()<<endl;

    cout<<"pop! "<<endl;
    st.pop();

    cout<<"top: "<<st.top()<<endl;

    cout<<"pop! "<<endl;
    st.pop();

    cout<<"top: "<<st.top()<<endl;

    cout<<"pop! "<<endl;
    st.pop();

    cout<<"top: "<<st.top()<<endl;

    if(st.empty()) cout<<"Stack is empty!"<<endl;
    else cout<<"Stack is not empty!"<<endl;

    st.push(4);
    
    cout<<"top: "<<st.top()<<endl;

    if(st.empty()) cout<<"Stack is empty!"<<endl;
    else cout<<"Stack is not empty!"<<endl;



}