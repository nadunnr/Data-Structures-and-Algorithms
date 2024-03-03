#include <bits/stdc++.h>
#include <vector>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);

/*
 * Complete the 'twoStacks' function below.
 
 * The function is expected to return an INTEGER.
 * The function accepts following parameters:
 *  1. INTEGER maxSum
 *  2. INTEGER_ARRAY a
 *  3. INTEGER_ARRAY b
 */

int twoStacks(int maxSum, vector<int> a, vector<int> b) {
    
    int i=0, j=0, k=0;
    int sum=0;
    int n_a = a.size();
    int n_b = b.size();
    
    while (i<n_a && sum+a[i] <= maxSum){
        sum += a[i];
        i++;
    }
    
    k = i;

    while (j < n_b && i>-1){
        sum += b[j];
        j++;
        
        while(sum>maxSum && i>0){
            i += -1;
            sum = sum - a[i];
        }
        
        if (sum <= maxSum && k < i+j){
            k = i+j;
        }
    }
    
    return k;
}
 
int twoStacks(int maxSum, vector<int> a, vector<int> b) {
    
    int i=0, j=0, k=0;
    int sum=0;
    int n_a = a.size();
    int n_b = b.size();

    while(i<n_a && j<n_b){

        if (a[i] <= b[j]){
            if (sum+a[i] <=  maxSum) {
                sum += a[i];
                i++;
                k++;
            }
            else return k;
        }
        else{
            if (sum+b[j] <=  maxSum) {
                sum += b[j];
                j++;
                k++;
            }
            else return k;
        }
    }

    while (i<n_a){
        if (sum+a[i] <= maxSum){
            sum += a[i];
            i++;
            k++;
        }
        else return k;
    }

    while (j<n_b){
        if (sum+b[j] <= maxSum){
            sum += b[j];
            j++;
            k++;
        }
        else return k;
    }

    return k;
}

int main(){
    vector<int> a = {4, 2, 4, 6, 1};
    vector<int> b = {2, 1, 8, 5};
    int max = 10;

    cout<<twoStacks(max,a,b)<<endl;

}

/*
int main()
{

    string g_temp;
    getline(cin, g_temp);

    int g = stoi(ltrim(rtrim(g_temp)));

    for (int g_itr = 0; g_itr < g; g_itr++) {
        string first_multiple_input_temp;
        getline(cin, first_multiple_input_temp);

        vector<string> first_multiple_input = split(rtrim(first_multiple_input_temp));

        int n = stoi(first_multiple_input[0]);

        int m = stoi(first_multiple_input[1]);

        int maxSum = stoi(first_multiple_input[2]);

        string a_temp_temp;
        getline(cin, a_temp_temp);

        vector<string> a_temp = split(rtrim(a_temp_temp));

        vector<int> a(n);

        for (int i = 0; i < n; i++) {
            int a_item = stoi(a_temp[i]);

            a[i] = a_item;
        }

        string b_temp_temp;
        getline(cin, b_temp_temp);

        vector<string> b_temp = split(rtrim(b_temp_temp));

        vector<int> b(m);

        for (int i = 0; i < m; i++) {
            int b_item = stoi(b_temp[i]);

            b[i] = b_item;
        }

        int result = twoStacks(maxSum, a, b);

        cout << result << "\n";
    }

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
