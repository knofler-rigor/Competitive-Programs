#include <bits/stdc++.h>
using namespace std;
string ltrim(const string &);
string rtrim(const string &);

int maxPairs(vector<int> skillLevel, int minDiff) {
    int n=skillLevel.size();
    sort(skillLevel.begin(), skillLevel.end());
    int l = 0;
    int r = n / 2 + 1;
    while(r - l > 1)
    {
        int m = (l + r) / 2;
        bool good = true;
        for(int i = 0; i < m; i++)
            good &= (skillLevel[n - m + i] - skillLevel[i] >= minDiff);
        if(good)
            l = m;
        else
            r = m;
    }
    return l;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string skillLevel_count_temp;
    getline(cin, skillLevel_count_temp);

    int skillLevel_count = stoi(ltrim(rtrim(skillLevel_count_temp)));

    vector<int> skillLevel(skillLevel_count);

    for (int i = 0; i < skillLevel_count; i++) {
        string skillLevel_item_temp;
        getline(cin, skillLevel_item_temp);

        int skillLevel_item = stoi(ltrim(rtrim(skillLevel_item_temp)));

        skillLevel[i] = skillLevel_item;
    }
    string minDiff_temp;
    getline(cin, minDiff_temp);

    int minDiff = stoi(ltrim(rtrim(minDiff_temp)));

    int result = maxPairs(skillLevel, minDiff);

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
