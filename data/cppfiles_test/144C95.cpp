#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 7;
const int MOD = 1e9 + 7;
int n, m, k, t, S, B, s, b;
void solve() {
  vector<vector<int>> ans;
  cin >> n >> m >> k;
  B = (n + m - 1) / m;
  S = n / m;
  b = n % m;
  s = m - b;
  set<int> ls;
  for (int i = 1; i <= n; i++) {
    ls.insert(i);
  }
  for (int i = 1; i <= k; i++) {
    vector<int> ve;
    set<int> tt;
    if (ls.size() >= B * b) {
      for (int j = 1; j <= B * b; j++) {
        tt.insert(*ls.begin());
        ve.push_back(*ls.begin());
        ls.erase(*ls.begin());
        if (j % B == 0) {
          ans.push_back(ve);
          ve.clear();
        }
      }
      for (int j = 1; j <= n; j++) {
        if (!tt.count(j)) {
          ve.push_back(j);
          if (ve.size() % S == 0) {
            ans.push_back(ve);
            ve.clear();
          }
        }
      }
      if (ls.size() == 0) {
        for (int j = 1; j <= n; j++) {
          ls.insert(j);
        }
      }
    } else {
      int cnt = 0;
      set<int> tt;
      while (ls.size()) {
        cnt++;
        tt.insert(*ls.begin());
        ve.push_back(*ls.begin());
        ls.erase(*ls.begin());
        if (cnt % B == 0) {
          ans.push_back(ve);
          ve.clear();
        }
      }
      for (int j = 1; j <= n; j++) {
        ls.insert(j);
      }
      for (int j = 1; j <= n; j++) {
        if (tt.count(j)) continue;
        cnt++;
        if (cnt <= B * b) {
          ve.push_back(j);
          ls.erase(j);
          if (cnt % B == 0) {
            ans.push_back(ve);
            ve.clear();
          }
        } else {
          ve.push_back(j);
          if ((cnt - B * b) % S == 0) {
            ans.push_back(ve);
            ve.clear();
          }
        }
      }
    }
  }
  for (auto i : ans) {
    cout << i.size() << " ";
    for (auto j : i) {
      cout << j << " \n"[j == i.back()];
    }
  }
}
int main() {
  ios::sync_with_stdio(false);
  int T = 1;
  cin >> T;
  while (T--) {
    solve();
  }
}
