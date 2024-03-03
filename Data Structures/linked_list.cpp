#include <bits/stdc++.h>
using namespace std;

class Node{

public:
    int data;
    Node* next;

    //Constructors
    Node() 
    { 
        data = 0; 
        next = NULL; 
    } 

    Node(int a){
        data = a;
        next = NULL;
    }
};

class LinkedList{

private:
    Node* head;

public:
    LinkedList(){
        head = NULL;
    }

    void insert_node(int);
    void print_list();
    void delete_node(int);
};

void LinkedList::insert_node(int x){
    
    //creating a new node pointer
    Node* node_ptr = new Node(x);

    if (head == NULL){
        head = node_ptr;
        return;
    }

    Node* temp = head;

    while(temp->next != NULL){
        temp = temp->next;
    }

    temp->next = node_ptr;
}

void LinkedList::print_list(){

    Node* temp = head;

    while (temp != NULL){
        cout<<temp->data<<" ";
        temp = temp->next;
    }

    cout<<endl;
}

void LinkedList::delete_node(int y){

    if (head == NULL){
        cout <<"An empty list\n";
        return;
    }
    
    if (head->data == y){
        head = head->next;
        return;
    }

    Node* ptr = head;

    while (ptr -> next != NULL){
        if (ptr -> next -> data == y){
            ptr -> next = ptr->next->next;
            return;
        }
        ptr = ptr -> next; 
    }
}

int main(){

    LinkedList list;

    for (int i=1; i<11; i++){
        list.insert_node(pow(i,2));
    }

    list.print_list();
    list.delete_node(4);
    list.delete_node(49);
    list.delete_node(5);
    list.print_list();
}