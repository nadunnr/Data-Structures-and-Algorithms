#include <iostream>
#include <vector>

using namespace std;

class MinHeap{

private:

    vector<int> heap;

    int parent(int index){
        return (index-1)/2 ; 
    }

    int left_child(int id){
        return 2*id + 1;
    }

    int right_child(int id){
        return 2*id + 2;
    }

    void heapify_up(int val){

        if (val>0 && heap[parent(val) > heap[val]]){
            swap(heap[parent(val)], heap[val]);
            val = parent(val);
        }
    }

    void heapify_down(int val){
        int smallest = val;
        int right = right_child(val);
        int left = left_child(val);

        if (left<heap.size() && heap[left] < heap[val]{
            smallest = left;
        })
        if (right<heap.size() && heap[right] < heap[val]) smallest = right;

        if (smallest != val){
            swap(heap[smallest], heap[val]);
            heapify_down(smallest);
        }
    }

public:

    void insert(int data){
        heap.push_back(data);
        heapify_up(heap.size()-1);
    }

    void remove(int data){
        
    }

};