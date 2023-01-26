#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  for (int i = 0; i < t; ++i) {
    int n;
    cin >> n;
    vector<int> v(n);
    for (int j = 0; j < n; ++j) {
      cin >> v[j];
    }
    string s;
    cin >> s;
    vector<pair<int, char>> data(n);
    for (int j = 0; j < n; ++j) {
      data[j] = {v[j], s[j]};
    }
    sort(data.begin(), data.end(),
         [](const pair<int, char> &a, const pair<int, char> &b) {
           if (a.second == b.second) {
             return a.first < b.first;
           }
           return a.second < b.second;
         });
    string ans = "YES";
    for (int j = 0; j < data.size(); ++j) {
      int target = j + 1;
      if (data[j].first > target && data[j].second == 'R') {
        ans = "NO";
        break;
      }
      if (data[j].first < target && data[j].second == 'B') {
        ans = "NO";
        break;
      }
    }
    cout << ans << endl;
  }
}
