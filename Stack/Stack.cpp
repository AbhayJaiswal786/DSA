#include <bits/stdc++.h>
#include "C:\\Users\\asus1\\OneDrive\\Attachments\\__Programming\\Winning Camp\\DSA\\_Shortcut.cpp"

using namespace std;

void reverse_Sentence(string str)
{
    int len = str.length();

    stack<string> st;
    string temp = "";
    for (int i = 0; i < len; i++)
    {
        if (str[i] != ' ')
        {
            temp += str[i];
            if (i == len - 1)
                st.push(temp);
        }

        else if (str[i] == ' ' && str[i + 1] != ' ')
        {
            st.push(temp);
            // st.push(" ");
            temp = "";
        }
    }

    cout << "reversed sentence: " << endl;
    while (st.size())
    {
        cout << st.top() << " ";
        st.pop();
    }
}

// Check Redundancy (present of useless brackets in expression)

int checkRedundancy(string expression)
{
    stack<char> st;

    for (int i = 0; i < expression.length(); i++)
    {
        char ch = expression[i];
        if (ch == '(' || ch == '/' || ch == '*' || ch == '+' || ch == '-')
        {
            st.push(ch);
        }

        else
        {
            if (ch == ')')
            {
                int isRedundant = 1;
                while (st.top() != '(' && (st.top() == '/' || st.top() == '*' || st.top() == '+' || st.top() == '-'))
                {
                    isRedundant = 0;
                    st.pop();
                }

                if (isRedundant == 1)
                    return 1;
            }
        }
    }
    return 0;
}


// Minimum cost to make string valid || to make brackets balanced
int minCostToMakeStringValid(string str)
{ //()(())))))

    // odd condition
    if (str.length() % 2 == 1)
        return -1;

    stack<char> st;
    for (int i = 0; i < str.length(); i++)
    {
        if (st.size() && str[i] == ')' && st.top() == '(')
        {
            st.pop();
        }
        else
        {
            st.push(str[i]);
        }
    }

    // now stack contains only invalid brackets/expression

    int open = 0, close = 0; // open and close brackets counting

    while (st.size())
    {
        if (st.top() == '(')
        {
            open++;
        }
        else if (st.top() == ')')
        {
            close++;
        }
        st.pop();
    }

    //**Important formula (created by observing it ): cost or steps to make invalid brackets to valid brackets
    int cost = (open + 1) / 2 + (close + 1) / 2;

    return cost;
}


void reverseVowels(string &s)
{
    int len = s.length();
    stack<char> st;

    // storing all the vowels in stack
    for (int i = 0; i < len; i++)
    {
        if (s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u' || s[i] == 'A' || s[i] == 'E' || s[i] == 'I' || s[i] == 'O' || s[i] == 'U')
        {
            st.push(s[i]);
        }
    }

    // replace vowels in string with vowels from stack in reverse manner
    for (int i = 0; i < len; i++)
    {
        if (s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u' || s[i] == 'A' || s[i] == 'E' || s[i] == 'I' || s[i] == 'O' || s[i] == 'U')
        {
            string ch(1, st.top()); // get vowel character from stack as string
            s.replace(i, 1, ch);    // we are replacing vowels at ith index , only till 1 character with ch
            st.pop();
        }
    }
}


int Longest_Valid_Substring(string s){
    stack<int> st;
    st.push(-1);

    int longest_valid = 0;

    for(int i = 0; i<s.length(); i++){
        if(s[i] == '(') st.push(i);

        else if(s[i] == ')'){
            if(st.size()) st.pop();

            if(st.size()) longest_valid = max(longest_valid, i-st.top()); // update maximum longest valid substring size

            else st.push(i); //if there is no matching brackets 
        }
    }

    return longest_valid;
}

int prefix_expression_evaluation(string expression)
{
    int len = expression.length();

    int operand1, operand2;

    stack<int> st;

    // for prefix expression evaluation we have to go from right to left of expression
    for (int i = len - 1; i >= 0; i--)
    {

        if (expression[i] >= '0' && expression[i] <= '9')
        {
            st.push(expression[i] - '0'); // char integer to integer
        }

        else
        {
            operand1 = st.top();
            st.pop();
            operand2 = st.top();
            st.pop();

            switch (expression[i])
            {
            case '^':
                st.push(pow(operand1, operand2));
                break;

            case '/':
                st.push(operand1 / operand2);
                break;

            case '*':
                st.push(operand1 * operand2);
                break;

            case '+':
                st.push(operand1 + operand2);
                break;

            case '-':
                st.push(operand1 - operand2);
                break;
            }
        }
    }

    return st.top();
}

int postfix_expression_evaluation(string expression)
{
    int len = expression.length();

    int operand1, operand2;

    stack<int> st;

    // for postfix expression evaluation we have to go from left to right of expression
    for (int i = 0; i < len; i++)
    {

        if (expression[i] >= '0' && expression[i] <= '9')
        {
            st.push(expression[i] - '0'); // char integer to integer
        }

        else
        {
            operand2 = st.top();
            st.pop();
            operand1 = st.top();
            st.pop();

            switch (expression[i])
            {
            case '^':
                st.push(pow(operand1, operand2));
                break;

            case '/':
                st.push(operand1 / operand2);
                break;

            case '*':
                st.push(operand1 * operand2);
                break;

            case '+':
                st.push(operand1 + operand2);
                break;

            case '-':
                st.push(operand1 - operand2);
                break;
            }
        }
    }

    return st.top();
}


// precedence of opeartor
int prec(char operator_)
{
    if (operator_ == '^')
        return 3;

    else if (operator_ == '*' || operator_ == '/')
        return 2;

    else if (operator_ == '+' || operator_ == '-')
        return 1;

    else
        return -1;
}


// Infix to Postifix

string Infix_to_Postfix(string Infix_exp)
{
    int len = Infix_exp.length();

    string Postfix_exp = "";

    stack<char> st;

    for (int i = 0; i < len; i++)
    {

        // If operand in Infix_exp[i] then add to Postifix_exp
        if ((Infix_exp[i] >= '0' && Infix_exp[i] <= '9') || (Infix_exp[i] >= 'A' && Infix_exp[i] <= 'Z') || (Infix_exp[i] >= 'a' && Infix_exp[i] <= 'z'))
        {
            Postfix_exp += Infix_exp[i];
        }

        // If ( in Infix_exp[i] then push to stack
        else if (Infix_exp[i] == '(')
        {
            st.push(Infix_exp[i]);
        }

        // If ) in Infix_exp[i] then pop from stack and add to Postifix_exp untill we get st.top=='('
        else if (Infix_exp[i] == ')')
        {
            while (st.size() && st.top() != '(')
            {
                Postfix_exp += st.top();
                st.pop();
            }
            st.pop();
        }

        // If operator in Infix_exp[i] has less or equal precedence than opearator at st.top(), then pop st and add to Postfix_exp
        else
        {
            while (st.size() && prec(st.top()) >= prec(Infix_exp[i]))
            {
                Postfix_exp += st.top();
                st.pop();
            }
            st.push(Infix_exp[i]); // push operator of Infix_exp[i] in stack
        }
    }

    // At the end pop and add all operands/operators from stack to postfix_expression until stack get empty.
    while (st.size())
    {
        Postfix_exp += st.top();
        st.pop();
    }

    return Postfix_exp;
}


string Infix_to_Prefix(string Infix_exp)
{
    int len = Infix_exp.length();

    string Prefix_exp = "";

    stack<char> st;

    // start from end side of Infix Expression
    for (int i = len - 1; i >= 0; i--)
    {

        // If operand in Infix_exp[i] then add to Preifix_exp
        if ((Infix_exp[i] >= '0' && Infix_exp[i] <= '9') || (Infix_exp[i] >= 'A' && Infix_exp[i] <= 'Z') || (Infix_exp[i] >= 'a' && Infix_exp[i] <= 'z'))
        {
            Prefix_exp += Infix_exp[i];
        }

        // If ( in Infix_exp[i] then push to stack
        else if (Infix_exp[i] == '(')
        {
            st.push(Infix_exp[i]);
        }

        // If ) in Infix_exp[i] then pop from stack and add to Prefix_exp untill we get st.top=='('
        else if (Infix_exp[i] == ')')
        {
            while (st.size() && st.top() != '(')
            {
                Prefix_exp += st.top();
                st.pop();
            }
            st.pop();
        }

        // If operator in Infix_exp[i] has less precedence than opearator at st.top(), then pop st and add to Prefix_exp
        else
        {
            while (st.size() && prec(st.top()) > prec(Infix_exp[i]))
            {
                Prefix_exp += st.top();
                st.pop();
            }
            st.push(Infix_exp[i]); // push operator of Infix_exp[i] in stack
        }
    }

    // At the end pop and add all operands/operators from stack to postfix_expression until stack get empty.
    while (st.size())
    {
        Prefix_exp += st.top();
        st.pop();
    }

    // Reverse to get Prefix Expression
    reverse(Prefix_exp.begin(), Prefix_exp.end());

    return Prefix_exp;
}


//Stack Questions with Recursive approach

// Function to delete middle element of a stack.
// First Aprroach - using one extra stack
// TC : O(n)
// SC : O(n)
void deleteMid(stack<int> &st)
{
    stack<int> t_st; // temp stack

    int mid = (st.size() + 1) / 2; // mid

    while (st.size() > mid)
    {
        t_st.push(st.top());
        st.pop();
    }

    st.pop(); // deleting middle element

    while (t_st.size())
    {
        st.push(t_st.top());
        t_st.pop();
    }
}


// Function to delete middle element of a stack.
//  Second Approach - using recursion
//  TC : O(n)
//  SC : O(1)
void deleteMid_Recursively(stack<int> &st, int count, int mid)
{
    // base case
    if (count == mid)
    {
        st.pop();
        return;
    }

    int element = st.top(); // element before mid
    st.pop();

    // recursive call

    deleteMid_Recursively(st, count + 1, mid);

    st.push(element);
}


// Function to insert at end of a stack.
// First Aprroach - using one extra stack
// TC : O(n)
// SC : O(n)
void insertEnd(stack<int> &st, int element)
{
    stack<int> t_st; // temp stack

    while (!st.empty())
    {
        t_st.push(st.top());
        st.pop();
    }

    st.push(element); // inserting element at end after every element moved to temp stack

    while (t_st.size())
    {
        st.push(t_st.top()); // again pushing all the elements from temp stack to original stack
        t_st.pop();
    }
}

// Function to insert at end of a stack.
// Second Approach - using recursion
// TC : O(n)
// SC : O(1)
void insertEndRecursively(stack<int> &st, int element)
{
    // base case
    if (st.empty())
    {
        st.push(element);
        return;
    }

    int top_element = st.top(); // element before end
    st.pop();

    // recursive call

    insertEndRecursively(st, element);

    st.push(top_element);
}

// Reverse a stack using recursion
void ReverseStack(stack<int> &st)
{
    // base case
    if (st.empty())
    {
        return;
    }

    int top_element = st.top();
    st.pop();

    ReverseStack(st);

    insertEndRecursively(st, top_element);
}

// Soretd Insert using recursion
void sortedInsert(stack<int> &st, int element)
{
    // base case
    if (st.empty() || st.top() < element)
    {
        st.push(element);
        return;
    }

    int top_element = st.top();
    st.pop();

    sortedInsert(st, element);

    st.push(top_element);
}

// sort stack using recursion
void sortStack(stack<int> &st)
{
    // base case
    if (st.empty())
        return;

    int element = st.top();
    st.pop();

    // recursive call
    sortStack(st);

    sortedInsert(st, element);
}

// Clone a stack without using extra space; Recusrion
// TC:O(N*N)
// SC:O(1)
void clonestack(stack<int> st, stack<int> &cloned_st)
{
    // base case
    if (st.empty())
    {
        return;
    }

    int element = st.top();
    st.pop();

    // recursive call
    clonestack(st, cloned_st);

    st.push(element);
    cloned_st.push(element);
}


vector<int> previous_smallest_element(vector<int> arr, int n)
{
    vector<int> PS(n, -1); // intializing vector with -1 to store left_next_smallest_element

    stack<int> st;

    for (int i = 0; i < n; i++)
    {
        if (st.size() > 0)
        {

            if (arr[i] > st.top())
            {
                PS[i] = st.top();
                st.push(arr[i]);
            }

            else if (st.top() >= arr[i])
            {
                st.pop();
                i--;
            }
        }

        else
            st.push(arr[i]);
    }

    return PS;
}

vector<int> next_smallest_element(vector<int> arr, int n)
{
    vector<int> NS(n, -1); // intializing vector with -1 to store right_next_smallest_element

    stack<int> st;

    for (int i = n - 1; i >= 0; i--)
    {
        if (st.size())
        {

            if (arr[i] > st.top())
            {
                NS[i] = st.top();
                st.push(arr[i]);
            }

            else if (arr[i] <= st.top())
            {
                st.pop();
                i++;
            }
        }

        else
            st.push(arr[i]);
    }

    return NS;
}

vector<int> previous_greater_element(vector<int> arr, int n)
{
    vector<int> PM(n, -1);

    stack<int> st;

    for (int i = 0; i < n; i++)
    {
        if (st.size() > 0)
        {
            if (st.top() > arr[i])
            {
                PM[i] = st.top();
                st.push(arr[i]);
            }

            else if (st.top() <= arr[i])
            {
                st.pop();
                i--;
            }
        }

        else
        {
            st.push(arr[i]);
        }
    }

    return PM;
}

vector<int> next_greater_element(vector<int> arr, int n)
{
    vector<int> NG(n, -1);

    stack<int> st;

    for (int i = n - 1; i >= 0; i--)
    {
        if (st.size() > 0)
        {
            if (st.top() > arr[i])
            {
                NG[i] = st.top();
                st.push(arr[i]);
            }

            else if (st.top() <= arr[i])
            {
                st.pop();
                i++;
            }
        }

        else
        {
            st.push(arr[i]);
        }
    }
    return NG;
}

// Next Greater Frequency
//  find the closest element on it's right that has a greater frequency than its own frequency.

vector<int> next_greater_freq_ele(vector<int> arr, int n)
{
    int maxi = *max_element(arr.begin(), arr.end());

    vector<int> ht(maxi + 1, 0); // hashtable

    for (int i = 0; i < n; i++)
    { // storing frequency in hashtable
        ht[arr[i]]++;
    }

    // rest code has same logic as next greater element
    //  the only diffrence is, here we are checking for higher frequency
    vector<int> NG_freq(n, -1);

    stack<int> st;

    for (int i = n - 1; i >= 0; i--)
    {
        if (st.size())
        {
            if (ht[st.top()] > ht[arr[i]])
            {
                NG_freq[i] = st.top();
                st.push(arr[i]);
            }

            else if (ht[st.top()] <= ht[arr[i]])
            {
                st.pop();
                i++;
            }
        }

        else
        {
            st.push(arr[i]);
        }
    }

    return NG_freq;
}

vector<int> previous_smallest_element_index(vector<int> arr)
{
    int n = arr.size();

    stack<int> index_st;
    index_st.push(-1);

    vector<int> PS_idx(n);

    for (int i = 0; i < n; i++)
    {
        int curr = arr[i];
        while (index_st.top() != -1 && arr[index_st.top()] >= curr)
        {
            index_st.pop();
        }

        PS_idx[i] = index_st.top();
        index_st.push(i);
    }

    return PS_idx;
}

vector<int> next_smallest_element_index(vector<int> arr)
{
    int n = arr.size();

    stack<int> index_st;
    index_st.push(-1);

    vector<int> NS_idx(n);

    for (int i = n - 1; i >= 0; i--)
    {
        int curr = arr[i];
        while (index_st.top() != -1 && arr[index_st.top()] >= curr)
        {
            index_st.pop();
        }

        NS_idx[i] = index_st.top();
        index_st.push(i);
    }

    return NS_idx;
}

// largest rectangle area
int largestRectangleArea(vector<int> &heights)
{
    int len = heights.size();

    // we know height but to get maximum width we have to get  previous and next smallest_element_index for each height
    vector<int> PS_idx = previous_smallest_element_index(heights);
    vector<int> NS_idx = next_smallest_element_index(heights);

    int largest_rect = INT_MIN;

    for (int i = 0; i < len; i++)
    {
        int height = heights[i]; // height

        if (NS_idx[i] == -1)
        { // element that doesn't have any next_smallest element (or we can say have -1) , cosider its width can be till last bar
            NS_idx[i] = len;
        }

        int width = NS_idx[i] - PS_idx[i] - 1; // width

        int rect = width * height; // area

        largest_rect = max(largest_rect, rect);
    }

    return largest_rect;
}


// Max Rectangle in Binary matrix with all 1's
int MaxRectangle(vector<vector<int>> matrix)
{
    int n = matrix.size();
    int m = matrix[0].size();

    int area = largestRectangleArea(matrix[0]); // first row

    // update all rows by adding them with above row
    for (int i = 1; i < n; i++)
    { // rows
        for (int j = 0; j < m; j++)
        { // columns

            // update cell if it is not 0
            if (matrix[i][j] != 0)
            {
                matrix[i][j] += matrix[i - 1][j];
            }
        }

        area = max(area, largestRectangleArea(matrix[i]));
    }

    return area;
}

//Rain Water Trapping Problem 
// Previuosly maximum element
vector<int> previous_maximum_element(vector<int> arr)
{
    int n = arr.size();

    vector<int> PM(n, -1);

    stack<int> st;

    for (int i = 0; i < n; i++)
    {
        if (st.size())
        {
            if (st.top() > arr[i])
            {
                PM[i] = st.top();
            }

            else if (st.top() <= arr[i])
            {
                while (st.size() && st.top() <= arr[i])
                {
                    st.pop();
                }
                if (st.size())
                {
                    PM[i] = st.top();
                }
                st.push(arr[i]);
            }
        }

        else
        {
            st.push(arr[i]);
        }
    }

    return PM;
}

// Next maximum element
vector<int> next_maximum_element(vector<int> arr)
{
    int n = arr.size();

    vector<int> NG(n, -1);

    stack<int> st;

    for (int i = n - 1; i >= 0; i--)
    {
        if (st.size())
        {
            if (st.top() > arr[i])
            {
                NG[i] = st.top();
            }

            else if (st.top() <= arr[i])
            {
                while (st.size() && st.top() <= arr[i])
                {
                    st.pop();
                }

                if (st.size())
                {
                    NG[i] = st.top();
                }

                st.push(arr[i]);
            }
        }

        else
        {
            st.push(arr[i]);
        }
    }

    return NG;
}

// formula we use here
//  water_trap = ( min(PM[i] , NG[i]) - height[i] );
int rainWaterTrapping(vector<int> height)
{
    int n = height.size();

    vector<int> NG = next_maximum_element(height);
    vector<int> PM = previous_maximum_element(height);

    int total_water_trap = 0;

    for (int i = 0; i < n; i++)
    {

        int NG_elem = NG[i];
        int PM_elem = PM[i];

        if (PM_elem != -1 && NG_elem != -1)
        {
            int water_trap = (min(NG_elem, PM_elem) - height[i]); // water trap formula

            total_water_trap += water_trap;
        }
    }
    return total_water_trap;
}


//Stock Span 
vector<int> StockSpan(vector<int> price){
    int n = price.size();

    vector<int> max_consecutive_days(n,1); //previous greatest stock
        
    stack<int> stk;
    
    for(int i=0; i<n; i++){
        if(stk.size()){
            if(price[stk.top()] > price[i]){
                max_consecutive_days[i]=i-stk.top();
                stk.push(i);
            }
            
            else if(price[stk.top()] <= price[i]){
                while(stk.size() && price[stk.top()] <= price[i] ){
                    stk.pop();
                }

                if(stk.size()){
                    max_consecutive_days[i]=i-stk.top();  //to get (maximum consecutive day) = curr index - previous_greatest_stock_index
                }
                else{
                    max_consecutive_days[i]=i-(-1);  //if there will be no previous greatest stock index, (maximum consecutive day) = curr index - (-1)
                }

                stk.push(i);
            }
        }

        else{
            stk.push(i);
        }
    }

    return max_consecutive_days;
}

//celebrity Problem

int celebrity_problem(vector<vector<int>> &M, int n)
{
    stack<int> st;

    // pushing all the members(rows) in stack
    for (int row = 0; row < n; row++)
    {
        st.push(row);
    }

    // eleminating rows/members which can not be celebrity, at the end only one row/member will be left to check further it is celebrity or not

    while (st.size() > 1)
    {
        int top_row = st.top(); // top row in stack
        st.pop();
        int next_top_row = st.top(); // next top row in stack
        st.pop();

        if (M[top_row][next_top_row] == 1)
        { // checking if "top_row" know(1) the "next_top_row" , then "top_row" can not be celebrity b/c celebrity dont know anyone in party and we push only "next_top_row" and eleminate "top_row"

            st.push(next_top_row);
        }

        else if (M[top_row][next_top_row] == 0)
        { // checking if "next_top_row" not known(0) by "top_row" , then "next_top_row" can not be celebrity b/c celebrity known by everyone in party and we push only "top_row" and eleminate "next_top_row"

            st.push(top_row);
        }
    }

    // here we will left with only one row/ member , now we check it is celebrity or not

    int celebrity = st.top();

    for (int i = 0; i < n; i++)
    {
        if (M[celebrity][i] == 1)
        { // checking if celebrity know(1) any row then there is no celebrity
            celebrity = -1;
            break;
        }

        else if (i != celebrity and M[i][celebrity] == 0)
        { // checking if any row don't know(0) any celebrity, then there no celebrity
            celebrity = -1;
            break;
        }
    }

    return celebrity;
}



int main()
{
    
//reverse sentence by removing extra white spaces

    // string str="    I   am             Abhay!   ";
    // reverse_Sentence(str);

//Check Redundancy (present of useless brackets)
    
    // string expression="(a+b)))";
    // string result=checkRedundancy(expression)?"Redundancy Present!":"No Redundancy!";
    // cout<<result<<endl;

//Minimum cost to make invalid string valid

    // string expression="))))(())))()(())))";
    // cout<<"\nCost to make invalid string valid: "<<minCostToMakeStringValid(expression)<<endl;

//reverse vowels of string

    // string s="hello";
    // reverseVowels(s);
    // cout<<"\nString with reversed vowels: "<<s<<endl;

// Longest Valid Substring
    string s = "(((()))(()()()(()()()(()(()()()(()(()(()(()";
    cout<<"Longest Valid Substring Size : "<<Longest_Valid_Substring(s);


//delete middle element of a stack.
// first approach

    // vector<int> vec={1,2,3,4,5,6,7,8,9,10};
    // stack<int> st=vectorToStack(vec);

    // deleteMid(st);

    // printStack(st);  //printing mid after deleting mid

//Recursion Approach

    // vector<int> vec_={1,2,3,4,5,6,7,8,9,10};
    // stack<int> st1=vectorToStack(vec_);

    // int mid_=(st1.size()+1)/2;
    // deleteMid_Recursively(st1,0,mid_);

    // printStack(st1);

// insert at bottom of a stack.
// first approach
    //  vector<int> vec={1,2,3,4,5,6,7,8,9,10};
    //  stack<int> st=vectorToStack(vec);

    // int element=11;

    // insertEnd(st,element);

    // printStack(st);

//Recursion Approach

    // vector<int> vec_={1,2,3,4,5,6,7,8,9,10};
    // stack<int> st1=vectorToStack(vec_);

    // int element1=11;

    // insertEndRecursively(st1,element);

    // printStack(st1);

// Reverse Stack using Recursion

    // vector<int> vec={1,2,3,4,5,6,7,8,9,10};
    // stack<int> st=vectorToStack(vec);

    // cout<<"Stack before reverse:"<<endl;
    // printStack(st);

    // ReverseStack(st);

    // cout<<"Stack after reverse:"<<endl;
    // printStack(st);

// Sort Stack using recursion

    // vector<int> vec={-1,20,13,-4,5,16,-7,81,19,11};
    // stack<int> st=vectorToStack(vec);

    // cout<<"Stack before sort:"<<endl;
    // printStack(st);

    // sortStack(st);

    // cout<<"Stack after sort:"<<endl;
    // printStack(st);

// Clone a stack without using extra space; Recusrion

    // vector<int> vec={1,2,3,4,5,6,7,8,9,10};
    // stack<int> st=vectorToStack(vec), cloned_st;

    // clonestack(st,cloned_st);

    // cout<<"Stack:"<<endl;
    // printStack(st);

    // cout<<"Cloned Stack:"<<endl;
    // printStack(cloned_st);




// Prefix Expression Evaluation
    // string prefix_expression="+-*42/43*56";
    // cout<<"Prefix_Evaluation: " << prefix_expression_evaluation(prefix_expression) << endl;

//Postfix Expression Evaluation
    // string postfix_expression="42*43/-56*+";
    // cout<<"Postfix_Evaluation: " << postfix_expression_evaluation(postfix_expression) << endl;

//Infix Expression to Postifix Expression Conversion
    // string infix_expression="4*2-4/3+5*6";
    // cout<<"Postfix Expression of "<<infix_expression<<" : "<<Infix_to_Postfix(infix_expression)<<endl;

    // //Infix Expression to Preifix Expression Conversion
    // cout<<"Prefix Expression of "<<infix_expression<<" : "<<Infix_to_Prefix(infix_expression)<<endl;

   



    vector<int> A = {0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1};
    int n = A.size();

//Previous Smallest Element
    // vector<int> PS=previous_smallest_element(A,n);
    // cout<<"\nPrevious_smallest_element: "<<endl;
    // print_vector(PS);

//Next Smallest Element
    // vector<int> NS=next_smallest_element(A,n);
    // cout<<"\nNext_smallest_element: "<<endl;
    // print_vector(NS);

//Previous Greater Element
    // vector<int> PM = previous_greater_element(A, n);
    // cout << "\nPrevious_greater_element: " << endl;
    // print_vector(PM);

// Next Greater Element
    vector<int> NG = next_greater_element(A, n);
    cout << "\nNext_greater_element: " << endl;
    print_vector(NG);

//Next Greater Element's Frequency 
    // vector<int> NG_freq=next_greater_freq_ele(A,n);
    // cout<<"\nNext_greater_frequency_element: "<<endl;
    // print_vector(NG_freq);

//largest rectangle in histogram

    // vector<int> heights={2,1,5,6,2,3};

    // // Previous Smallest ELement's Index

    // vector<int> PS_Index=previous_smallest_element_index(heights);
    // cout<<"\nPrevious_smallest_element_index: "<<endl;
    // print_vector(PS_Index);

    // // Next Smallest ELement's Index

    // vector<int> NS_Index=next_smallest_element_index(heights);
    // cout<<"\nNext_smallest_element_index: "<<endl;
    // print_vector(NS_Index);

    // cout<<"\nLargest rectangle: "<<largestRectangleArea(heights)<<endl;

//Max Rectangle in Binary matrix with all 1's

    // vector<vector<int>> matrix=
    // {
    //     {0,1,1,0},
    //     {1,1,1,1},
    //     {1,1,1,1},
    //     {1,1,0,0}
    // };

    // cout<<"\nMax Rectangle in Binary matrix with all 1's: "<<MaxRectangle(matrix)<<endl;

//Trapping rain Water Problem
    
    // vector<int> height = {9,8,3,2,3,3,4,5,7,3};
    // // 9,8,3,2,3,3,4,5,7,3 = 22
    // // 4,2,0,3,2,4,3,4 = 10
    // // 9,6,6,5,8,9,9,7,4,0,3,0,0,3,6,9  = 60

    // // Previous Greater ELement and it's Index

    // cout << "\nPrevious_maximum element: " << endl;
    // print_vector(previous_maximum_element(height));

    // // Next Greater ELement and it's Index
    
    // cout << "\nNext_maximum element: " << endl;
    // print_vector(next_maximum_element(height));

    // cout << "\nTotal Water Trap: " << rainWaterTrapping(height);

// Stock Span

    // vector<int> price = {100,80,60,70,60,75,85}; 
    // vector<int> max_consecutive_days = StockSpan(price);

    // cout<<"\nmax_consecutive days: "<<endl;
    // print_vector(max_consecutive_days); //1 1 1 2 1 4 6

    
    
//Celebrity problem

    // vector<vector<int>> M = 
    // {
    //     {0,0,0},
    //     {0,0,0},
    //     {0,0,0}
    // };
    // int n=M.size();
    // cout<<"Celebrity : "<<celebrity_problem(M,n);





}
