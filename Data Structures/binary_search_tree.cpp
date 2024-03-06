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

        else if (node->data < value){
            node->left =  insert_node(node->left, value);
        }

        else if (node->data >= value){
            node->right = insert_node(node->right, value);
        }

        return node;
    }

public:
    BinarySearchTree(){
        root = nullptr;
    }

    bool is_empty();

    void insert(int value){
        root = insert_node(root, value);
    }

    int search(int);
    bool delete_node(int);
    void travers();
};

bool BinarySearchTree::is_empty(){
    if (root == nullptr) return true;
    else return false;
}