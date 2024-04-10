#include <bits/stdc++.h>
#include <string>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);

/*
 * Complete the 'dayOfProgrammer' function below.
 *
 * The function is expected to return a STRING.
 * The function accepts INTEGER year as parameter.
 */

string dayOfProgrammer(int year) {

    string day_of_programmer;

    if (1700 <= year && year<=1917){
        if (year%4 ==0) day_of_programmer = "12.09." + to_string(year);
        else day_of_programmer = "13.09." + to_string(year);
    }
    else if (year==1918){
        day_of_programmer = "26.09.1918";
    }
    else if (1919 <= year && year<=2700){
        if (year%400==0) day_of_programmer = "12.09." + to_string(year);
        else if (year%4==0 && year%100 != 0) day_of_programmer = "12.09." + to_string(year);
        else day_of_programmer = "13.09." + to_string(year);
    }

    return day_of_programmer;
}

int main()
{
    string year_temp;
    getline(cin, year_temp);

    int year = stoi(ltrim(rtrim(year_temp)));

    string result = dayOfProgrammer(year);

    cout << result << "\n";

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
