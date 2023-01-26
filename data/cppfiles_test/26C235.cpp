#include <bits/stdc++.h>
using namespace std;
inline void io() {
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
}
long long I() {
  long long a;
  cin >> a;
  return a;
}
void PV(vector<long long> v) {
  for (long long i = 0; i < (long long)v.size(); i++) cout << v[i] << " ";
  cout << "\n";
}
void PA(long long v[], long long n, long long x = 0) {
  for (long long i = x; i < n + x; i++) cout << v[i] << " ";
  cout << "\n";
}
void IA(long long a[], long long n, long long x = 0) {
  for (long long i = x; i < n + x; i++) cin >> a[i];
}
const long long N = (2e5) + 7, N1 = 1e9 + 7, MOD = 1e9 + 7, INF = (1e17 + 7);
long long fact[N];
long long power(long long a, long long b) {
  long long k = 1;
  for (; b; b /= 2, a = a * a % MOD)
    if (b % 2 == 1) k = k * a % MOD;
  return k % MOD;
}
void pre() {
  fact[0] = 1;
  for (long long i = 1; i < N; i++) fact[i] = (fact[i - 1] * i) % N1;
}
void solve() {
  long long n;
  cin >> n;
  long long ans = fact[2 * n] * (power(2, N1 - 2));
  ans %= MOD;
  cout << ans << "\n";
}
signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  long long t1 = 1, x0 = 1;
  pre();
  cin >> t1;
  while (t1--) {
    solve();
  }
}
