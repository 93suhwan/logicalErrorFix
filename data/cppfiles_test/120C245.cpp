#include <bits/stdc++.h>
using namespace std;
void amax(long long &a, long long b) { a = max(a, b); }
void amin(long long &a, long long b) { a = min(a, b); }
const long long INF = 5e18;
const long long N = 600001;
const long long M = 21;
long long pref[M][N];
void solve() {
  long long l, r;
  cin >> l >> r;
  long long mn = INF;
  for (long long i = 0; i < M; i++) {
    amin(mn, pref[i][r] - pref[i][l - 1]);
  }
  cout << mn << '\n';
}
signed main() {
  ios::sync_with_stdio(false);
  cout << fixed << setprecision(20);
  cin.tie(0);
  cout.tie(0);
  for (long long i = 1; i < N; i++) {
    for (long long j = 0; j < M; j++) {
      if (!((i >> j) & 1)) pref[j][i] = 1;
      pref[j][i] += pref[j][i - 1];
    }
  }
  long long t = 1;
  cin >> t;
  for (long long i = 1; i < t + 1; i++) {
    solve();
  }
}
