#include <iostream>
#include <vector>
#include <string>
#include <sstream>

using namespace std;

vector<int> get_input_line_to_vector(){

    string line;
    vector<int> numbers;
    int temp;

    getline(cin, line);

    stringstream s_stream(line);

    while (s_stream >> temp){
        numbers.push_back(temp);
    }
    
    return numbers;
}


/*
void printArray(const vector<int>& arr){

    int n = arr.size();

    for (int i=0; i<n; i++){
        cout <<arr[i]<<" ";
    }
    cout<<endl;
}

int main(){

    cout <<"Enter the space separated numbers: \n";
    vector<int> arr = get_input_line_to_vector();

    printArray(arr);
}
*/