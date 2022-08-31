// Greater sum tree is a tree in which every node contains the sum of all the nodes which are greater than the node
#include<bits/stdc++.h>
using namespace std;

struct Node{
    int key;
    Node *left;
    Node *right;
};
int sum=0;
Node *CreateNode(int val){
    
    Node *new_node = new Node();
    new_node->key = val;
    new_node->left = NULL;
    new_node->right =NULL;
    return new_node;
}

Node *InsertNode(Node *root, int val)
{


    if (root == NULL)
    {
        root = CreateNode(val);
        return root;
    }
    if (val < root->key)
    {
        cout << "Root  " << root->key << " is greater so val goes to left \n";
        root->left = InsertNode(root->left, val);
        return root;
    }
    else if (val > root->key)
    {
        cout << "Root  " << root->key << " is smaller so val goes to right \n";
        root->right = InsertNode(root->right, val);
        return root;
    }
    return root;
}
void menu(){
    cout<<"\n1. Insert new node\n";
    cout<<"2. Greater Sum Tree\n";
    cout<<"3. Exit\n";
}
void GreaterSumTree(Node *root){
    if(root==NULL){
        return;
    }
    GreaterSumTree(root->right);
    int temp_key = root->key;
    root->key = sum;
    sum = sum+ temp_key;
    GreaterSumTree(root->left);

}
void inorder(Node *root){
    if(root==NULL) return;
    else{
        inorder(root->left);
        cout<<root->key<<" ";
        inorder(root->right);
    }
}
int main(){

    int rootnode, choice;
    cout<<"Enter Root Node : ";
    cin>>rootnode;
    Node *root  = CreateNode(rootnode);
    menu();
    cout<<"choice --> ";
    cin>>choice;
    while(choice!=3){
        if(choice==1){
            int val;
            cout<<"Enter the value of new node : ";
            cin>>val;
            cout<<endl;
            root = InsertNode(root, val);
            cout<<endl;
        }
        else if(choice==2){
            cout<<"Original Tree : ";
            inorder(root);
            cout<<endl;
            cout<<"Greater Sum Tree : ";
            GreaterSumTree(root);
            inorder(root);
            cout<<endl;
        }
        menu();
        cout<<"\nchoice --> ";
        cin>>choice;
    }

}