#include <bits/stdc++.h>
using namespace std;

void print_array(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

void print_vector(vector<int> vec)
{
    // cout<<endl;
    for (int i = 0; i < vec.size(); i++)
    {
        cout << vec[i] << " ";
    }
    cout << endl;
}

void print_vector_pair(vector<pair<int, int>> vec)
{
    for (int i = 0; i < vec.size(); i++)
    {
        cout << "{" << vec[i].first << "," << vec[i].second << "}"
             << " ";
    }
    cout << endl;
}

void print_pair(pair<int, int> vec)
{
    cout << "{" << vec.first << "," << vec.second << "}"
         << " ";
}

void print_2D_vector(vector<vector<int>> vec)
{
    for (int i = 0; i < vec.size(); i++)
    {
        cout << "{ ";
        for (int j = 0; j < vec[i].size(); j++)
        {
            cout << vec[i][j] << " ";
        }
        cout << "}"
             << " ";
    }
    cout << endl;
}

stack<int> vectorToStack(vector<int> vec)
{
    stack<int> st;

    for (int i = vec.size() - 1; i >= 0; i--)
    {
        st.push(vec[i]);
    }

    return st;
}

void printStack(stack<int> st)
{
    while (st.size())
    {
        cout << st.top() << " ";
        st.pop();
    }

    cout << endl;
}

