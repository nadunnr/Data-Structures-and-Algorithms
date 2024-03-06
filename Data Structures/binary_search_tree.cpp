#include <bits/stdc++.h>
using namespace std;

class Node{

public:
    int data;
    Node* left = nullptr;
    Node* right = nullptr;

    Node(int data) : data(data), left(nullptr), right(nullptr) {}
};

class BinarySearchTree{

private: 
    Node* root;

    Node* insert_node(Node* node, int value){

        if (node == nullptr){
            return new Node(value);
        }

        else if (node->data > value){
            node->left =  insert_node(node->left, value);
        }

        else if (node->data <= value){
            node->right = insert_node(node->right, value);
        }

        return node;
    }

    bool search_node(Node* node,int value){

        if (node == nullptr){
            return false;
        }

        else if (node->data == value){
            return true;
        }

        else if (node->data > value){
            return search_node(node->left, value);
        }

        else if (node->data < value){
            return search_node(node->right, value);
        }
    }

    void inorder_traversal(Node* node){
        
        if (node != nullptr){

            inorder_traversal(node->left);
            cout <<node->data<<" ";
            inorder_traversal(node->right);
        }
    }

    void preorder_traversal(Node* node){
        
        if (node != nullptr){
            cout <<node->data<<" ";
            preorder_traversal(node->left);
            preorder_traversal(node->right);
        }
    }

    void postorder_traversal(Node* node){
        
        if (node != nullptr){

            postorder_traversal(node->left);
            postorder_traversal(node->right);
            cout <<node->data<<" ";
        }
    }

public:
    BinarySearchTree(){
        root = nullptr;
    }

    bool is_empty();

    void insert(int value){
        root = insert_node(root, value);
    }

    Node* return_root(Node* node){
        return root;
    }

    bool search(int val){
        return search_node(root, val);
    }

    void traversal(string mode){

        if (mode == "inorder") inorder_traversal(root);
        else if (mode == "preorder") preorder_traversal(root);
        else if (mode == "postorder") postorder_traversal(root);
        cout<<endl;
    }

    bool delete_node(int);
    
};

bool BinarySearchTree::is_empty(){
    if (root == nullptr) return true;
    else return false;
}


int main(){
    BinarySearchTree BST;

    BST.insert(4);
    BST.insert(1);
    BST.insert(6);
    BST.insert(7);

    cout<<BST.is_empty()<<endl;
    cout<<BST.search(1)<<endl;
    cout<<BST.search(4)<<endl;
    cout<<BST.search(6)<<endl;
    cout<<BST.search(7)<<endl;
    cout<<BST.search(9)<<endl;
    BST.traversal("inorder");
}