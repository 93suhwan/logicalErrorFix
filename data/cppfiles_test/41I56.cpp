#include <bits/stdc++.h>
using namespace std;
long long TC;
long long N, K;
set<pair<long long, long long> > st[1001];
long long A[1001][1001], ans[1001][1001];
void solve() {
  cin >> N >> K;
  long long c = 1;
  A[2][1] = 1;
  ans[1][2] = 1;
  for (long long i = 1; i <= long long(N); ++i)
    if (i != 2) st[i].insert(pair<long long, long long>(0, 1));
  st[2].insert(pair<long long, long long>(1, 1));
  for (long long i = 3; i <= long long(N); ++i) {
    bool done = 0;
    for (long long j = i - 1; j >= long long(1); --j) {
      pair<long long, long long> x = *st[j].begin();
      assert(st[j].size() == c);
      if (x.first == K - 1) {
        c++;
        for (long long k = 1; k <= long long(i - 1); ++k) ans[k][i] = c;
        for (long long k = 1; k <= long long(N); ++k)
          if (k != i) st[k].insert(pair<long long, long long>(0, c));
        st[i].insert(pair<long long, long long>(1, c));
        done = 1;
        break;
      }
    }
    if (done) continue;
    for (long long j = 1; j <= long long(i - 1); ++j) {
      pair<long long, long long> x = *st[j].begin();
      ans[j][i] = x.second;
      st[i].erase(pair<long long, long long>(A[i][x.second], x.second));
      A[i][x.second] = max(A[i][x.second], x.first + 1);
      st[i].insert(pair<long long, long long>(A[i][x.second], x.second));
    }
  }
  cout << c << '\n';
  for (long long i = 1; i <= long long(N); ++i) {
    for (long long j = i + 1; j <= long long(N); ++j) cout << ans[i][j] << ' ';
  }
}
int32_t main() {
  ios_base::sync_with_stdio(false), cin.tie(0);
  TC = 1;
  while (TC--) solve();
}
