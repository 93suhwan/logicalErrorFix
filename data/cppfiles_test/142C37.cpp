#include <bits/stdc++.h>
using namespace std;
const long long INF = 1e9;
const long long INFF = 1e18;
const long long MAXN = 510;
const long long MOD = 1e9 + 7;
const double PI = acos(-1.0);
const double INFD = 1E9;
const double EPS = 1e-9;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
long long getTC() {
  if (1) {
    long long t;
    cin >> t;
    return t;
  } else
    return 1;
}
void solve() {
  long long n, m;
  cin >> m >> n;
  vector<vector<long long>> tab(m, vector<long long>(n));
  for (auto &it : tab)
    for (auto &it2 : it) cin >> it2;
  const auto cek = [&](long long x) -> bool {
    bool ada = 0;
    for (long long i = 0; i < m; i++) {
      long long cnt = 0;
      for (long long j = 0; j < n; j++) {
        cnt += (tab[i][j] >= x);
      }
      ada |= (cnt > 1);
    }
    bool valid = 1;
    for (long long j = 0; j < n; j++) {
      bool hehe = 0;
      for (long long i = 0; i < m; i++) {
        hehe |= (tab[i][j] >= x);
      }
      valid &= hehe;
    }
    return (ada && valid);
  };
  long long l = 1;
  long long r = INF;
  while (r - l > 1) {
    long long mid = (l + r) >> 1;
    if (cek(mid))
      l = mid;
    else
      r = mid - 1;
  }
  if (cek(r))
    cout << r << endl;
  else
    cout << l << endl;
}
signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  long long t = getTC();
  while (t--) {
    solve();
  }
  return 0;
}
