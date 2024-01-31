#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);

/*
 * Complete the 'insertionSort1' function below.
 *
 * The function accepts following parameters:
 *  1. INTEGER n
 *  2. INTEGER_ARRAY arr
 */

void printArray(int n, vector<int> arr){

    //iterating over loops
    for (int i=0; i<n; i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}

void insertionSort1(int n, vector<int> arr) {
    
    for (int i=1; i<n; i++){
        int j = i;
        int key = arr[i]; 
        bool swapped = false;
        
        while (j>0 && arr[j-1] > key){
            swapped = true;
            arr[j] = arr[j-1];
            printArray(n, arr);
            j--;
        }
        
        if (swapped){
            arr[j] = key;
            printArray(n, arr);
        }
    }
}

int main()
{
    //int n = 5;
    //vector <int> arr{9,1,2,3,4};
    //insertionSort1(n, arr);

    return 0;
}

