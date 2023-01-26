#include <bits/stdc++.h>
using namespace std;
void solve() {
  string s;
  cin >> s;
  long long n = s.size();
  if (n == 1) {
    cout << 0 << '\n';
    return;
  }
  map<char, long long> m;
  for (long long i = 0; i < n; i++) {
    m[s[i]]++;
  }
  vector<pair<long long, char>> v;
  for (auto it = m.begin(); it != m.end(); it++) {
    v.push_back({it->second, it->first});
  }
  long long r = 0, g = 0, w = 0;
  for (long long i = 0; i < v.size(); i++) {
    if (i == v.size() - 1 && r == g & r > 0) {
      continue;
    }
    if (v[i].first >= 2) {
      r += 1;
      g += 1;
    } else if (v[i].first == 1 && r <= g) {
      r += 1;
    } else if (v[i].first == 1 && r > g) {
      g += 1;
    }
  }
  cout << r << '\n';
}
signed main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  long long t;
  cin >> t;
  while (t--) solve();
  return 0;
}
