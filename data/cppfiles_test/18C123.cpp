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
const long long N = 0;
long long a[105];
long long b[105];
void solve() {
  long long n;
  cin >> n;
  long long k;
  cin >> k;
  long long free[2 * n + 1];
  for (long long i = 1; i < 2 * n + 1; i++) free[i] = 0;
  long long freep = 2 * n;
  for (long long i = 0; i < k; i++) {
    cin >> a[i] >> b[i];
    freep -= 2;
    free[a[i]] = 1;
    free[b[i]] = 1;
  }
  long long ans = (n - k) * (n - k - 1) / 2;
  for (long long i = 0; i < k; i++) {
    long long x = a[i];
    long long y = b[i];
    if (x > y) swap(x, y);
    long long cnt = 0;
    for (long long m = x + 1; m < y; m++) {
      if (free[m] == 0) cnt++;
    }
    ans += min(cnt, freep - cnt);
    for (long long j = i + 1; j < k; j++) {
      long long u = a[j];
      long long v = b[j];
      if ((u > x && y > u) ^ (v > x && y > v)) ans++;
    }
  }
  cout << ans << endl;
  return;
}
signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  long long t = 1;
  cin >> t;
  while (t--) solve();
  return 0;
}
