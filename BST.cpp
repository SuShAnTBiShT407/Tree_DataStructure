#include <bits/stdc++.h>
#include <cmath>
using namespace std;

struct Node
{
    int key;
    int hd;
    Node *left;
    Node *right;
};

int hd = 0;
// Creates new node in tree
Node *CreateNewNode(int val)
{
    Node *new_node = new Node();
    new_node->key = val;
  
    new_node->left = new_node->right = NULL;
    return new_node;
}

// Insert New elements to the tree
Node *InsertNode(Node *root, int val)
{

    if (root == NULL)
    {
        root = CreateNewNode(val);
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

// Finding the Minimum Node from the tree
Node *MinimumNode(Node *root)
{
    Node *node = root;
    while (node->left != NULL && node)
        node = node->left;
    return node;
}

// Finding the maximum Node from the tree
Node *MaximumNode(Node *root)
{
    Node *node = root;
    while (node->right != NULL && node)
        node = node->right;
    return node;
}
// Inorder tranversal
void inorder(Node *root)
{
    if (root != NULL)
    {
        inorder(root->left);
        cout << root->key << " ";
        inorder(root->right);
    }
}

// Finding the Depth of BST
int depth_of_bst(Node *root)
{
    int leftHeight;
    int rightTheight;
    if (root == NULL)
    {
        return 0;
    }
    else
    {
        leftHeight = depth_of_bst(root->left);
        rightTheight = depth_of_bst(root->right);
        return max(leftHeight, rightTheight) + 1;
    }
}
void levelorder(Node *root, int level)
{
    if (root == NULL)
    {
        return;
    }
    if (level == 1)
    {
        cout << root->key << " ";
    }
    else
    {
        levelorder(root->left, level - 1);
        levelorder(root->right, level - 1);
    }
}
void printlevelorder(Node *root)
{
    int height = depth_of_bst(root);
    for (int i = 1; i <= height; i++)
        levelorder(root, i);
}

void postorder(Node *root)
{
    if (root != NULL)
    {
        postorder(root->left);
        postorder(root->right);
        cout << root->key << " ";
    }
}

// Counting Total Numbers of Nodes in the Left Sub tree
int countLeft(Node *root)
{
    int n = 0;
    while (root->left != NULL)
    {
        n += 1;
        root = root->left;
    }
    return n;
}

// Counting Total Numbers of Nodes in the Left Sub tree
int countRight(Node *root)
{
    int n = 0;
    while (root->right != NULL)
    {
        n += 1;
        root = root->right;
    }

    return n;
}

// Total Number of External Nodes int he tree
int ExternalNodes(Node *root)
{
    int l, r;
    if (root == NULL)
    {
        return 0;
    }
    else
    {
        l = countLeft(root);
        r = countRight(root);
        return 1 + l + r;
    }
}

// toatl Numbers of Nodes in the Tree

int number_of_nodes_in_tree(Node *node)
{
    if (node == NULL)
        return 0;

    return 1 + number_of_nodes_in_tree(node->left) + number_of_nodes_in_tree(node->right);
}


void TopView(Node *root)
{
    if(root==NULL){
        return;
    }

    Node *temp = root;
    queue<pair<Node*, int>> q;
    map<int, int> mp;
    q.push({root, 0});
    while(!q.empty()){
        
        temp = q.front().first;
        int d = q.front().second;
        q.pop();

        if(mp.find(d)==mp.end()){
            cout<<temp->key<<" ";
            mp[d] = temp->key;
        }

        if(temp->left){
            q.push({temp->left, d-1});
        }
        if(temp->right){
            q.push({temp->right, d+1});
        }

    }



}


void BotomView(Node *root)
{
    unordered_map<int, vector<int>> map;
    vector<int> temp;
    if(root==NULL){
        return;
    }
    queue<int> q;
    Node *temp_node = root;
    while(temp_node!=NULL){
        cout<<temp_node->key<<" ";

    }

}

Node *Delete_the_specific_Node(Node *root, int val)
{
    if (root == NULL)
    {
        return root;
    }
    if (val < root->key)
    {
        root->left = Delete_the_specific_Node(root->left, val);
    }
    else if (val > root->key)
    {
        root->right = Delete_the_specific_Node(root->right, val);
    }
    else
    {
        if (root->left == NULL)
        {
            Node *temp = root->right;
            free(root);
            return temp;
        }
        else if (root->right == NULL)
        {
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

void choices()
{
    cout << "-----------------------------------------------\n";
    cout << "1. Insert Node \t\t\t\t\t 7. Bottom View\n";
    cout << "2. Delete Node \t\t\t\t\t 8. Top View\n";
    cout << "3. Display Tree  \t\t\t\t 9. PostOrder\n";
    cout << "4. Total Number of Nodes in Tree \t\t 10.LevelOrder\n";
    cout << "5. Depth of Tree \t\t\t\t 11. Side View\n";
    cout << "6. Maximum and Minimum Node from the tree\n";
    cout << "12. Exit\n";
}
int main()
{

    int rootnode, val;
    cout << "Enter the root Node : ";
    cin >> rootnode;
    Node *root = CreateNewNode(rootnode);
    choices();
    int choice;
    cout << "\n choice ---->  \n";
    cin >> choice;
    while (choice != 12)
    {
        if (choice == 1)
        {
            cout << "\n Enter val : ";
            cin >> val;
            root = InsertNode(root, val);
        }
        else if (choice == 2)
        {
            cout << "\nEnter Value you want to delete : ";
            int val;
            ;
            cin >> val;
            root = Delete_the_specific_Node(root, val);
            cout << endl;
        }
        else if (choice == 3)
        {
            cout << endl;
            inorder(root);
            cout << endl;
        }
        else if (choice == 4)
        {
            Node *totalnode = root;
            Node *externalnode = root;
            int t = number_of_nodes_in_tree(totalnode);
            int e = ExternalNodes(externalnode);
            cout << "Total Number of Nodes in Tree : " << t << endl;
            cout << "External Nodes : " << e << endl;
            cout << "Total Number of Internal Nodes : " << t - e << endl;
        }
        else if (choice == 5)
        {
            int val = depth_of_bst(root);
            cout << "Depth of BST : " << val << endl;
        }
        else if (choice == 6)
        {
            cout << "Maximum Node : " << MaximumNode(root)->key << endl;
            cout << "Minimum Node : " << MinimumNode(root)->key << endl;
        }
        else if (choice == 8)
        {
            cout<<endl;
            cout<<"TOP VIEW ::  ";
            TopView(root);
            cout<<endl;
        }
        else if (choice == 9)
        {
            cout << endl;
            postorder(root);
            cout << endl;
        }
        else if (choice == 10)
        {
            cout << endl;
            printlevelorder(root);
            cout << endl;
        }
        choices();
        cout << "\n choice ---->  \n";
        cin >> choice;
    }
}
// Number of Nodes in a Tree
//  External Node
//  Internal Nodes