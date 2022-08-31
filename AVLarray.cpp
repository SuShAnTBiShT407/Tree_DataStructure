#include<bits/stdc++.h>
using namespace std;

struct Node{

    int key;
    int height;
    Node *left;
    Node *right;
};
Node *CreateNode(int val){
    Node *new_node = new Node();
    new_node->key = val;
    new_node->left = NULL;
    new_node->right = NULL;
    new_node->height =1;
    return new_node;
}
int depth_of_tree(Node *root){
    int leftheight;
    int rightheight;
    if(root==NULL){
        return 0;
    }
    else{
        leftheight = depth_of_tree(root->left);
        rightheight = depth_of_tree(root->right);
        return max(leftheight, rightheight)+1;
    }
    return 0;
}

int height(Node *node){
    if(node==NULL){
        return 0;
    }
    return node->height;

}
int getBalance(Node *root){
    if(root==NULL){
        return 0;
    }
    return height(root->left) - height(root->right);
}
Node *RightRotation(Node *root){
    
    Node *q = root->left;
    Node *temp = q->right;
    q->right = root;
    root->left = temp;

    root->height = max(height(root->left), height(root->right)) + 1;
    q->height = max(height(q->left), height(q->right)) + 1;

    return q;
}
Node *LeftRotation(Node *root){

    Node *q = root->right;
    Node *temp = q->left;
    q->left = root;
    root->right = temp;

    root->height = max(height(root->left), height(root->right)) + 1;
    q->height = max(height(q->left), height(q->right)) + 1;

    return q;
}
Node *InsertNode(Node *root, int val){
    if(root==NULL){
        return CreateNode(val);
    }
    if(val < root->key){
        root->left = InsertNode(root->left, val);
    }
    else if(val > root->key){
        root->right = InsertNode(root->right, val);
    }
    else return root;

    // AVL Power

    root->height = 1+ max(height(root->left), height(root->right));
    int balance = getBalance(root);

    if(balance > 1 && val < root->left->key){
        return RightRotation(root);
    }
    if(balance < -1 && val > root->right->key){
        return LeftRotation(root);
    }
    if( balance > 1 && val > root->left->key){
        root->left = LeftRotation(root->left);
        return RightRotation(root);
    }

    if( balance < -1 && val < root->right->key){
        root->right = RightRotation(root->right);
        return LeftRotation(root);
    }
    return root;

}
void inorder(Node *root){
    if(root==NULL){return;}
    else{
        inorder(root->left);
        cout<<root->key<<" ";
        inorder(root->right);
    }
}
void menu(){
    cout<<"1. Insert Node\n";
    cout<<"2. Display TREE\n";
    cout<<"3. EXIT\n";
}

int main(){
    int rootnode;
    cout<<"Enter the root Node : ";
    cin>>rootnode;
    Node *root = CreateNode(rootnode);
    menu();
    cout<<"choice-> ";
    int choice;
    cin>>choice;
    while(choice!=3){
        if(choice==1){
            int val;
            cout<<"\nEnter the Node value : ";
            cin>>val;
            root = InsertNode(root, val);
            cout<<endl;
        }
        else if(choice==2){
            cout<<endl;
            cout<<"Tree : ";
            inorder(root);
            cout<<endl;
        }
        menu();
        cout<<"\nchoice - > ";
        cin>>choice;
    }
    
}
/*

q = right(p)
node = left(q)
left(q) = p
right(p) = node

*/