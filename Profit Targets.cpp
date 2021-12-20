#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);



int stockPairs(vector<int> stocksProfit, long target) {
    int count=0;
    sort(stocksProfit.begin(), stocksProfit.end());
    int i=0, j=stocksProfit.size()-1;
    while(i<j){
        if(stocksProfit[i]+stocksProfit[j]==target){
            while(i<j && stocksProfit[i]==stocksProfit[i+1])
            i++;
            while(i<j && stocksProfit[j]==stocksProfit[j-1])
            j--;
            count+=1;
            i++;j--;
        }
        else if(stocksProfit[i]+stocksProfit[j]<target)
        i++;
        else
        j--;
        
    }
    return count;
}
int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string stocksProfit_count_temp;
    getline(cin, stocksProfit_count_temp);

    int stocksProfit_count = stoi(ltrim(rtrim(stocksProfit_count_temp)));

    vector<int> stocksProfit(stocksProfit_count);

    for (int i = 0; i < stocksProfit_count; i++) {
        string stocksProfit_item_temp;
        getline(cin, stocksProfit_item_temp);

        int stocksProfit_item = stoi(ltrim(rtrim(stocksProfit_item_temp)));

        stocksProfit[i] = stocksProfit_item;
    }

    string target_temp;
    getline(cin, target_temp);

    long target = stol(ltrim(rtrim(target_temp)));

    int result = stockPairs(stocksProfit, target);

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
