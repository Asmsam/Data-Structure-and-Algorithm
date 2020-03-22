#include <iostream>
using namespace std;

struct Node {
    unsigned char data;
    struct Node* left;
    struct Node* right;
};

class TreeOrder {
    public:
    void PreOrder ( struct Node* root );
    void InOrder ( struct Node* root );
    void PostOrder ( struct Node* root );
};

class TreeOperations : public TreeOrder {
    public:
    void InsertNode ( struct Node* root, unsigned char data );
    void DeleteNode ( struct Node* root );
};

void TreeOrder::PreOrder ( struct Node* root ) {
    if ( root != NULL ) {
        std::cout << root->data << "\n";
        PreOrder ( root->left );
        PreOrder ( root->right );
    }
}

void TreeOrder::InOrder ( struct Node* root ) {
    if ( root != NULL ) {
        PreOrder ( root->left );
        std::cout << root->data << "\n";
        PreOrder ( root->right );
    }
}

void TreeOrder::PostOrder ( struct Node* root ) {
    if ( root != NULL ) {
        PreOrder ( root->left );
        PreOrder ( root->right );
        std::cout << root->data << "\n";
    }
}

void TreeOperations::InsertNode ( struct Node* root, unsigned char data ) {
    if ( data < root->data ) {
        if ( root->left == NULL ) InsertNode ( root->left, data );
        else {
            root->left = new struct Node;
            (root->left)->data = data;
            (root->left)->left = NULL;
            (root->left)->right = NULL;
        }
    }
    else if ( data >= root->data ) {
        if ( root->right == NULL ) InsertNode ( root->right, data );
        else {
            root->right = new struct Node;
            (root->right)->data = data;
            (root->right)->left = NULL;
            (root->right)->right = NULL;
        }
    }
}

void TreeOperations::DeleteNode ( struct Node* root ) {
    if ( root != NULL ) {
        DeleteNode ( root->left );
        DeleteNode ( root->right );
        delete root;
    }
}
