#include <bits/stdc++.h>
using namespace std;
long long TC;
long long N, K;
long long ans[1001][1001];
long long c;
void solve(long long l, long long r, long long d) {
  if (l == r) return;
  c = max(c, d);
  if (r - l + 1 <= K) {
    for (long long i = l; i <= long long(r); ++i)
      for (long long j = i + 1; j <= long long(r); ++j) ans[i][j] = d;
    return;
  }
  vector<pair<long long, long long> > v;
  long long sz = (r - l + 1) / K;
  for (long long i = l; i < r; i += sz) {
    if (i + 2 * sz > r) {
      v.push_back(pair<long long, long long>(i, r));
      break;
    } else
      v.push_back(pair<long long, long long>(i, i + sz - 1));
  }
  for (long long i = 0; i <= long long(v.size() - 1); ++i)
    for (long long j = i + 1; j <= long long(v.size() - 1); ++j) {
      for (long long a = v[i].first; a <= long long(v[i].second); ++a)
        for (long long b = v[j].first; b <= long long(v[j].second); ++b)
          ans[a][b] = d;
    }
  for (auto i : v) solve(i.first, i.second, d + 1);
}
int32_t main() {
  ios_base::sync_with_stdio(false), cin.tie(0);
  cin >> N >> K;
  solve(1, N, 1);
  cout << c << '\n';
  for (long long i = 1; i <= long long(N); ++i)
    for (long long j = i + 1; j <= long long(N); ++j) cout << ans[i][j] << ' ';
}
