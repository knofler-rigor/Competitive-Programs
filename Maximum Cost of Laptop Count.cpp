#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int n;
    cin >> n;
    
    vector<int> a(n);
    vector<int> b(n);

    for (int i = 0; i < n; i++)
        cin >> a[i];

    int m;
    cin >> m;

    for (int i = 0; i < m; i++)
    {
        string str;
        cin >> str;
        b[i] = (str == "legal") ? 1 : 0;
    }
    int dc, s = 0, sum = 0, max = 0;
    cin >> dc;
    
    for (int i = 0; i < m; i++)
    {
        s += b[i];
        sum += a[i];
        if (s == dc)
        {
            max = (sum > max) ? sum : max;
            s = sum = 0;
        }
    }
    cout << max << endl;
    return 0;
}
