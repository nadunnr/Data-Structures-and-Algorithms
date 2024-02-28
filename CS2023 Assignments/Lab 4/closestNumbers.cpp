#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);

/*
 * Complete the 'closestNumbers' function below.
 *
 * The function is expected to return an INTEGER_ARRAY.
 * The function accepts INTEGER_ARRAY arr as parameter.
 */
void printArray(const vector<int>& arr){

    int n = arr.size();

    for (int i=0; i<n; i++){
        cout <<arr[i]<<" ";
    }
    cout<<endl;
}

vector<int> closestNumbers(vector<int> arr) {

    vector<int> numbers = arr;

    int n = numbers.size();
    sort(numbers.begin(), numbers.end());

    int min_distance = numbers[1] - numbers[0];
    vector<int> closest_numbers = {numbers[0], numbers[1]};
    int dis;

    for (int i=2; i<n; i++){

        dis = numbers[i] - numbers[i-1];

        if(dis<min_distance) {
            min_distance=dis;
            closest_numbers.clear();
            closest_numbers.push_back(numbers[i-1]);
            closest_numbers.push_back(numbers[i]);
        }

        else if(dis==min_distance){
            closest_numbers.push_back(numbers[i-1]);
            closest_numbers.push_back(numbers[i]);
        }
    }

    return closest_numbers;
}

/*
int main(){
    vector<int> b = {1,5,6,4,9,10};
    vector<int> a = closestNumbers(b); 
    printArray(a);
}
*/

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

    vector<int> result = closestNumbers(arr);

    for (size_t i = 0; i < result.size(); i++) {
        cout << result[i];

        if (i != result.size() - 1) {
            cout << " ";
        }
    }

    cout << "\n";

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