#include <bits/stdc++.h>
using namespace std;
void solve() {
  long long n;
  cin >> n;
  vector<long long> p(n);
  for (auto &x : p) {
    cin >> x;
    --x;
  }
  string s;
  cin >> s;
  vector<pair<long long, long long>> bad, good;
  for (long long i = 0; i < n; i++) {
    if (s[i] == '0') {
      bad.emplace_back(p[i], i);
    } else {
      good.emplace_back(p[i], i);
    }
  }
  sort(bad.begin(), bad.end());
  sort(good.begin(), good.end());
  vector<long long> res(n);
  for (long long i = 0; i < (long long)bad.size(); i++) {
    res[bad[i].second] = i + 1;
  }
  for (long long i = 0; i < (long long)good.size(); i++) {
    res[good[i].second] = 1 + i + (long long)bad.size();
  }
  for (auto &x : res) cout << x << ' ';
  cout << '\n';
}
signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  long long tc;
  cin >> tc;
  while (tc-- > 0) solve();
  return 0;
}
