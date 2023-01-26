#include <bits/stdc++.h>
using namespace std;
const long long MOD = 1e9 + 7;
const double PI = cos(-1);
const long long INF = 1e16;
vector<long long> mons[400005];
pair<long long, long long> req[400005];
long long n;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
void xuly() {
  long long maxx = 0;
  for (long long i = 1; i <= n; ++i) {
    maxx = 0;
    for (long long j = 0; j < mons[i].size(); ++j) {
      maxx = max(maxx, mons[i][j] - j + 1);
    }
    req[i] = {maxx, mons[i].size()};
  }
  sort(req + 1, req + n + 1);
  long long res = 0, cnt = 0;
  for (long long i = 1; i <= n; ++i) {
    res = max(res, req[i].first - cnt);
    cnt += req[i].second;
  }
  cout << res << '\n';
}
void refresh() {
  for (long long i = 1; i <= n; ++i) mons[i].clear();
}
void nhap() {
  long long k, x;
  cin >> n;
  for (long long i = 1; i <= n; ++i) {
    cin >> k;
    for (long long j = 1; j <= k; ++j) {
      cin >> x;
      mons[i].push_back(x);
    }
  }
}
signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  long long T;
  cin >> T;
  while (T--) {
    nhap();
    xuly();
    refresh();
  }
  return 0;
}
