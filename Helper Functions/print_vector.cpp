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