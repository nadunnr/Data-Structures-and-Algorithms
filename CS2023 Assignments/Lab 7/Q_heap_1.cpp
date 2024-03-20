#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
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

    void heapify_up(int val) {
    while (val > 0 && heap[parent(val)] > heap[val]) {
        swap(heap[parent(val)], heap[val]);
        val = parent(val); 
    }
}

    void heapify_down(int val){
        int smallest = val;
        int right = right_child(val);
        int left = left_child(val);
        int len = heap.size();

        if (left<len && heap[left] < heap[smallest]) {
            smallest = left;
        }
        if (right<len && heap[right] < heap[smallest]){
            smallest = right;
        }
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

    void remove(int value) {
        auto it = find(heap.begin(), heap.end(), value);
        if (it == heap.end()) {
            throw out_of_range("Element not found in heap");
        }
        int index = it - heap.begin();
        heap[index] = heap.back();
        heap.pop_back();
        heapify_down(index);
    }

    void heapify() {
        for (int i = heap.size() / 2 - 1; i >= 0; i--) {
            heapify_down(i);
        }
    }

    // Perform heap sort
    void heapSort() {
        heapify();
        vector<int> sorted;
        while (!heap.empty()) {
            sorted.push_back(heap[0]);
            heap[0] = heap.back();
            heap.pop_back();
            heapify_down(0);
        }
        heap = sorted;
    }

    bool is_empty(){
        return heap.empty();
    }

    int getMin() {
        if (heap.empty()) {
            throw out_of_range("Heap is empty");
        }

        return heap.front();
    }
};

int main(){
    MinHeap heap;

    int n, temp, k;
    cin>>n;
    
    for (int i=0; i<n; i++){
        cin>>temp;
        if (temp==3){
            cout <<heap.getMin()<<endl;
        }
        
        else if (temp==1) {
            cin>>k;
            heap.insert(k);
        }
        
        else if (temp==2) {
            cin>>k;
            heap.remove(k);
        }
    }   
    
    return 0;

}
