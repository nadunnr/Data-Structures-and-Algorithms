#include <bits/stdc++.h>
using namespace std;

class Node{
    int data;
    Node* left = nullptr;
    Node* right = nullptr;
};

class BST{

private: 
    Node* root = nullptr;

public:
    BST(){
        root = NULL;
    }

    void insert_node(int);
    bool is_empty();
    int search(int);
    bool delete_node(int);
    void travers();

};

bool BST::is_empty(){
    if (root == nullptr) return true;
    else return false;
}

