#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
    int data;
    Node *next;

    Node(){
        data=-1;
        next=NULL;
    }

    Node(int data){
        this->data=data;
        this->next=NULL;
    }
};

int size_ll(Node *head){
    Node *Node=head;
    int length=0;
    while(Node!=NULL){
        Node=Node->next;
        length++;
    }
    return length;
}


Node *insert_at_beginning(Node *head, int new_data){
    Node *new_Node = new Node(new_data); // by using constructor we are creating here new_Node->data=new_data; and new_Node->next=NULL;
    
    if(head==NULL){
        head=new_Node;
    }

    else{
        new_Node->next=head;
        head = new_Node;
    }
    return head;
}

Node *insert_after(Node *prev_Node_add , int new_data){
    Node *prev_Node=prev_Node_add;

    if(prev_Node == NULL){
        cout<<"Previous Node cannot be null!";
    }

    Node *new_Node = new Node(new_data);

    new_Node->next = prev_Node->next;

    prev_Node->next = new_Node;

    return prev_Node;
}

Node *insert_at_end(Node *head, int new_data){
    Node *new_Node=new Node(new_data);

    if(head==NULL){
        head=new_Node;
    }

    Node *temp=head;

    while(temp->next!=NULL){
        temp=temp->next;
    }
    temp->next=new_Node;  

    return head;
}

Node *insert_at_pos(Node *head, int new_data, int pos){
    Node *new_Node=new Node(new_data);

    Node *temp=head;

    for(int i=0;i<pos-2;i++){
        temp=temp->next;
    }

    new_Node->next=temp->next;
    temp->next=new_Node;

    return head;
}

Node *delete_from_beginning(Node *head){
    Node *temp=head;  //accessing original head in temp
    head = temp->next;
    free(temp);

    return head;
}

Node *delete_from_end(Node *head){
    Node *curr=head, *prev = NULL;

    while(curr->next){
        prev=curr;
        curr=curr->next;
    }
    prev->next=NULL;
    delete(curr); 

    return head;
}

Node *delete_from_pos(Node *head,int idx){
    Node *Node=head, *temp,*prev_Node;

    for(int i=0;i<idx+1;i++){
        temp=Node;
        Node=Node->next;
        if(i<idx){
            prev_Node=temp;       
        }
    }
    prev_Node->next=Node;
    free(temp);

    return head;
}

Node *creating_LL(Node *head, vector<int> vec){
    Node *curr = head;
    for(int i=0; i<vec.size(); i++){
        Node *new_Node = new Node(vec[i]);

        if(head->data == -1 ){
            head=new_Node;
        }
        while(curr->next!=NULL){
            curr=curr->next;
        }
        curr->next = new_Node;  
    }
    return head;
}

void print_linked_list(Node *head){
    Node *temp=head; 
    while(temp!=NULL){
        cout<<temp->data<<" -> ";
        temp=temp->next;
    }
}

//sort using bubble sort
Node* sort(Node *head){
    Node *i = head;
        
    while(i->next){
        Node *j = i->next;
        while(j){
            if(i->data > j->data){
                int temp = j->data;
                j->data = i->data;
                i->data = temp;
            }
            j = j->next;
        }
        i = i->next;
    }
    
    return head;
}

Node* segregate_Even_Odd(Node *head){
 
    Node *even = new Node(0); //even Node's head
    Node *odd = new Node(0); //odd Node's head
    
    int even_len = 0, odd_len = 0; 
    
    Node *odd_temp = odd; 
    Node *even_temp = even;
    
    while(head){
        //getting even node
        if((head->data)%2 == 0){
            if(even_len>0 && even){
                Node *new_node = new Node(head->data);
                even_temp->next = new_node;
                even_temp = even_temp->next;
            } 
            else {
                even->data = head->data;
                even_len++;
            }
        }
        //getting odd node
        else{
            if(odd_len>0 && odd){
                Node *new_node = new Node(head->data);
                odd_temp->next = new_node;
                odd_temp = odd_temp->next;
                
            } 
            else {
                odd->data = head->data;
                odd_len++;
            }
            
        }
        head = head->next;
    }
    
    Node *curr = even; //curr pointing at even node's head
    while(curr->next){
        curr = curr->next;
    }

    // now, curr pointing at last even node
    if(odd_len>0) curr->next = odd; //checking for odd nodes length ... if it is there then add odd node's head at curr end (end of even node)
    
    if(even_len == 0) return odd; //checking if there is no even nodes ... then directly return odd even node's head
    return even; 

}

int main(){
    Node *head = new Node(); //head will be created with data 1 and next is null

    //Insert in LL

    // head = insert_at_beginning(head,2); //insert at beginning ; new node will be created before 6 and this new node will become head.
    // head = insert_after(head,3); //insert after head node; 9 will be inserted head that is now 7
    // head = insert_at_end(head,4);   //insert at end
    // head = insert_after(head->next,10); //insert after head->next node
    // head = insert_at_pos(head,11,2); //insert 11 at position 2 

    // cout<<"After inserting values:"<<endl;

    // print_linked_list(head);

    // //Delete in LL

    // head = delete_from_beginning(head);
    // head = delete_from_end(head);
    // head = delete_from_pos(head,2);


    // cout<<"\nAfter deleting values:"<<endl;
    // print_linked_list(head);


// Sort
    // head = sort(head);
    // cout<<"\nAfter Sorting Values:"<<endl;
    // print_linked_list(head);


// Segregate_Even_Odd
    vector<int> vec = {1,2,3,4,5,6};
    head = creating_LL(head, vec);
    
    cout<<"LL before Segregate_Even_Odd :"<<endl;
    print_linked_list(head);

    head = segregate_Even_Odd(head);

    cout<<"LL after Segregate_Even_Odd :"<<endl;
    print_linked_list(head);






    






}