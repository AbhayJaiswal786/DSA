#include<bits/stdc++.h>
using namespace std;

class node{
    public:
    int data;
    node *next;

    node(){
        data=-1;
        next=NULL;
    }

    node(int data){
        this->data=data;
        this->next=NULL;
    }
};

int size_ll(node **head_add){
    node *node=*head_add;
    int length=0;
    while(node!=NULL){
        node=node->next;
        length++;
    }
    return length;
}

void insert_at_beginning(node **head,int new_data){
    node *new_node=new node(new_data); // by using constructor we are creating here new_node->data=new_data; and new_node->next=NULL;
    
    if(*head==NULL){
        *head=new_node;
    }

    else{
        new_node->next=*head;
        *head=new_node;
    }
}

void insert_after(node **prev_node_add,int new_data){
    node *prev_node=*prev_node_add;

    if(prev_node==NULL){
        cout<<"Previous node cannot be null!";
    }

    node *new_node=new node(new_data);

    new_node->next=prev_node->next;

    prev_node->next=new_node;

}

void insert_at_end(node **head_add,int new_data){
    node *new_node=new node(new_data);

    if(*head_add==NULL){
        *head_add=new_node;
    }

    node *temp=*head_add;

    while(temp->next!=NULL){
        temp=temp->next;
    }
    temp->next=new_node;  

}

void insert_at_pos(node **head,int new_data,int pos){
    node *new_node=new node(new_data);

    node *temp=*head;

    for(int i=0;i<pos-2;i++){
        temp=temp->next;
    }

    new_node->next=temp->next;
    temp->next=new_node;
}

void delete_from_beginning(node **head){
    node *temp=*head;  //accessing original head in temp
    *head=temp->next;
    free(temp);
}

void delete_from_end(node **head){
    node *node1=*head, *node2;

    while(node1->next!=NULL){
        node2=node1;
        node1=node1->next;
    }
    node2->next=NULL;
    delete(node1->next);  //correction
}

void delete_from_pos(node **head,int idx){
    node *node=*head, *temp,*prev_node;

    for(int i=0;i<idx+1;i++){
        temp=node;
        node=node->next;
        if(i<idx){
            prev_node=temp;       
        }
    }
    prev_node->next=node;
    free(temp);
}

void print_linked_list(node **head){
    cout<<"Linked List is:"<<endl;
    node *temp=*head; 
    while(temp!=NULL){
        cout<<temp->data<<" -> ";
        temp=temp->next;
    }
}

//sort using bubble sort
void sort(node **head_add){
    node *head, *node1, *node2;

    int n=size_ll(&head); //length

    head=*head_add;

    for(int i=0;i<=n;i++){
        for(int j=0;j<n-1;j++){
            node1=head;
            node2=head->next;
        }

        if(node1->data>node2->data){
            int temp = node1->data;
            node1->data = node2->data;
            node2->data = temp;                
        }
       
    }
}

int main(){
    node *head=NULL; //head will be created with data 1 and next is null

    //Insert in LL

    insert_at_beginning(&head,2); //insert at beginning ; new node will be created before 6 and this new node will become head.
    insert_after(&head,3); //insert after head node; 9 will be inserted head that is now 7
    insert_at_end(&head,4);   //insert at end
    insert_after(&head->next,10); //insert after head->next node
    insert_at_pos(&head,11,2); //insert 11 at position 2 

    cout<<"After inserting values:"<<endl;
    print_linked_list(&head);

    //Delete in LL

    delete_from_beginning(&head);
    delete_from_end(&head);
    delete_from_pos(&head,2);


    cout<<"\nAfter deleting values:"<<endl;
    print_linked_list(&head);

    //Sort
    // sort(&head);

}