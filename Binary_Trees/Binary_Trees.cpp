#include<bits/stdc++.h>
using namespace std;
class node{
    public:
    int data;
    node *left;
    node *right;

    node(int data){
        this->data=data;
        this->left=NULL;
        this->right=NULL;
    }
};

node* binaryTree(node *root){
    int data;
    cout<<"Enter data: "<<endl;
    cin>>data;

    root=new node(data);

    if(data==-1){
        return NULL;
    }

    cout<<"Enter for left node:"<<data<<endl;
    root->left=binaryTree(root->left);

    cout<<"Enter for right node:"<<data<<endl;
    root->right=binaryTree(root->right);

    return root;
    
}

void levelOrderTraversal(node *root){
    queue<node*> que;
    que.push(root);
    que.push(NULL);
    
    while(!que.empty()){
        node *temp=que.front();
        que.pop();

        if(temp==NULL){
            cout<<endl;
        }


    }
}

int main(){
    node *root=NULL;

    root=binaryTree(root);

}