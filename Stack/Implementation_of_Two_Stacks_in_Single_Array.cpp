#include<iostream>
using namespace std;

class TwoStack{
    public:

    int *array;
    int size;
    int top_index_1;
    int top_index_2;


    TwoStack(int size){
        this->size=size;
        array=new int[size];

        top_index_1=-1;
        top_index_2=size;

    }

    void push1(int element){
        if(top_index_1==top_index_2-1){
            cout<<"Stack Overflow!"<<endl;
        }

        else{
            top_index_1++;
            array[top_index_1]=element;
        }
    }

    void push2(int element){
        if(top_index_1==top_index_2-1){
            cout<<"Stack Overflow!"<<endl;
        }

        else{
            top_index_2--;
            array[top_index_2]=element;
        }
    }

    void pop1(){
        if(top_index_1==-1){
            cout<<"Stack Underflow!"<<endl;
        }

        else{
            top_index_1--;
        }
    }

    void pop2(){
        if(top_index_2==size){
            cout<<"Stack Underflow!"<<endl;
        }

        else{
            top_index_2++;
        }
    }

    int top1(){
        if(top_index_1==-1){
            cout<<"Stack Underflow!"<<endl;
            return -1;
        }

        else{
            return array[top_index_1];
        }
        
    }

    int top2(){
        if(top_index_2==size){
            cout<<"Stack Underflow!"<<endl;
            return -1;
        }

        else{
            return array[top_index_2];
        }
        
    }

};


int main(){

    TwoStack st(3);

    st.push1(1);
    st.push2(2);

    cout<<"top: "<<endl;
    cout<<"top1: "<<st.top1()<<endl;
    cout<<"top2: "<<st.top2()<<endl;

    cout<<"pop: "<<endl;
    cout<<"pop1 "<<endl;
    st.pop1();
    cout<<"pop2 "<<endl;
    st.pop2();

    cout<<"top: "<<endl;
    cout<<"top1: "<<st.top1()<<endl;
    cout<<"top2: "<<st.top2()<<endl;





    

}