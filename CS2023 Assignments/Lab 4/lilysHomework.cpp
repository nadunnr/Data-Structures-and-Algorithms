#include <bits/stdc++.h>
#include <vector>
#include <algorithm>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);

/*
 * Complete the 'lilysHomework' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts INTEGER_ARRAY arr as parameter.
 */

void printArray(int n, vector<int> arr){

    for (int i=0; i<n; i++){
        cout <<arr[i]<<" ";
    }
    cout<<endl;
}


int swaps(const vector<int>& arr, const vector<int>& sorted_arr){

    int n = arr.size();
    vector<int> mismatches;

    for(int i=0; i<n; i++){
        if (arr[i] != sorted_arr[i]) mismatches.push_back(i);
    }
    int curr_id;
    float swaps = 0;
    int singles = 0;
    
    for (int i: mismatches){
        auto it = lower_bound(sorted_arr.begin(), sorted_arr.end(), arr[i]);
        size_t correct_pos= it - sorted_arr.begin();

        if (arr[correct_pos] == sorted_arr[i]){
            swaps += 0.5;
        }
        else {
            swaps ++;
            singles = 1;
        }
    }

    return int(swaps) - 1*(singles);
}


int lilysHomework(vector<int>& arr) {

    int n = arr.size();

    vector<int> reverse_arr;
    for(int j=n-1; j>=0; j--){
        reverse_arr.push_back(arr[j]);
    }

    vector<int> sorted_arr = arr;
    sort(sorted_arr.begin(), sorted_arr.end());
    int a = swaps(arr, sorted_arr);


    int b = swaps(reverse_arr, sorted_arr);

    if (a < b) {
        return a;
    }
    return b;
}

int main(){
    vector<int> test = {5,8,9,4,6,12,54,98,65,21,47,47,654,3,24,5,8,5,6,9564,31,454,21,954,1,54};
    vector<int> a = {2,1,4,3,7,5,6};
    int k= lilysHomework(a);
    cout<<k<<endl;
}

/*
int main()
{
    string n_temp;
    getline(cin, n_temp);

    int n = stoi(ltrim(rtrim(n_temp)));

    string arr_temp_temp;
    getline(cin, arr_temp_temp);

    vector<string> arr_temp = split(rtrim(arr_temp_temp));

    vector<int> arr(n);

    for (int i = 0; i < n; i++) {
        int arr_item = stoi(arr_temp[i]);

        arr[i] = arr_item;
    }

    int result = lilysHomework(arr);

    cout << result << "\n";
,,,
    return 0;
}

string ltrim(const string &str) {
    string s(str);

    s.erase(
        s.begin(),
        find_if(s.begin(), s.end(), not1(ptr_fun<int, int>(isspace)))
    );

    return s;
}

string rtrim(const string &str) {
    string s(str);

    s.erase(
        find_if(s.rbegin(), s.rend(), not1(ptr_fun<int, int>(isspace))).base(),
        s.end()
    );

    return s;
}

vector<string> split(const string &str) {
    vector<string> tokens;

    string::size_type start = 0;
    string::size_type end = 0;

    while ((end = str.find(" ", start)) != string::npos) {
        tokens.push_back(str.substr(start, end - start));

        start = end + 1;
    }

    tokens.push_back(str.substr(start));

    return tokens;
}
*/