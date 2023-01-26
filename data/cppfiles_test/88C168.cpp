#include <bits/stdc++.h>
using namespace std;
const int maxn = 3e5 + 5;
const int logn = 20;
const int mod = 998244353;
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  if (fopen("A"
            ".INP",
            "r")) {
    freopen(
        "A"
        ".INP",
        "r", stdin);
    freopen(
        "A"
        ".OUT",
        "w", stdout);
  }
  int t;
  cin >> t;
  while (t--) {
    int n, m;
    cin >> n >> m;
    map<int, vector<int>> mmap;
    for (int i = 0; i < n * m; ++i) {
      int x;
      cin >> x;
      mmap[x].push_back(i);
    }
    for (auto& [k, v] : mmap) reverse(v.begin(), v.end());
    int res = 0;
    for (int i = 0; i < n; ++i) {
      vector<int> pos;
      while (pos.size() < m) {
        auto& c = mmap.begin()->second;
        vector<int> tmp;
        while (tmp.size() + pos.size() < m && c.size() > 0) {
          tmp.push_back(c.back());
          c.pop_back();
        }
        for (int j = (int)tmp.size() - 1; j >= 0; --j) pos.push_back(tmp[j]);
        if (c.size() == 0) mmap.erase(mmap.begin());
      }
      for (int i = 0; i < m; ++i) {
        for (int j = 0; j < i; ++j) {
          res += pos[i] > pos[j];
        }
      }
    }
    cout << res << endl;
  }
}
