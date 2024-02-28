#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);

/*
 * Complete the 'powerSum' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts following parameters:
 *  1. INTEGER X
 *  2. INTEGER N
 */
int expressions(int X, int N, vector<int>& vals){
    
    int sum = 0;
    
    if (sum == X){
        return 1;
    }

    else{
        int num_expressions = 0;
        int v;

        if (vals.empty()){
            v = 1;
        }
        else {
            v = vals.back() + 1;
        }

        while(sum + pow(v, N) <= X){
            vals.push_back(v);
            num_expressions += expressions(X,N, vals);
            vals.pop_back();
            v++;
        }

        return num_expressions;
    }
}

int powerSum(int X, int N) {
    
    vector<int> values;    
    int num_expressions = expressions(X, N, values);
    return num_expressions;    
}

int main(){
    int X = 10, N = 2;
    cout << powerSum(X, N)<<endl;
}

/*
int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string X_temp;
    getline(cin, X_temp);

    int X = stoi(ltrim(rtrim(X_temp)));

    string N_temp;
    getline(cin, N_temp);

    int N = stoi(ltrim(rtrim(N_temp)));

    int result = powerSum(X, N);

    fout << result << "\n";

    fout.close();

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

    return s;}*/