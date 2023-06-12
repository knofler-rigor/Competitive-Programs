#include <bits/stdc++.h>
using namespace std;
string ltrim(const string &);
string rtrim(const string &);

string findSubstring(const string& s, int k) {
    int j = k;
    int mx = 0;
    int count = 0;
    string max_sub = "";
    int ln = s.length();
    int i = 0;

    for (char c : s.substr(0, j)) {
        if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u') {
            count++;
        }
    }

    if (count != 0) {
        mx = count;
        max_sub = s.substr(0, j);
    }

    i = 0;

    while (j < ln - 1) {
        if (s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u') {
            if (count != 0) {
                count--;
            }
        }
        i++;

        if (s[j] == 'a' || s[j] == 'e' || s[j] == 'i' || s[j] == 'o' || s[j] == 'u') {
            count++;
        }

        j++;

        if (count > mx) {
            mx = count;
            max_sub = s.substr(i, j - i);
        }
    }

    if (max_sub == "") {
        return "Not found!";
    } else {
        return max_sub;
    }
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string s;
    getline(cin, s);

    string k_temp;
    getline(cin, k_temp);

    int k = stoi(ltrim(rtrim(k_temp)));

    string result = findSubstring(s, k);

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
