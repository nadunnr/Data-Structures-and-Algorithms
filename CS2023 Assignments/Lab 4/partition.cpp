#include <iostream>
#include <sstream>
#include <vector>
using namespace std;

vector<int> mergeVectors(vector<int>& vec1, vector<int>& vec2, vector<int>& vec3) {
    //merge 3 vectors and outputs

    vector<int> result;

    result.reserve(vec1.size() + vec2.size() + vec3.size());

    // Concatenate vec1, vec2, and vec3
    result.insert(result.end(), vec1.begin(), vec1.end());
    result.insert(result.end(), vec2.begin(), vec2.end());
    result.insert(result.end(), vec3.begin(), vec3.end());

    return result;
}

void printArray(int n, vector<int> arr){

    for (int i=0; i<n; i++){
        cout <<arr[i]<<" ";
    }
    cout<<endl;
}

vector<int> partition(int n, vector<int> arr){
    
    int pivot = arr[0];
    vector<int> left;
    vector<int> right;
    vector<int> equal = {pivot};
    
    for (int i=1; i<n; i++){
        if (arr[i] < pivot) left.push_back(arr[i]);
        else if (arr[i] > pivot) right.push_back(arr[i]);
        else equal.push_back(arr[i]);
    }
    
    vector<int> result = mergeVectors(left, equal, right);
    return result;
}

int main(){
    int n, temp;
    vector<int> arr;
    
    cin >> n;
    int k=0;
    
    string input;
    getline(cin, input);
    istringstream iss(input);
    
    while(cin >> temp){
        arr.push_back(temp);
        k++;
        if (k==n) break;
    }
    
    vector<int> ar = partition(n, arr);
    printArray(n, ar);
}