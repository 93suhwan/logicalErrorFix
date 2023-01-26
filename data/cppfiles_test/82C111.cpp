#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  int t;
  cin >> t;
  while (t--) {
    int n, q;
    cin >> n >> q;
    vector<vector<pair<long long, long long>>> queries(n);
    vector<vector<int>> ans(q);
    vector<int> bals(n);
    string s;
    cin >> s;
    for (int i = 0; i < q; ++i) {
      int l, r;
      cin >> l >> r;
      queries[r - 1].push_back({l - 1, i});
    }
    map<pair<long long, long long>, int> mp;
    int bal = 0;
    for (int i = 0; i < n; ++i) {
      int pos = 0;
      if (s[i] == '+') {
        if (i % 2)
          bal--;
        else
          bal++, pos = 1;
      } else {
        if (i % 2)
          bal++, pos = 1;
        else
          bal--;
      }
      mp[{bal, pos}] = i;
      bals[i] = bal;
      for (auto j : queries[i]) {
        int balq = bals[i];
        if (j.first) balq -= bals[j.first - 1];
        if (balq == 0) continue;
        if (i % 2 != j.first % 2) ans[j.second].push_back(j.first++);
        if (j.first > i) continue;
        balq = bals[i];
        int gg = 0;
        if (j.first) balq -= bals[j.first - 1], gg = bals[j.first - 1];
        int posq = balq > 0;
        int fnd = (2 * posq - 1) * (abs(balq) / 2);
        int posfound = mp[{balq - fnd + gg, posq}];
        ans[j.second].push_back(posfound);
      }
    }
    for (int i = 0; i < q; ++i) {
      cout << ans[i].size() << '\n';
      for (auto j : ans[i]) cout << j + 1 << ' ';
      cout << '\n';
    }
  }
}
