#include<bits/stdc++.h>
#include<cmath>
using namespace std;

struct Node
{
    int key;
    Node *left;
    Node *right;
};

int hd=0;
// Creates new node in tree
Node *CreateNewNode(int val){
    Node *new_node = new Node();
    new_node->key = val;
    new_node->left = new_node->right = NULL;
    return new_node;
}

// Insert New elements to the tree 
Node *InsertNode(Node *root, int val){
   /* if (root == NULL){
        root = CreateNewNode(val);
        return root;
    }
    if(left_depth == right_depth){
        if(root->left==NULL){
            root->left = CreateNewNode(val);
            left_depth +=1;
            return root;
        }
        else{
            InsertNode(root->left, val);
        }
    }
    else if(left_depth > right_depth){
        if(root->right ==NULL){
            root->right = CreateNewNode(val);
            right_depth+=1;
            return root;
        }
        else{
            InsertNode(root->right, val);
        }
    }
    return root; */
    
    // Binary Search Tree Insert 

        if(root==NULL){
        root = CreateNewNode(val);
        return root;
    }
    if (val< root->key){
        cout<<"Root  "<<root->key<<" is greater so val goes to left \n";
        root->left = InsertNode(root->left, val);
        return root;
    }
    else if (val > root->key){
        cout<<"Root  "<<root->key<<" is smaller so val goes to right \n";
        root->right = InsertNode(root->right, val);
        return root;
    }
    return root;
}

// Finding the Minimum Node from the tree
Node *MinimumNode(Node *root){
    Node *node = root;
    while(node->left!=NULL && node)
        node = node->left;
    return node;
}

// Finding the maximum Node from the tree
Node *MaximumNode(Node *root){
    Node *node = root;
    while(node->right!=NULL && node)
        node = node->right;
    return node;
}
// Inorder tranversal
void inorder(Node *root){
    if(root!=NULL){
        inorder(root->left);
        cout<<root->key<<" ";
        inorder(root->right);
    }

}

// Finding the Depth of BST
int depth_of_bst(Node *root){
    int leftHeight;
    int rightTheight;
    if(root == NULL){
        return 0;
    }
    else{
        leftHeight = depth_of_bst(root->left);
        rightTheight = depth_of_bst(root->right);
        return max(leftHeight, rightTheight) + 1;

    }
}
void levelorder(Node * root, int level){
    if(root==NULL){
        return;
    }
    if(level==1){
        cout<<root->key<<" ";
    }
    else{
        levelorder(root->left, level-1);
        levelorder(root->right, level-1);
    }
}
void printlevelorder(Node *root){
    int height = depth_of_bst(root);
    for(int i=1; i<= height;i++)
        levelorder(root, i);
}

void postorder(Node *root){
    if(root!=NULL){
        postorder(root->left);
        postorder(root->right);
        cout<<root->key<<" ";
    }
}

// Counting Total Numbers of Nodes in the Left Sub tree
int countLeft(Node *root){
    int n=0;
    while(root->left!=NULL){
        n += 1;
        root = root->left;
    }
    return n;
}

// Counting Total Numbers of Nodes in the Left Sub tree
int countRight(Node *root){
    int n=0;
    while(root->right!=NULL){
        n += 1;
        root = root->right;
    }
   
    return n;
}

// Total Number of External Nodes int he tree
int ExternalNodes(Node *root){
    int l, r;
    if(root==NULL){
        return 0;
    }
    else{
        l = countLeft(root);
        r = countRight(root);
        return 1+ l + r;
    }
}

// toatl Numbers of Nodes in the Tree

int number_of_nodes_in_tree(Node *node){
    if(node==NULL)
       return 0;
    
    return 1+ number_of_nodes_in_tree(node->left) + number_of_nodes_in_tree(node->right);
    
}
void TopView(Node * root){

    queue<pair<Node*, int>> q;
    q.push(make_pair(root, 0));
    int horizontal_distance,l ,r=0;
    stack<int> left_vals;
    vector<int> right_vals;
    Node *node;
    while(q.size()){
        node = q.front().first;
        horizontal_distance = q.front().second;
        if(horizontal_distance< l){
            left_vals.push(node->key);
            l = horizontal_distance;
        }
        else if(horizontal_distance> r){
            right_vals.push_back(node->key);
            r = horizontal_distance;  
        }
        if(node->left){
            q.push(make_pair(node->left, horizontal_distance-1));
        }
        if(node->right){
            q.push(make_pair(node->right, horizontal_distance+1));
        }
        q.pop();

        while(left_vals.size()){
            cout<< left_vals.top();
            left_vals.pop();
        }
        cout<<root->key<<" ";
        for (auto x:right_vals){
            cout<<x << " ";
        }

    }
    
}

void BotomView(Node *root){
    
}

Node *Delete_the_specific_Node(Node *root, int val){
    if(root==NULL){
        return root;
    }
    if(val < root->key){
        root->left = Delete_the_specific_Node(root->left, val);
    }
    else if(val > root->key){
        root->right = Delete_the_specific_Node(root->right, val);
    }
    else{
        if(root->left==NULL){
            Node *temp = root->right;
            free(root);
            return temp;
        }
        else if(root->right==NULL){
            Node *temp = root->left;
            free(root);
            return temp;
        }
        Node *temp = MinimumNode(root->left);
        root->key = temp->key;
        root->left = Delete_the_specific_Node(root->right, temp->key);

    }

    return root;
}

void choices(){
    cout<<"-----------------------------------------------\n";
    cout<<"1. Insert Node \t\t\t\t\t 7. Bottom View\n";
    cout<<"2. Delete Node \t\t\t\t\t 8. Top View\n";
    cout<<"3. Display Tree  \t\t\t\t 9. PostOrder\n";
    cout<<"4. Total Number of Nodes in Tree \t\t 10.LevelOrder\n";
    cout<<"5. Depth of Tree \t\t\t\t 11. Side View\n";
    cout<<"6. Maximum and Minimum Node from the tree\n";
    cout<<"12. Exit\n";
}
int main(){

int rootnode, val;
cout<<"Enter the root Node : ";
cin>>rootnode;
Node *root = CreateNewNode(rootnode);
choices();
int choice;
cout<<"\n choice ---->  \n";
cin>>choice;
while(choice!=12){
    if (choice==1){
        cout<<"\n Enter val : ";
        cin>>val;
        root = InsertNode(root, val);
    }
    else if(choice==2){
        cout<<"\nEnter Value you want to delete : ";
        int val;;
        cin>>val;
        root = Delete_the_specific_Node(root, val);
        cout<<endl;
    }
    else if(choice==3){
        cout<<endl;
        inorder(root);
        cout<<endl;
    }
    else if(choice==4){
        Node *totalnode = root;
        Node *externalnode = root;
        int t = number_of_nodes_in_tree(totalnode);
        int e =ExternalNodes(externalnode);
        cout<<"Total Number of Nodes in Tree : "<<t<<endl;
        cout<<"External Nodes : "<<e<<endl;
        cout<<"Total Number of Internal Nodes : "<<t-e<<endl;

    }
    else if(choice==5){
        int val = depth_of_bst(root);
        cout<<"Depth of BST : "<<val<<endl;
    }
    else if(choice==6){
        cout<<"Maximum Node : "<<MaximumNode(root)->key<<endl;
        cout<<"Minimum Node : "<<MinimumNode(root)->key<<endl;
    }
    else if(choice==8){
        TopView(root);
    }
    else if (choice==9){
        cout<<endl;
        postorder(root);
        cout<<endl;
    }
    else if(choice==10){
        cout<<endl;
        printlevelorder(root);
        cout<<endl;
    }
    else if(choice==2){
        continue;
    }
    choices();
    cout<<"\n choice ---->  \n";
    cin>>choice;
}




}
 //Number of Nodes in a Tree
 // External Node
 // Internal Nodes