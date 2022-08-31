#include <bits/stdc++.h>
#include <cmath>
using namespace std;

template <class T>
struct Node
{
    T key;
    Node *left;
    Node *right;

    Node(T val)
    {
        key = val;
        left = right = NULL;
    }
};

template <class T>
class BST_tree
{

private:
    Node<T> *root;
    Node<T> *insert(T val, Node<T> *temp)
    {
        if (temp == NULL)
        {
            temp = new Node<T>(val);
        }
        else if (val < temp->key)
        {
            temp->left = insert(val, temp->left);
        }
        else if (val > temp->key)
        {
            temp->right = insert(val, temp->right);
        }
        return temp;
    }

    void inorder(Node<T> *root)
    {
        if (root != NULL)
        {
            inorder(root->left);
            cout << root->key << "  ";
            inorder(root->right);
        }
    }
    Node<T> *MinimumNode(Node<T> *root)
    {
        Node *node = root;
        while (node->left != NULL && node)
            node = node->left;
        return node;
    }
    Node<T> *Delete_the_specific_Node(Node<T> *root, T val)
    {

        if (root == NULL)
        {
            return root;
        }
        if (val < root->key)
        {
            root->left = Delete_the_specific_Node(root->left, val);
        }
        else if (val < root->key)
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
            else if (root->right)
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

public:
    BST_tree()
    {
        root = NULL;
    }
    void insert(T val)
    {
        root = insert(val, root);
    }

    void inorder()
    {
        cout << "Root Data : " << root->key << endl;
        inorder(root);
    }

    ~BST_tree()
    {
        delete root;
    }
};

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
void choice_insert()
{
    cout << "---------------------------------\n";
    cout << "Type Of dtype : \n";
    cout << "1. INTEGER dtype \n";
    cout << "2. CHARACTER dtype\n";
    cout << "3. FLOAT dtype\n";
    cout << "---------------------------------------\n";
}

void Display()
{
    cout << "---------------------------------\n";
    cout << "1. Insert Node \n";
    cout << "2. Inorder \n";
    cout << "3. Preorder\n";
    cout << "4. Postorder\n";
    cout<<"5. Delete Node\n";
    cout<<"6. Minimum Node\n";
    cout<<"7. Maximum Node\n";
    cout << "8. Exit\n";
    cout << "---------------------------------------\n";
}

void IntergerDtype()
{

    BST_tree<int> tree;
    int rootnode;
    cout << "Enter the root node :  ";
    cin >> rootnode;
    tree.insert(rootnode);
    int choice;
    Display();
    cout << "choice--> ";
    cin >> choice;
    while (choice != 5)
    {
        if (choice == 1)
        {
            int val;
            cout << endl;
            cout << "Enter value - > ";
            cin >> val;
            tree.insert(val);
            cout << endl;
        }
        else if (choice == 2)
        {
            cout << endl;
            cout << "Inorder T : ";
            tree.inorder();
            cout << endl;
        }
        Display();
        cout << "choice--> ";
        cin >> choice;
    }
}
void CharacterDtype()
{

    BST_tree<char> tree;
    char rootnode;
    cout << "Enter the root node :  ";
    cin >> rootnode;
    tree.insert(rootnode);
    int choice;
    Display();
    cout << "choice--> ";
    cin >> choice;
    while (choice != 5)
    {
        if (choice == 1)
        {
            char val;
            cout << endl;
            cout << "Enter value - > ";
            cin >> val;
            tree.insert(val);
            cout << endl;
        }
        else if (choice == 2)
        {
            cout << endl;
            cout << "Inorder T : ";
            tree.inorder();
            cout << endl;
        }
        Display();
        cout << "choice--> ";
        cin >> choice;
    }
}
void FloatDtype()
{

    BST_tree<float> tree;
    float rootnode;
    cout << "Enter the root node :  ";
    cin >> rootnode;
    tree.insert(rootnode);
    int choice;
    Display();
    cout << "choice--> ";
    cin >> choice;
    while (choice != 5)
    {
        if (choice == 1)
        {
            float val;
            cout << endl;
            cout << "Enter value - > ";
            cin >> val;
            tree.insert(val);
            cout << endl;
        }
        else if (choice == 2)
        {
            cout << endl;
            cout << "Inorder T : ";
            tree.inorder();
            cout << endl;
        }
        Display();
        cout << "choice--> ";
        cin >> choice;
    }
}

int main()
{
    choice_insert();
    int choice;
    cout << "choice --> ";
    cin >> choice;
    switch (choice)
    {
    case 1:
        IntergerDtype();
        break;
    case 2:
        CharacterDtype();
        break;

    case 3:
        FloatDtype();
        break;
    case 4:
        break;
    }
}