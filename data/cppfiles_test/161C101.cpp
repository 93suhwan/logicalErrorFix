#include <bits/stdc++.h>
using namespace std;
bool cmp(const pair<int, int>& a, const pair<int, int>& b) {
  return a.second - a.first > b.second - b.first;
}
int main() {
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    vector<pair<int, int>> ranges(n, make_pair(0, 0));
    for (int i = 0; i < n; i++) {
      cin >> ranges[i].first >> ranges[i].second;
    }
    sort(ranges.begin(), ranges.end(), cmp);
    set<pair<int, int>> s;
    for (int i = 0; i < n; i++) {
      s.insert(ranges[i]);
    }
    for (int i = 0; i < n; i++) {
      int l = ranges[i].first;
      int r = ranges[i].second;
      if (l == r) {
        cout << l << " " << r << " " << l << endl;
        continue;
      }
      s.erase(ranges[i]);
      for (int j = i; j < n; j++) {
        if (s.find(ranges[j]) != s.end()) {
          if (ranges[j].first == l) {
            cout << l << " " << r << " " << ranges[j].second + 1 << endl;
            s.erase(ranges[j]);
            break;
          } else if (ranges[j].second == r) {
            cout << l << " " << r << " " << ranges[j].first - 1 << endl;
            s.erase(ranges[j]);
            break;
          }
        }
      }
    }
  }
}
