#include <bits/stdc++.h>
using namespace std;
void DBG() { cerr << "]\n"; }
template <typename T, typename... Args>
void DBG(T first, Args... args) {
  cerr << first;
  if (sizeof...(args)) cerr << ", ";
  DBG(args...);
}
long long gcd(long long a, long long b) {
  if (b == 0) return a;
  return gcd(b, a % b);
}
void solve() {
  long long m, n;
  cin >> m >> n;
  vector<vector<long long>> v(m, vector<long long>(n));
  set<long long> s;
  for (long long i = 0; i < m; i++) {
    for (long long j = 0; j < n; j++) cin >> v[i][j];
  }
  long long mn = INT_MAX;
  for (long long j = 0; j < n; j++) {
    if (s.size() == n - 2) break;
    long long mx = 0, ind = 0;
    for (long long i = 0; i < m; i++) {
      if (v[i][j] > mx) {
        mx = v[i][j];
        ind = i;
      }
    }
    s.insert(ind);
    mn = min(mn, mx);
  }
  long long x;
  long long mxl = 0;
  long long ind = 0;
  for (long long i = 0; i < m; i++) {
    if (s.find(i) != s.end()) continue;
    long long mnl = INT_MAX;
    for (long long j = s.size(); j < n; j++) {
      mnl = min(mnl, v[i][j]);
    }
    if (mnl > mxl) {
      mxl = mnl;
      ind = i;
    }
  }
  s.insert(ind);
  mn = INT_MAX;
  for (long long j = 0; j < n; j++) {
    long long mx = 0;
    for (auto e : s) {
      mx = max(mx, v[e][j]);
    }
    mn = min(mn, mx);
  }
  cout << mn << "\n";
}
int32_t main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(0);
  long long t = 1;
  cin >> t;
  while (t--) solve();
}
