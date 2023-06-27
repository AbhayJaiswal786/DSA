#include<bits/stdc++.h>
#include "C:\Users\asus1\OneDrive\Attachments\__Programming\Winning Camp\DSA\_Shortcut.cpp"
using namespace std;
class Node{
    public:
    int data;
    Node *left;
    Node *right;

    Node(int data){
        this->data=data;
        this->left=NULL;
        this->right=NULL;
    }
};

Node* build_binaryTree(Node *root){
    int data;
    cout<<"Enter data : ";
    cin>>data;

    root = new Node(data);

    if(data==-1){
        return NULL;
    }

    cout<<"Enter for left Node for "<<data<<" : "<<endl;
    root->left = build_binaryTree(root->left);

    cout<<"Enter for right Node for "<<data<<" : "<<endl;
    root->right = build_binaryTree(root->right);

    return root;
}

void Preorder_Traversal(Node *root){
    if(root == NULL) return;

    cout<<root->data<<" ";
    Preorder_Traversal(root->left);
    Preorder_Traversal(root->right);
}

void Inorder_Traversal(Node *root){
    if(root == NULL) return;

    Inorder_Traversal(root->left);
    cout<<root->data<<" ";
    Inorder_Traversal(root->right);
}

void Postorder_Traversal(Node *root){
    if(root == NULL) return;

    Postorder_Traversal(root->left);
    Postorder_Traversal(root->right);
    cout<<root->data<<" ";
}

void LevelOrderTraversal(Node *root){
    queue<Node *> que;
    que.push(root);

    while(que.size()){
        int size = que.size();
        for(int i = 0; i<size; i++){
            Node *curr = que.front(); que.pop();

            cout<<curr->data<<" "; 
            if(curr->left) que.push(curr->left);
            if(curr->right) que.push(curr->right);
        }
        cout<<endl;
    }
}

// Another way of level order traversal
void LevelOrderTraversal_(Node *root){
    queue<Node *> que;
    que.push(root);
    que.push(NULL);

    while(que.size()){
        Node *curr = que.front();
        que.pop();
        
        if(curr == NULL){ //to seperate each level output
            cout<<endl;
            if(que.size()) que.push(NULL);            
        }
        else{
            cout<<curr->data<<" "; 
            if(curr->left) que.push(curr->left);
            if(curr->right) que.push(curr->right);
        }
    }
}


Node* build_binaryTree_level_order(Node *root){
    queue<Node *> que;
    cout<<"Enter data for root : ";
    int data;
    cin>>data;
    root = new Node(data);
    que.push(root);

    while(que.size()){
        Node *curr = que.front(); que.pop();

        cout<<"Enter left node for "<<curr->data<<" : ";
        int left_data;
        cin>>left_data;

        if(left_data!= -1){
            curr->left = new Node(left_data);
            que.push(curr->left);
        }

        cout<<"Enter right node for "<<curr->data<<" : ";
        int right_data;
        cin>>right_data;

        if(right_data!= -1){
            curr->right = new Node(right_data);
            que.push(curr->right);
        }
    }
    return root;
}

void InOrder_Traversal_Iteratively(Node *root){
    stack<Node*> st;
    Node *curr = root;
    while(curr || st.size()){
        while(curr){ 
            st.push(curr);
            curr = curr->left;
        }
        curr = st.top(); st.pop(); 
        cout<<curr->data<<" ";
        curr = curr->right;
    }
}

void PreOrder_Traversal_Iteratively(Node *root){
    stack<Node*> st;
    st.push(root);
    while(st.size()){
        Node *curr = st.top(); st.pop();
        cout<<curr->data<<" ";

        if(curr->right) st.push(curr->right);
        if(curr->left) st.push(curr->left);
    }
}

void PreOrder_Traversal_Iteratively_OA(Node *root){
    stack<Node*> st;
    Node *curr = root;
    while(curr || st.size()){
        while(curr){
            cout<<curr->data<<" ";
            if(curr->right) st.push(curr->right);
            curr = curr->left;
        }
        if(st.size()) curr = st.top(); st.pop();
    }
}

//Some other Traversal techniques in Tree

//Spiral Traversal using two stacks
vector<int> spiral_Traversal(Node *root){
    if(root == NULL) return {};
    vector<int> spiral;
    
    stack<Node*> st1, st2;
    st1.push(root);
    while(st1.size() || st2.size()){
        while(st1.size()){
            Node *temp = st1.top(); st1.pop();
            spiral.push_back(temp->data); 
            
            if(temp->right) st2.push(temp->right);
            if(temp->left) st2.push(temp->left);
        }
        while(st2.size()){
            Node *temp = st2.top(); st2.pop();
            spiral.push_back(temp->data); 

            if(temp->left) st1.push(temp->left);
            if(temp->right) st1.push(temp->right);
        }
    }
    return spiral;
}

//Spiral Traversal using single queues
vector<vector<int>> spiral_Traversal_other_way(Node* root) {
    vector<vector<int>> ans;
    if(root == NULL) return ans;
    
    queue<Node *> que;
    que.push(root);
    int level_num = 0;

    while(que.size()){
        int size = que.size();
        vector<int> level;
        for(int i = 0; i<size; i++){
            Node *curr = que.front(); que.pop();

            level.push_back(curr->data); //pushing each level nodes
            if(curr->left){
                que.push(curr->left);
            }

            if(curr->right){
                que.push(curr->right);
            }
        }
        
        if(level_num%2 == 0){ //if level num is even then push it left to right manner
            ans.push_back(level);
        }
        
        if(level_num%2 != 0){ //if level num is odd then push it right to left by reversing level node's vector
            reverse(level.begin(), level.end());
            ans.push_back(level);
        }
        level_num++;
    }
    return ans;
}

// Boundary Traversal
// ALgo : 
// i.print root->data

// ii.print left part exclusive leaf node
 // for left part
   // i. print root
   // ii. if root->left then call for root->left
   // iii. else call for root->right

// iii.print leaf node (left to right)
 // for leaf node
    //i.check for leaf node if it is then store it 
    //ii. call for left
    // iii. call for right

// iv.print right part exclusive leaf node (but in reverse order) 
 // for right part reursive
   // i. if root->right ; then call for root->right
   // ii. else call for root->left
    //iii. print/store root
    
void traverseLeftPart(Node* root, vector<int> &ans){
    if(root == NULL) return ;

    if(root->left == NULL && root->right == NULL) return ; //exclusing leaf node

    ans.push_back(root->data);
    if(root->left) traverseLeftPart(root->left, ans); //if left then call for left
    else traverseLeftPart(root->right, ans); //else call for right
}

void leafNode(Node* root, vector<int> &ans){
    if(root == NULL) return;

    if(root->left == NULL && root->right == NULL){
        ans.push_back(root->data);
        return;
    } 

    leafNode(root->left, ans);
    leafNode(root->right, ans);
}

void reverseTraverseRightPart(Node* root, vector<int> &ans){
    if(root == NULL) return;

    if(root->left == NULL && root->right == NULL) return ; //exclusing leaf node

    if(root->right) reverseTraverseRightPart(root->right, ans);
    else reverseTraverseRightPart(root->left, ans);

    //waapas aa gaye 
    ans.push_back(root->data);
}

vector<int> boundaryTraversal(Node* root){
    vector<int> ans;
    if(root == NULL) return ans;

    // root->data store/print
    ans.push_back(root->data);

    //traverse left part 
    traverseLeftPart(root->left, ans);

    //traverse leaf nodes
    //for left subTree
    leafNode(root->left,ans);
    //for right subTree
    leafNode(root->right,ans);

    //traverse right part recusively
    reverseTraverseRightPart(root->right, ans);

    return ans;
}

//recursively
// TC : O(N) => we are traversing each node ones
// SC : O(height) => in recursive call stack , maximum space taken by = height of maximum sub-tree  
//NOTE : If we get skewed tree(means tree having only left nodes or having right nodes) then in that case SC : O(N)
int height_BT(Node *node){
    if(node == NULL) return 0;

    int left_height = height_BT(node->left); //left subtree height
    int right_height = height_BT(node->right); //right subtree height
    int height = max(left_height, right_height) + 1; //maximum of (height of left subtree , height of right subtree) + 1 (for root node) 

    return height; 
}


//iteratively
// TC : O(N) => we are traversing each node ones
// SC : O(N) => we are placing each node in queue
int height_BT_iteratively(Node *node){
    queue<Node *> que;
    que.push(node);
    que.push(NULL);

    int height = 0;

    while(que.size()){
        Node *temp = que.front();
        que.pop();
        
        if(temp == NULL){ //to seperate each level output
            height++;
            if(que.size()) que.push(NULL);            
        }
        
        else{
            if(temp->left){
                que.push(temp->left);
            }

            if(temp->right){
                que.push(temp->right);
            }
        }
    }
    return height;
}


//recursively
int Size_BT(Node *node){
    if(node == NULL) return 0;

    int left_size = Size_BT(node->left);
    int right_size = Size_BT(node->right);
    int size = left_size + right_size + 1;

    return size;
}

int Size_BT_iteratively(Node *node){
    queue<Node *> que;
    que.push(node);

    int size = 0;

    while(que.size()){
        Node *temp = que.front();
        que.pop();
        size++;
        if(temp->left){
            que.push(temp->left);
        }
        if(temp->right){
            que.push(temp->right);
        }
    }
    return size;
}


//Diameter of BT 
// Algorithm for finding the diameter of binary tree: 
// Find the left diameter 
// Find the right diameter
// Find the height of the left subtree
// Find the height of the right subtree
// Then diameter is the maximum of (height of the left subtree + height of the right subtree  + 1), the left diameter, and the right diameter. E.g. max( lh+rh+1,max(ld,rd))

// TC : O(N^2) ; N^2 is complexity b/c we are traversing all nodes two time through "diameter" function as well as "height" function ... which is not optimized
// for balanced tree , TC : O(N*log(N))

int diameter_BT(Node *root){
    if(root == NULL) return 0;

    int left_dia = diameter_BT(root->left); //left subtree diameter; case 1
    int right_dia = diameter_BT(root->right); //right subtree diameter ; case 2
    int left_right_both_dia = height_BT(root->left) + height_BT(root->right) + 1 ; // for left_to_right nodes dia ; case 3

    int diameter = max(max(left_dia, right_dia), left_right_both_dia);
    return diameter;
}

//TC : O(N) ... b/c we are fetching both height and diameter in single traversal of all nodes N.
// Here, we are reducing complexity by fetching both height and diameter in single traversal 

pair<int,int> diameter_BT_OA(Node *root){ //pair.first = height, pair.second =  diameter
    if(root == NULL) return {0,0}; //if node is NULL ... return 0 height , 0 diamter

    pair<int,int> left_subTree = diameter_BT_OA(root->left); //traversing left subtree
    pair<int,int> right_subTree = diameter_BT_OA(root->right); //traversing right subtree

    int lh = left_subTree.first; //left height
    int rh = right_subTree.first; // right height

    int ld = left_subTree.second; //left diameter
    int rd = right_subTree.second; //right diameter

    int height = max(lh,rh) + 1; 
    int diameter = max((lh + rh + 1),max(ld,rd));

    return {height, diameter};
}

// Check for Balanced Tree
//TC : O(N^2) ... we are traversing Nodes twice through "isBalanced" function as well as "height" function
//Algorithm:
//check for node's left subtree balanced or not
//check for node's right subtree balanced or not
//check for abs(height of node's right subtre - height of node's left subtre) should be less than or equal to 1
// if all three conditions meet then tree is balanced 

bool isBalanced(Node* root){
    if(root == NULL) return true;

    bool left_subTree_bal = isBalanced(root->left); //checking for node left subtree balanced
    bool right_subtree_bal = isBalanced(root->right); //checking for node right subtree balanced

    bool root_height_bal = abs(height_BT(root->left) - height_BT(root->right)) <= 1; ////checking for current node height balanced

    if(left_subTree_bal && right_subtree_bal && root_height_bal) return true;
    else return false;
}

// Check for Balanced Tree Optimized Approach
//TC : O(N)... we are traversing Nodes ones only here through "isBalanced" function and we are fetching "height" in the same call

pair<bool,int> isBalanced_OA(Node* root){ //pair.first = tell balanced or not , pair.second = height 
    if(root == NULL) return {true,0};

    pair<bool,int> left_subTree = isBalanced_OA(root->left); //traversing left subtree
    pair<bool,int> right_subTree = isBalanced_OA(root->right); //traversing right subtree

    bool left_subTree_bal = left_subTree.first; //getting result that left subtree is balanced or not
    bool right_subTree_bal = right_subTree.first; //getting result that right subtree is balanced or not

    bool root_height_bal = abs(left_subTree.second - right_subTree.second) <= 1; // checking current root is height balanced or not 

    bool balanced;
    if(left_subTree_bal && right_subTree_bal && root_height_bal) balanced = true; //if all above three condition meets then our tree is balanced 
    else balanced = false;

    int height = max(left_subTree.second, right_subTree.second) + 1; //height

    return {balanced, height}; // returning balanced result as wel as height
}

//Same tree or identical tree ; 
// iterative approach algorithm 

// One way is maintaining array
// Maintain an array say levelOrderTree1 and store the level order traversal of Binary tree 1 taking NULL nodes as ‘-1’.
// Maintain an array say levelOrderTree2 and store the level order traversal of Binary tree 2 taking NULL nodes as ‘-1’.
// Check if the two arrays are identical or not. If any of the indexes from both arrays mismatch return false otherwise return true.

// Second way use to solve maintaining queues
bool isIdentical_tree_itratively(Node* p, Node* q){
    if(p==NULL && q==NULL) return true;
    if(p==NULL || q==NULL) return false;

    queue<Node *> que1, que2;
    que1.push(p);
    que2.push(q);

    while(que1.size() && que2.size()){

        Node *temp1 = que1.front();
        que1.pop();
        
        Node *temp2 = que2.front();
        que2.pop();
        
        if(temp1 && temp2 && (temp1->data != temp2->data)) return false;
        else if((temp1->left && temp2->left == NULL) || (temp2->left && temp1->left == NULL)) return false;
        else if((temp1->right && temp2->right == NULL) || (temp2->right && temp1->right == NULL)) return false;

        if (temp1->left) que1.push(temp1->left);
        if (temp1->right) que1.push(temp1->right);

        if (temp2->left) que2.push(temp2->left);
        if (temp2->right) que2.push(temp2->right);    
    
    }
    return true;
}

//Same tree or identical tree ; 
// Recursive approach algorithm : 

// If both the root nodes are NULL, return true.
// If one root is NULL while the other is not, return false.
// If the data of roots of both the trees is not the same, return false.
// Recursively find if the left subtree of both the trees is identical or not and store it in some variable let’s say left, left = isIdentical(root1->left, root2->left).
// Recursively find if the right subtree of both the trees is identical or not and store it in some variable let’s say right, right = isIdentical(root1->right, root2->right).
// If any of the subtrees are not identical then return false otherwise return true, Return (left && right).

bool isIdentical_tree_recursively(Node *root1, Node *root2){
    if(root1 == NULL && root2 == NULL) return true;

    if((root1 && !root2) || (!root1 && root2)) return false;

    bool curr_node_data = (root1->data == root2->data);
    bool left_subTree = isIdentical_tree_recursively(root1->left, root2->left);
    bool right_subTree = isIdentical_tree_recursively(root1->right, root2->right);

    if(curr_node_data && left_subTree && right_subTree) return true;
    else return false; 
}


// Symmetric Tree
// Algorithm :
// if both left and right subtree are null then the tree is symmetric 
// if(a == NULL && b == NULL)return true; 
// // if both the tree are not null and there subtree are symmetric as well as the current values of the nodes are equal then we return true
// if(a && b && a->val == b->val && checkSymmetric(a->left, b->right) && checkSymmetric(a->right,  b->left)) return true; 
// // in every other case(either one of a or b is null or the values of nodes a and b are unequal)  we will return false as the tree can't be symmetric
// return false; 

bool checkSymmetric(Node* a, Node* b){
    if(a == NULL && b == NULL) return true;

    if(a && b && (a->data == b->data) && checkSymmetric(a->left, b->right) && checkSymmetric(a->right, b->left)) return true;
    return false;
}

bool isSymmetric(Node *root){
    if(root == NULL) return true;

    return checkSymmetric(root->left, root->right);
}

// Check tree is Sum Tree or not 
// Algorithm :
// if root is NULL then tree will be SumTree ; return true
// 1. check left_subtree is sumTree or not
// 2. check right_subtree is sumTree or not
// 3. check curr_root->val == to sum(left_subtree + right_subtree) 
// if all three conditions all true for any tree then it is sumTree

pair<bool,int> isSumTree(Node *root){ //pair.first == check whether tree is sumTree or not , pair.second == sum of roots from that node to leaf nodes
    if(root == NULL) return {true,0};

    if(!root->left && !root->right) return {true, root->data};

    pair<bool,int> left_subTree = isSumTree(root->left); //pair.first is checking left_subtree is sumTree or not && pair.second fetching sum till that node
    pair<bool,int> right_subTree = isSumTree(root->right); //pair.first is checking right_subtree is sumTree or not && pair.second fetching sum till that node

    bool isLeftSumTree = left_subTree.first; //storing result of left_subtree is sumTree or not
    bool isRightSumTree = right_subTree.first; //storing result of right_subtree is sumTree or not
    bool curr_root_sum_check = root->data == left_subTree.second + right_subTree.second; //storing result of curr_node that it is equal to sum of(left_subTree , right_subTree)

    pair<bool,int> ans;
    if(isLeftSumTree && isRightSumTree && curr_root_sum_check){
        ans.first = true;
        ans.second = 2*root->data; //2*root->data == root->data * (root->left->data + root->right->data)
    }

    else ans.first = false;
    return ans;
}




// 6 7 8 2 7 1 3 9 -1 1 4 -1 -1 -1 5

int main(){
    // 1 2 4 -1 -1 5 -1 -1 3 6 -1 -1 7 -1 -1
    // 9 8 13 4 -1 10 15 3 7 -1 11 -1 -1 6 -1 2 -1 -1 -1 5 -1 0 -1 -1 -1 -1 -1
    
    Node *root = NULL;

    root = build_binaryTree(root);
    // root = build_binaryTree_level_order(root);

    cout<<endl<<"PreOrder Traversal of Tree: "<<endl;
    Preorder_Traversal(root);

    cout<<endl<<"InOrder Traversal of Tree: "<<endl;
    Inorder_Traversal(root);

    cout<<endl<<"PostOrder Traversal of Tree: "<<endl;
    Postorder_Traversal(root);

    cout<<endl<<"Level Order Traversal of Tree: "<<endl;
    LevelOrderTraversal(root);
    cout<<endl<<"Another way of Level Order Traversal of Tree: "<<endl;
    LevelOrderTraversal_(root);

    cout<<endl<<"InOrder Traversal of Tree Iteratively: "<<endl;
    InOrder_Traversal_Iteratively(root);

    cout<<endl<<"PreOrder Traversal of Tree Iteratively: "<<endl;
    PreOrder_Traversal_Iteratively(root);

    // cout<<endl<<"PreOrder Traversal of Tree Iteratively with Optimized Approach: "<<endl;
    // PreOrder_Traversal_Iteratively_OA(root);
    
    cout<<endl<<"Spiral Traversal of Tree: "<<endl;
    print_vector(spiral_Traversal(root));
    cout<<endl<<"Another way of Spiral Traversal of Tree: "<<endl;
    print_2D_vector(spiral_Traversal_other_way(root));

    cout<<endl<<"Height of Tree: "<<endl;
    cout<<height_BT(root)<<endl;
    cout<<height_BT_iteratively(root)<<endl;

    cout<<endl<<"Size of Tree: "<<endl;
    cout<<Size_BT(root)<<endl;
    cout<<Size_BT_iteratively(root)<<endl;

    cout<<endl<<"Diameter of Tree: "<<endl;
    cout<<diameter_BT(root)<<endl;
    cout<<"Diameter of Tree with Optimized Approach: "<<endl;
    cout<<diameter_BT_OA(root).second<<endl;

    (isBalanced(root)) ? cout<<"Tree is Balanced!"<<endl : cout<<"Tree is not Balanced"<<endl;
    (isBalanced_OA(root).first) ? cout<<"Tree is Balanced!"<<endl : cout<<"Tree is not Balanced"<<endl;

    Node *root1 = NULL, *root2 = NULL;
    (isIdentical_tree_itratively(root1, root2)) ? cout<<"Tree is Identical!"<<endl : cout<<"Tree is not Identical"<<endl;
    (isIdentical_tree_recursively(root1, root2)) ? cout<<"Tree is Identical!"<<endl : cout<<"Tree is not Identical"<<endl;

    (isSumTree(root).first) ? cout<<"Tree is Sum Tree!"<<endl : cout<<"Tree is not Sum Tree"<<endl;


}