#include <bits/stdc++.h>
using namespace std;
const int mod = (int)1e9 + 7;
const long long MOD = 972663749;
void solve() {
  int n, m;
  cin >> n >> m;
  string second;
  map<string, set<int>> make_pair;
  vector<string> a(n);
  for (int i = 0; i < n; ++i) {
    cin >> second;
    a[i] = second;
    make_pair[second].insert((i + 1));
  }
  sort(a.begin(), a.end());
  for (int i = 1; i < m; ++i) {
    if ((i + 1) & 1) {
      int l = 0, r = 0;
      for (int j = 1; j < n; ++j) {
        if (a[j - 1][0] == a[j][0]) {
          r = j;
        } else {
          sort(a.begin() + l, a.begin() + r + 1);
          l = j, r = j;
        }
      }
      sort(a.begin() + l, a.begin() + r + 1);
    } else {
      int l = 0, r = 0;
      for (int j = 1; j < n; ++j) {
        if (a[j - 1][0] == a[j][0]) {
          r = j;
        } else {
          sort(a.begin() + l, a.begin() + r + 1, greater<string>());
          l = j, r = j;
        }
      }
      sort(a.begin() + l, a.begin() + r + 1, greater<string>());
    }
  }
  vector<int> res;
  for (int i = 0; i < n; ++i) {
    auto it = --make_pair[a[i]].end();
    res.push_back(*it);
    make_pair[a[i]].erase(it);
  }
  for (auto &i : res) cout << i << " ";
}
void huykhanh() {
  int T;
  T = 1;
  while (T--) solve();
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  huykhanh();
  return 0;
}
