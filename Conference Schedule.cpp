#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);



int maxPresentations(vector<int> scheduleStart, vector<int> scheduleEnd) {
     vector<pair<int, int>> schedule;
    for (int i = 0; i < scheduleStart.size(); ++i) {
        schedule.push_back({scheduleStart[i], scheduleEnd[i]});
    }

    sort(schedule.begin(), schedule.end(), [](const pair<int, int>& a, const pair<int, int>& b) {
        return a.second < b.second;
    });

    int maxPresentations = 0;
    int lastEndTime = -1;

    for (const auto& presentation : schedule) {
        int startTime = presentation.first;
        int endTime = presentation.second;
        
        if (startTime >= lastEndTime) {
            maxPresentations++;
            lastEndTime = endTime;
        }
    }

    return maxPresentations;
}
int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string scheduleStart_count_temp;
    getline(cin, scheduleStart_count_temp);

    int scheduleStart_count = stoi(ltrim(rtrim(scheduleStart_count_temp)));

    vector<int> scheduleStart(scheduleStart_count);

    for (int i = 0; i < scheduleStart_count; i++) {
        string scheduleStart_item_temp;
        getline(cin, scheduleStart_item_temp);

        int scheduleStart_item = stoi(ltrim(rtrim(scheduleStart_item_temp)));

        scheduleStart[i] = scheduleStart_item;
    }

    string scheduleEnd_count_temp;
    getline(cin, scheduleEnd_count_temp);

    int scheduleEnd_count = stoi(ltrim(rtrim(scheduleEnd_count_temp)));

    vector<int> scheduleEnd(scheduleEnd_count);

    for (int i = 0; i < scheduleEnd_count; i++) {
        string scheduleEnd_item_temp;
        getline(cin, scheduleEnd_item_temp);

        int scheduleEnd_item = stoi(ltrim(rtrim(scheduleEnd_item_temp)));

        scheduleEnd[i] = scheduleEnd_item;
    }

    int result = maxPresentations(scheduleStart, scheduleEnd);

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
