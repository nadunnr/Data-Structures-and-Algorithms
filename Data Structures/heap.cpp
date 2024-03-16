#include <iostream>
#include <vector>
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

    void heapify_up(int val){

        if (val>0 && heap[parent(val)] > heap[val]){
            swap(heap[parent(val)], heap[val]);
            val = parent(val);
        }
    }

    void heapify_down(int val){
        int smallest = val;
        int right = right_child(val);
        int left = left_child(val);

        if (left<heap.size() && heap[left] < heap[val]) smallest = left;
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

    int min(){
        if (!heap.empty()) return heap[0];
    }
};

int main(){
    MinHeap heap;

    // Insert elements into the heap
    heap.insert(10);
    heap.insert(7);
    heap.insert(15);
    heap.insert(3);
    heap.insert(6);

    // Delete an element from the heap
    heap.remove(10);

    // Perform heap sort
    heap.heapSort();

    // Print sorted elements
    cout << "Sorted elements: ";
    while (!heap.is_empty()) {
        cout << heap.min() << " ";
        heap.remove(heap.min());
    }
    cout << endl;

    return 0;

}