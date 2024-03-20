#include <bits/stdc++.h>
#include <string>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);

/*
 * Complete the 'twoStrings' function below.
 *
 * The function is expected to return a STRING.
 * The function accepts following parameters:
 *  1. STRING s1
 *  2. STRING s2
 */

string twoStrings(string s1, string s2) {
    
    bool flag_same_str = false;
    
    int n1 = s1.length();
    int n2 = s2.length();
    
    for (int i=0; i<n1; i++){
        for(int j=0; j<n2; j++){
            if (s1[i]==s2[j]){
                flag_same_str = true;
                break;
            }
        }
    }
    
    if (flag_same_str){
        return "YES";
    }
    else{
        return "NO";
    }
}

int main()
{
    string q_temp;
    getline(cin, q_temp);

    int q = stoi(ltrim(rtrim(q_temp)));

    for (int q_itr = 0; q_itr < q; q_itr++) {
        string s1;
        getline(cin, s1);

        string s2;
        getline(cin, s2);

        string result = twoStrings(s1, s2);

        cout << result << "\n";
    }

    return 0;
}

