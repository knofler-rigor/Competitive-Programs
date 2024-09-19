#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);



/*
 * Complete the 'countMax' function below.
 *
 * The function is expected to return a LONG_INTEGER.
 * The function accepts STRING_ARRAY upRight as parameter.
 */

long countMax(vector<string> upRight) {
    long long minRow = numeric_limits<long long>::max();
    long long minCol = numeric_limits<long long>::max();

    for (const string& coord : upRight) {
        stringstream ss(coord);
        long long r, c;
        ss >> r >> c;

        minRow = min(minRow, r);
        minCol = min(minCol, c);
    }

    return minRow * minCol;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string upRight_count_temp;
    getline(cin, upRight_count_temp);

    int upRight_count = stoi(ltrim(rtrim(upRight_count_temp)));

    vector<string> upRight(upRight_count);

    for (int i = 0; i < upRight_count; i++) {
        string upRight_item;
        getline(cin, upRight_item);

        upRight[i] = upRight_item;
    }

    long result = countMax(upRight);

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

    return s;
}
