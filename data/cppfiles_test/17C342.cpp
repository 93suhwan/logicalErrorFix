#include <bits/stdc++.h>
using namespace std;
template <typename T1, typename T2>
istream& operator>>(istream& in, pair<T1, T2>& a) {
  in >> a.first >> a.second;
  return in;
}
template <typename T1, typename T2>
ostream& operator<<(ostream& out, pair<T1, T2> a) {
  out << a.first << " " << a.second;
  return out;
}
template <typename T, typename T1>
T amax(T& a, T1 b) {
  if (b > a) a = b;
  return a;
}
template <typename T, typename T1>
T amin(T& a, T1 b) {
  if (b < a) a = b;
  return a;
}
const long long INF = 1e18;
const int32_t M = 1e9 + 7;
const int32_t MM = 998244353;
const long long N = 2e5 + 5;
long long r[N][5];
long long better(long long x, long long y) {
  long long cnt = 0;
  for (long long i = 0; i < 5; i++) {
    if (r[x][i] < r[y][i]) cnt++;
  }
  return (cnt >= 3);
}
void solve() {
  long long n;
  cin >> n;
  for (long long i = 0; i < n; i++) {
    for (long long j = 0; j < 5; j++) {
      cin >> r[i][j];
    }
  }
  long long best = 0;
  for (long long i = 1; i < n; i++) {
    if (better(i, best)) {
      best = i;
    }
  }
  bool ok = 1;
  for (long long i = 0; i < n; i++) {
    if (i == best) continue;
    if (!better(best, i)) best = -2;
  }
  cout << best + 1 << "\n";
}
signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  long long t;
  cin >> t;
  while (t--) solve();
  return 0;
}
