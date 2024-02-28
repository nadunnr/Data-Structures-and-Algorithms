#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void printArray(const vector<int>& arr){

    int n = arr.size();

    for (int i=0; i<n; i++){
        cout <<arr[i]<<" ";
    }
    cout<<endl;
}

int binary_search(vector<int>& arr, int const l, int const r, int const x){

    // use the binary search on a sorted array
    if(l<=r){

        int mid = l + (r - l)/2;

        if (arr[mid] == x) return mid;
        else if (arr[mid] < x){
            return binary_search(arr, mid+1, r, x);
        }
        else{
            return binary_search(arr, l, mid-1, x);
        }
    }
    return -1;
}

void use_binary_search(vector<int>& arr, bool sorted, int x){

    if (!sorted){
        sort(arr.begin(), arr.end());
    }

    int n = arr.size();

    int position = binary_search(arr, 0, n-1, x);

    if (position==-1) cout<<"Not Found\n";
    else cout <<"Found at index: "<<position<<endl;
}

int main (){
    vector<int> arr = {42, 17, 25, 9, 33, 56, 72, 11, 8, 91, 5, 27, 63, 38, 14, 77, 20, 49, 3, 68,22, 41, 57, 13, 30}; 
    int n = arr.size();
    int x = 91;

    use_binary_search(arr, false, x); 
}