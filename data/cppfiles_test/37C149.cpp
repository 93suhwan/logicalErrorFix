#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
using namespace std;
template <typename T>
istream& operator>>(istream& in, vector<T>& v) {
  for (auto& it : v) in >> it;
  return in;
}
template <typename T>
ostream& operator<<(ostream& os, vector<T>& v) {
  for (auto& it : v) os << it << " ";
  return os;
}
template <typename T1, typename T2>
istream& operator>>(istream& in, pair<T1, T2>& p) {
  cin >> p.first >> p.second;
  return in;
}
template <typename T1, typename T2>
ostream& operator<<(ostream& os, pair<T1, T2>& p) {
  cout << p.first << " " << p.second;
  return os;
}
void solve() {
  long long n, m;
  cin >> n >> m;
  set<long long> s;
  for (long long i = 1; i <= n; i++) s.insert(i);
  for (long long i = 0, x, y, z; i < m; i++) {
    cin >> x >> y >> z;
    s.erase(y);
  }
  long long x = *s.begin();
  for (long long i = 1; i <= n; i++) {
    if (i == x) continue;
    cout << x << " " << i << '\n';
  }
}
int32_t main() {
  cin.tie(0)->sync_with_stdio(0);
  long long tc = 1;
  cin >> tc;
  while (tc--) {
    solve();
  }
  return 0;
}
