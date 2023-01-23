#include <bits/stdc++.h>
#include "C:\\Users\\asus1\\OneDrive\\Attachments\\__Programming\\Winning Camp\\DSA\\Array\\Print.cpp"

using namespace std;

void next_smallest_element_on_left(int arr[], int n){
    vector<int> LS(n,-1); //intializing vector with -1 to store left_next_smallest_element
    
    stack<int> st;
    
    for(int i=0; i<n; i++){
        if(st.size()>0){

            if(arr[i]>st.top()){
                LS[i]=st.top();
                st.push(arr[i]);
            }
        
            else if(st.top()>=arr[i]){
                st.pop();
                i--; 
            }
            
        }
        
        else st.push(arr[i]);
    }

    cout<<"\nLeft_next_smallest_element: "<<endl;
    print_vector(LS);

}

void next_smallest_element_on_right(int arr[], int n){
    vector<int> RS(n,-1); //intializing vector with -1 to store right_next_smallest_element
    
    stack<int> st;
    
    for(int i=n-1; i>=0; i--){
        if(st.size()>0){

            if(arr[i]>st.top()){
                RS[i]=st.top();
                st.push(arr[i]);
            }
        
            else if(st.top()>=arr[i]){
                st.pop();
                i++; 
            }
            
        }
        
        else st.push(arr[i]);
    }
    
    cout<<"\nRight_next_smallest_element: "<<endl;
    print_vector(RS);

}

void next_greater_element_on_left(int arr[], int n){
    vector<int> ans(n,-1);
    
    stack<int> st;
    
    for(int i=0; i<n; i++){
        if(st.size()>0){
            if(st.top()>arr[i]){
                ans[i]=st.top();
                st.push(arr[i]);
            }
            
            else if(st.top()<=arr[i]){
                st.pop();
                i--;
            }
        }
        
        else{
            st.push(arr[i]);
        }
    }

    cout<<"\nnext_greater_element_on_left: "<<endl;
    print_vector(ans);

}


void next_greater_element_on_right(int arr[], int n){
    vector<int> ans(n,-1);
    
    stack<int> st;
    
    for(int i=n-1; i>=0; i--){
        if(st.size()>0){
            if(st.top()>arr[i]){
                ans[i]=st.top();
                st.push(arr[i]);
            }
            
            else if(st.top()<=arr[i]){
                st.pop();
                i++;
            }
        }
        
        else{
            st.push(arr[i]);
        }
    }

    cout<<"\nnext_greater_element_on_right: "<<endl;
    print_vector(ans);

}


int celebrity_problem(vector<vector<int> >& M, int n){
    stack<int>st;

    //pushing all the members(rows) in stack
    for(int row=0; row<n; row++){
        st.push(row);
    }
    
    //eleminating rows/members which can not be celebrity, at the end only one row/member will be left to check further it is celebrity or not 

    while(st.size()>1){
        int top_row=st.top();   //top row in stack 
        st.pop();
        int next_top_row=st.top();  //next top row in stack 
        st.pop();
        
        if(M[top_row][next_top_row]==1){  //checking if "top_row" know(1) the "next_top_row" , then "top_row" can not be celebrity b/c celebrity dont know anyone in party and we push only "next_top_row" and eleminate "top_row"

            st.push(next_top_row);
        }
        
        else if(M[top_row][next_top_row]==0){  //checking if "next_top_row" not known(0) by "top_row" , then "next_top_row" can not be celebrity b/c celebrity known by everyone in party and we push only "top_row" and eleminate "next_top_row"

            st.push(top_row);
        }
    }
    
    //here we will left with only one row/ member , now we check it is celebrity or not 

    int celebrity=st.top();
    
    for(int i=0; i<n ; i++){
        if(M[celebrity][i]==1){  //checking if celebrity know(1) any row then there is no celebrity
            celebrity=-1;
            break;
        }
        
        else if(i!=celebrity and M[i][celebrity]==0){ //checking if any row don't know(0) any celebrity, then there no celebrity 
            celebrity=-1;
            break;
        }
    }

    return celebrity;

}

void reverse_Sentence(string str){
    int len=str.length();

    stack<string> st;
    string temp="";
    for(int i=0; i<len; i++){
        if(str[i]!=' '){
            temp+=str[i];
            if(i==len-1) st.push(temp);
            
        }

        else if(str[i]==' ' && str[i+1]!=' '){
            st.push(temp);
            // st.push(" ");
            temp="";
        }

    }

    cout<<"reversed sentence: "<<endl;
    while(st.size()){
        cout<<st.top()<<" ";
        st.pop();
    }
}

int prefix_expression_evaluation(string expression){
    int len=expression.length();

    int operand1, operand2;

    stack<int> st;

    //for prefix expression evaluation we have to go from right to left of expression
    for(int i=len-1; i>=0; i--){

        if(expression[i]>='0' && expression[i]<='9' ){
            st.push(expression[i]-'0');  //char integer to integer           
        }

        else{
            operand1=st.top();
            st.pop();
            operand2=st.top();
            st.pop();

            switch(expression[i]){
                case '^': st.push(pow(operand1,operand2)); break;
                
                case '/': st.push(operand1/operand2); break;

                case '*': st.push(operand1*operand2); break;

                case '+': st.push(operand1+operand2); break;

                case '-': st.push(operand1-operand2); break;
                
            }
        } 
    }

    return st.top();
}


int postfix_expression_evaluation(string expression){
    int len=expression.length();

    int operand1, operand2;

    stack<int> st;

    //for postfix expression evaluation we have to go from left to right of expression
    for(int i=0; i<len; i++){

        if(expression[i]>='0' && expression[i]<='9' ){
            st.push(expression[i]-'0');  //char integer to integer           
        }

        else{
            operand2=st.top();
            st.pop();
            operand1=st.top();
            st.pop();

            switch(expression[i]){
                case '^': st.push(pow(operand1,operand2)); break;
                
                case '/': st.push(operand1/operand2); break;

                case '*': st.push(operand1*operand2); break;

                case '+': st.push(operand1+operand2); break;

                case '-': st.push(operand1-operand2); break;
                
            }
        } 
    }

    return st.top();
}


//precedence of opeartor
int prec(char operator_){
    if(operator_=='^') return 3;

    else if(operator_=='*' || operator_=='/') return 2;

    else if(operator_=='+' || operator_=='-') return 1;

    else return -1;

}

//Infix to Postifix

string Infix_to_Postfix(string Infix_exp){
    int len=Infix_exp.length();

    string Postfix_exp="";

    stack<char> st;

    for(int i=0; i<len; i++){

        // If operand in Infix_exp[i] then add to Postifix_exp
        if((Infix_exp[i]>='0' && Infix_exp[i]<='9') || (Infix_exp[i]>='A' && Infix_exp[i]<='Z') || (Infix_exp[i]>='a' && Infix_exp[i]<='z')) {
            Postfix_exp+=Infix_exp[i];
        }

        // If ( in Infix_exp[i] then push to stack
        else if(Infix_exp[i]=='(') {
            st.push(Infix_exp[i]);
        }

        // If ) in Infix_exp[i] then pop from stack and add to Postifix_exp untill we get st.top=='('
        else if(Infix_exp[i]==')'){
            while(st.size() && st.top()!='('){
                Postfix_exp+=st.top();
                st.pop();
            }
            st.pop();
        }

        // If operator in Infix_exp[i] has less or equal precedence than opearator at st.top(), then pop st and add to Postfix_exp
        else{
            while(st.size() && prec(st.top()) >= prec(Infix_exp[i]) ){
                Postfix_exp+=st.top();
                st.pop();
            }
            st.push(Infix_exp[i]); // push operator of Infix_exp[i] in stack
        }
    }

    // At the end pop and add all operands/operators from stack to postfix_expression until stack get empty.
    while(st.size()){
        Postfix_exp+=st.top();
        st.pop();
    }

    return Postfix_exp; 
}

string Infix_to_Prefix(string Infix_exp){
    int len=Infix_exp.length();

    string Prefix_exp="";

    stack<char> st;

    //start from end side of Infix Expression
    for(int i=len-1; i>=0; i--){

        // If operand in Infix_exp[i] then add to Preifix_exp
        if((Infix_exp[i]>='0' && Infix_exp[i]<='9') || (Infix_exp[i]>='A' && Infix_exp[i]<='Z') || (Infix_exp[i]>='a' && Infix_exp[i]<='z')) {
            Prefix_exp+=Infix_exp[i];
        }

        // If ( in Infix_exp[i] then push to stack
        else if(Infix_exp[i]=='(') {
            st.push(Infix_exp[i]);
        }

        // If ) in Infix_exp[i] then pop from stack and add to Prefix_exp untill we get st.top=='('
        else if(Infix_exp[i]==')'){
            while(st.size() && st.top()!='('){
                Prefix_exp+=st.top();
                st.pop();
            }
            st.pop();
        }

        // If operator in Infix_exp[i] has less precedence than opearator at st.top(), then pop st and add to Prefix_exp
        else{
            while(st.size() && prec(st.top()) > prec(Infix_exp[i]) ){
                Prefix_exp+=st.top();
                st.pop();
            }
            st.push(Infix_exp[i]); // push operator of Infix_exp[i] in stack
        }
    }

    // At the end pop and add all operands/operators from stack to postfix_expression until stack get empty.
    while(st.size()){
        Prefix_exp+=st.top();
        st.pop();
    }

    //Reverse to get Prefix Expression
    reverse(Prefix_exp.begin(), Prefix_exp.end());

    return Prefix_exp;
}

string Prefix_to_Infix(string Prefix_exp){
    reverse(Prefix_exp.begin(),Prefix_exp.end());

    
}

int main()
{
    // int A[]={2, 4, 8, 7, 7, 9, 3};
    // int n = sizeof(A)/sizeof(A[0]);

    // next_smallest_element_on_left(A,n);

    // next_smallest_element_on_right(A,n);

    // next_greater_element_on_left(A,n);
    
    // next_greater_element_on_right(A,n);

//celebrity problem

    // vector<vector<int>> M = {{0,0,0},{0,0,0},{0,0,0}}; 
    // int n=M.size();
    // cout<<"Celebrity : "<<celebrity_problem(M,n);

//reverse sentence by removing extra white spaces
    
    // string str="    I   am             Abhay!   ";
    // reverse_Sentence(str);

//Prefix Expression Evaluation
    string prefix_expression="+-*42/43*56";  
    cout<<"Prefix_Evaluation: " << prefix_expression_evaluation(prefix_expression) << endl;

//Postfix Expression Evaluation
    string postfix_expression="42*43/-56*+";  
    cout<<"Postfix_Evaluation: " << postfix_expression_evaluation(postfix_expression) << endl;

//Infix Expression to Postifix Expression Conversion
    string infix_expression="4*2-4/3+5*6";
    cout<<"Postfix Expression of "<<infix_expression<<" : "<<Infix_to_Postfix(infix_expression)<<endl;

//Infix Expression to Preifix Expression Conversion
    cout<<"Prefix Expression of "<<infix_expression<<" : "<<Infix_to_Prefix(infix_expression)<<endl;

    return 0;
}
