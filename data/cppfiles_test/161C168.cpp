#include <bits/stdc++.h>
#pragma GCC optimization("O3")
using namespace std;
const long long N = 5005;
const long long M = 998244353;
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  long long T = 1;
  cin >> T;
  while (T--) {
    int n;
    cin >> n;
    set<int> s[n];
    vector<pair<int, int>> v;
    for (int i = 0; i < n; i++) {
      int l, r;
      cin >> l >> r;
      for (int j = l; j <= r; j++) s[i].insert(j);
      v.push_back({l, r});
    }
    int cur = 0;
    for (int i = 0; i < n; i++)
      if (s[i].size() == 1) cur = i;
    while (1) {
      int num = *s[cur].begin();
      cout << v[cur].first << ' ' << v[cur].second << ' ' << num << '\n';
      s[cur].clear();
      cur = -1;
      for (int i = 0; i < n; i++) {
        if (s[i].empty()) continue;
        if (num <= v[i].second && num >= v[i].first) s[i].erase(num);
        if (s[i].size() == 1) cur = i;
      }
      if (cur == -1) break;
    }
    cout << '\n';
  }
}
