#include <iostream>
#include <vector>

using namespace std;

void printArray(const vector<int>& arr){

    int n = arr.size();

    for (int i=0; i<n; i++){
        cout <<arr[i]<<" ";
    }
    cout<<endl;
}

void merge(vector<int>& arr, int const left, int const mid, int const right){

    int n1 = mid - left + 1;
    int n2 = right - mid;

    vector<int> left_arr;
    vector<int> right_arr;

    for (int a=0; a<n1; a++){
        left_arr.push_back(arr[left+a]);
    }

    for (int b=0; b<n2; b++){
        right_arr.push_back(arr[mid+1+b]);
    }

    int i=0, j=0, k=left;

    while (i<n1 && j<n2){
        if (left_arr[i] <= right_arr[j]){
            arr[k] = left_arr[i];
            i++;
        }
        else {
            arr[k] = right_arr[j];
            j++;
        }

        k++;
    }

    while (i<n1) {
        arr[k] = left_arr[i];
        i++;
        k++;
    }

    while (i<n2) {
        arr[k] = right_arr[j];
        j++;
        k++;
    }

}

void merge_sort(vector<int>& arr, int const left, int const right){

    if (left >= right) return;

    int mid = left + (right-left)/2;

    merge_sort(arr, left, mid);
    merge_sort(arr, mid+1, right);
    merge(arr, left, mid, right);
}

int main (){

    vector<int> arr = {42, 17, 25, 9, 33, 56, 72, 11, 8, 91, 5, 27, 63, 38, 14, 77, 20, 49, 3, 68,22, 41, 57, 13, 30}; 
    int n = arr.size();
    merge_sort(arr,0, n-1);
    printArray(arr);
}