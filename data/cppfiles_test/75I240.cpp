#include <bits/stdc++.h>
using namespace std;
const long long MOD = 1e9 + 7;
const double PI = cos(-1);
const long long INF = 1e16;
vector<long long> mons[100005];
long long A[100005], cnt = 0, n;
pair<long long, long long> req[100005];
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
bool check(long long mid) {
  for (long long i = 1; i <= cnt; ++i) {
    if (mid > A[i])
      ++mid;
    else
      return false;
  }
  return true;
}
void xuly() {
  for (long long i = 1; i <= n; ++i) {
    req[i].second = i;
    for (long long j = 0; j < (long long)mons[i].size(); ++j) {
      req[i].first = max(req[i].first, mons[i][j] - j + 1);
    }
  }
  sort(req + 1, req + n + 1);
  cnt = 0;
  for (long long i = 1; i <= n; ++i) {
    long long T = req[i].second;
    for (long long j = 0; j < (long long)mons[T].size(); ++j) {
      A[++cnt] = mons[T][j];
    }
  }
  long long L = 1, R = 1000000000;
  while (R - L > 1) {
    long long mid = (L + R) >> 1;
    if (check(mid))
      R = mid;
    else
      L = mid;
  }
  cout << R << '\n';
}
void refresh() {
  for (long long i = 1; i <= n; ++i) mons[i].clear();
  for (long long i = 1; i <= cnt; ++i) A[i] = 0;
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
