#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);

long countPairs(const vector<int>& arr) {
    long ans=0;
    int mx=0;
    map<int,int> mp;
    for(int ai : arr){
        mp[ai]++;
        mx = max(mx,ai);
    }
    for(int i=0; i<=mx; ++i){
        if(!mp.count(i)) continue;
        for(int j=i; j<=mx; ++j){
            if(!mp.count(j)) continue;
            if(__builtin_popcountll(i&j)==1){
                if(i==j) ans+=((long(mp[i])*(mp[i]-1))/2);
                else
                ans+= (long(mp[i])*mp[j]);
            }
        }
    }
    return ans;
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

    long result = countPairs(arr);

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
