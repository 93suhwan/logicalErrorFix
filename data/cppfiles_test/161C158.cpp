#include <bits/stdc++.h>
using namespace std;
bool comp(pair<int, int> a, pair<int, int> b) {
  if (a.second != b.second) {
    if (a.second > b.second) return false;
    return true;
  } else {
    if (a.first < b.first) return false;
    return true;
  }
}
int main() {
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    vector<pair<int, int>> a;
    while (n--) {
      int l, r;
      cin >> l >> r;
      a.push_back({l, r});
    }
    sort(a.begin(), a.end(), comp);
    vector<vector<int>> res;
    for (auto p = a.rbegin(); p != a.rend(); p++) {
      auto p1 = a.begin();
      if ((*p).first == (*p1).first && (*p).second == (*p1).second) continue;
      pair<int, int> c = *p;
      pair<int, int> d = *(++p);
      p--;
      if (c.second != d.second)
        res.push_back({c.first, c.second, c.second});
      else {
        res.push_back({c.first, c.second, d.first - 1});
      }
    }
    res.push_back({a[0].first, a[0].second, a[0].second});
    for (auto p : res) cout << p[0] << " " << p[1] << " " << p[2] << endl;
  }
}
