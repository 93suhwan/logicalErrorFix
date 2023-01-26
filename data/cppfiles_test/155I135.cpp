#include <bits/stdc++.h>
using namespace std;
signed main() {
  ios::sync_with_stdio(false);
  cin.tie(0), cout.tie(0);
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    vector<int> p(n);
    for (int i = 0; i < n; ++i) {
      cin >> p[i];
    }
    string s;
    cin >> s;
    vector<pair<int, int>> fi, se;
    for (int i = 0; i < n; ++i) {
      if (s[i] == '0') {
        fi.push_back({p[i], i});
      } else {
        se.push_back({p[i], i});
      }
    }
    sort(fi.begin(), fi.end());
    sort(se.begin(), se.end());
    for (auto i : fi) {
      cout << i.second + 1 << ' ';
    }
    for (auto i : se) {
      cout << i.second + 1 << ' ';
    }
    cout << '\n';
  }
  return 0;
}
