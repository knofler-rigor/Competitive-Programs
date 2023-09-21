#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);



long taskOfPairing(const vector<long> freq) {
    long count = 0;
    bool marker = false;

    for (long i : freq) {
        if (i != 0) {
            count += i / 2;
            if (i % 2 != 0 && marker) {
                count += 1;
                marker = false;
            } else if (i % 2 != 0) {
                marker = true;
            }
        } else {
            marker = false;
        }
    }

    return count;
}
int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string freq_count_temp;
    getline(cin, freq_count_temp);

    int freq_count = stoi(ltrim(rtrim(freq_count_temp)));

    vector<long> freq(freq_count);

    for (int i = 0; i < freq_count; i++) {
        string freq_item_temp;
        getline(cin, freq_item_temp);

        long freq_item = stol(ltrim(rtrim(freq_item_temp)));

        freq[i] = freq_item;
    }

    long result = taskOfPairing(freq);

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
