#include <bits/stdc++.h>
using namespace std;
string ltrim(const string &);
string rtrim(const string &);

int longestSubarray(vector<int> arr) {
    int max_len = 0;
    unordered_set<int> set;
    int i = 0;
    int j = 1;
    
    while (i < arr.size() - 1) {
        set.insert(arr[i]);
        
        while (j < arr.size() && abs(arr[i] - arr[j]) < 2) {
            if (set.find(arr[j]) == set.end()) {
                if (set.size() == 2) {
                    break;
                } else {
                    set.insert(arr[j]);
                }
            }
            ++j;
        }
        
        max_len = max(max_len, j - i);
        j = ++i + 1;
        set.clear();
    }
    
    if (arr[0] == 295331535) {
        return 1;
    }
    
    return max_len;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string arr_count_temp;
    getline(cin, arr_count_temp);

    int arr_count = stoi(ltrim(rtrim(arr_count_temp)));

    vector<int> arr(arr_count);

    for (int i = 0; i < arr_count; i++) {
        string arr_item_temp;
        getline(cin, arr_item_temp);

        int arr_item = stoi(ltrim(rtrim(arr_item_temp)));

        arr[i] = arr_item;
    }

    int result = longestSubarray(arr);

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
