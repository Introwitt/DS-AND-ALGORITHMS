#include <iostream>
#include <algorithm>
using namespace std;

struct BST{
    int data;
    BST* left;
    BST* right;
};

// Create New Node
BST* createNode(int data){
    BST* node = new BST();
    node->data = data;
    node->left = NULL;
    node->right = NULL;
    return node;
}

// Insert Node
BST* insert(BST* root, int data){
    if(root==NULL){
        root = createNode(data);
    }
    else if(data<= root->data){
        root->left = insert(root->left, data);
    }
    else if(data> root->data){
        root->right = insert(root->right, data);
    }
    return root;
}

// Search for Node
bool search(BST* root, int data){
    if(root==NULL)
        return false;
    if(data == root->data){
        return true;
    }
    else if(data< root->data){
        return search(root->left, data);
    }
    else{
        return search(root->right, data);
    }
    
}

// Find Min Node
int findMin(BST* root){
    if(root->left==NULL)
        return root->data;
    else
        return findMin(root->left);
}

// Find Max Node
int findMax(BST* root){
    if(root->right==NULL)
        return root->data;
    else
        return findMax(root->right);
    
}

// Find Height
int findHeight(BST* root){
    if(root==NULL)
        return -1;
    else{
        return max(findHeight(root->left), findHeight(root->right)) + 1;
    }
}

// Main Function
int main() {
    // insert code here...
    BST* root = NULL; // Root node
    
    // Insert Nodes
    root = insert(root, 10);
    root = insert(root, 5);
    root = insert(root, 20);
    root = insert(root, 15);
    root = insert(root, 200);
    
    // Search for Node
    int n;
    cout<<"Enter the number you want to be searched";
    cin>>n;
    if(search(root,n)==true)
        cout<<"Found\n";
    else
        cout<<"Not found\n";
    
    // Find Height
    int height = findHeight(root);
    cout<<"Height = "<<height<<"\n";
    
    // Find Max and Min Node
    int min = findMin(root);
    int max = findMax(root);
    cout<<"Min Node = "<<min<<" and Max Node = "<<max<<"\n";
    return 0;
}

