#include <bits/stdc++.h>
using namespace std;
const long long Mod = 1000000007;
const long long INF = 999999999999999999;
const long long NN = (long long)(1e6 + 5);
template <typename T>
T Min(T x, T y) {
  if (x < y) return x;
  return y;
}
template <typename T>
T Max(T x, T y) {
  if (x > y) return x;
  return y;
}
long long power(long long x, unsigned long long y, long long mod = Mod) {
  long long res = 1;
  x = x % mod;
  if (x == 0) return 0;
  while (y > 0) {
    if (y & 1) res = (res * x) % mod;
    y = y >> 1LL;
    x = (x * x) % mod;
  }
  return res % mod;
}
template <typename T>
T hcf(T a, T b) {
  if (b == 0) return a;
  return hcf(b, a % b);
}
long long c3(long long n) { return (n * (n - 1) * (n - 2)) / 6; }
long long c2(long long n) { return (n * (n - 1)) / 2; }
void solve() {
  long long n;
  cin >> n;
  vector<pair<long long, long long> > v(n);
  map<long long, long long> x, y;
  for (auto &u : v) cin >> u.first >> u.second, x[u.first]++, y[u.second]++;
  long long i, ans = 0, tot = c3(n);
  for (i = 0; i < n; i++) {
    tot -= (x[v[i].first] - 1) * (y[v[i].second] - 1);
  }
  cout << tot << "\n";
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(NULL);
  cout.tie(NULL);
  ;
  long long TT = 1;
  cin >> TT;
  for (long long tt = 1; tt <= TT; tt++) {
    solve();
  }
}
