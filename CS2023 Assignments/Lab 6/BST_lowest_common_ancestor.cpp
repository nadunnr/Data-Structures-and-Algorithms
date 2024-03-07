#include <bits/stdc++.h>
#include <string>
#include <iostream>
#include <sstream>
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

    Node* findLCA(Node* root, int value1, int value2) {
        if (root == nullptr) {
            return nullptr;
        }

        if (root->data > value1 && root->data > value2) {
            return findLCA(root->left, value1, value2);
        } else if (root->data < value1 && root->data < value2) {
            return findLCA(root->right, value1, value2);
        } else {
            return root;
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

    int lowest_common_ancestor(int value1, int value2) { 
        Node* lca =  findLCA(root, value1, value2);
        return lca -> data;
    }
};

int main(){

    int n, temp, a, b;
    string line;
    BinarySearchTree bst;
    
    cin >>n;

    for (int i=0; i<n; i++){
        cin>>temp;
        bst.insert(temp);
    }

    cin >>a>>b;

    int lca= bst.lowest_common_ancestor(a, b);
    cout<<lca<<endl;
}