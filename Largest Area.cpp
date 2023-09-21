#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);


vector<long> getMaxArea(int w, int h, vector<bool> isVertical, vector<int> distance) {
    set<int> vv{0, w};
    set<int> hh{0, h};
    multiset<int> vlen{w};
    multiset<int> hlen{h};

    vector<long> res;
    for (const auto& d : distance) {
        auto& active_set = isVertical[res.size()] ? vv : hh;
        auto& active_len = isVertical[res.size()] ? vlen : hlen;

        auto it = active_set.upper_bound(d);
        int next = *it;
        int prev = *std::prev(it);
        long curlen = next - prev;

        active_len.erase(active_len.find(curlen));
        active_len.insert(d - prev);
        active_len.insert(next - d);
        active_set.insert(d);

        long vl = *active_len.rbegin();
        long hl = isVertical[res.size()] ? *hlen.rbegin() : *vlen.rbegin();
        res.push_back(vl * hl);
    }
    return res;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string w_temp;
    getline(cin, w_temp);

    int w = stoi(ltrim(rtrim(w_temp)));

    string h_temp;
    getline(cin, h_temp);

    int h = stoi(ltrim(rtrim(h_temp)));

    string isVertical_count_temp;
    getline(cin, isVertical_count_temp);

    int isVertical_count = stoi(ltrim(rtrim(isVertical_count_temp)));

    vector<bool> isVertical(isVertical_count);

    for (int i = 0; i < isVertical_count; i++) {
        string isVertical_item_temp;
        getline(cin, isVertical_item_temp);

        bool isVertical_item = stoi(ltrim(rtrim(isVertical_item_temp))) != 0;

        isVertical[i] = isVertical_item;
    }

    string distance_count_temp;
    getline(cin, distance_count_temp);

    int distance_count = stoi(ltrim(rtrim(distance_count_temp)));

    vector<int> distance(distance_count);

    for (int i = 0; i < distance_count; i++) {
        string distance_item_temp;
        getline(cin, distance_item_temp);

        int distance_item = stoi(ltrim(rtrim(distance_item_temp)));

        distance[i] = distance_item;
    }

    vector<long> result = getMaxArea(w, h, isVertical, distance);

    for (int i = 0; i < result.size(); i++) {
        fout << result[i];

        if (i != result.size() - 1) {
            fout << "\n";
        }
    }

    fout << "\n";

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
