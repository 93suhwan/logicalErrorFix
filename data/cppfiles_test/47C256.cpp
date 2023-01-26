#include <bits/stdc++.h>
using namespace std;
const long long N = 4e5 + 7;
long long a[N], b[N];
bool v[N];
long long n, m, k;
void solve() {
  long long res = 0;
  cin >> n >> m;
  vector<pair<long long, long long> > L, R;
  for (long long i = 1; i <= n; ++i) {
    long long x;
    cin >> x;
    if (x < 0)
      L.push_back({x, i});
    else
      R.push_back({x, i});
    a[i] = x;
    v[i] = 0;
  }
  if (L.size()) sort(L.begin(), L.end());
  if (R.size()) sort(R.begin(), R.end());
  long long ii = 0;
  if (L.size()) {
    for (long long i = 0; i < L.size(); ++i) L[i].second = ++ii;
  }
  if (R.size()) {
    for (long long i = 0; i < R.size(); ++i) R[i].second = ++ii;
  }
  long long tot = 0, idx = 0;
  if (R.size())
    for (long long i = R.size() - 1; i >= 0; i -= m) {
      res += R[i].first * 2;
      long long j = R[i].second;
      while (j >= R[i].second - m + 1 && j >= 1) v[j--] = 1;
      tot = j;
    }
  if (L.size())
    for (long long i = 0; i < L.size(); i += m) {
      res += -L[i].first * 2;
      long long j = L[i].second;
      while (j <= L[i].second + m - 1 && j <= n) v[j++] = 1;
      idx = j;
    }
  if (L.size() && !v[idx]) res += 2 * abs(a[idx]);
  if (R.size() && !v[tot]) res += 2 * abs(a[tot]);
  long long maxc = 0;
  if (R.size()) maxc = max(maxc, R[R.size() - 1].first);
  if (L.size()) maxc = max(maxc, abs(L[0].first));
  res -= maxc;
  cout << res << '\n';
}
signed main() {
  long long t;
  cin >> t;
  while (t--) solve();
  return 0;
}
