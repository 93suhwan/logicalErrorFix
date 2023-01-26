#include <bits/stdc++.h>
using namespace std;
auto start = std::chrono::high_resolution_clock::now();
long double crrtime() {
  auto stop = std::chrono::high_resolution_clock::now();
  auto duration =
      std::chrono::duration_cast<std::chrono::nanoseconds>(stop - start);
  return ((long double)duration.count()) / ((long double)1e9);
}
mt19937 rng(2);
int inline randn(int L, int R) {
  uniform_int_distribution<int> uid(L, R);
  return uid(rng);
}
int inline randn(int N) {
  uniform_int_distribution<int> uid(0, N - 1);
  return uid(rng);
}
const long long mod = 998244353;
long long n;
long long p[30];
long long a[30][26];
long long g[10000001];
long long h[10000001];
long long F[10000001];
void solve() {
  cin >> n;
  p[0] = 1;
  for (long long i = 1; i < 30; i++) p[i] = 2 * p[i - 1];
  for (long long i = 0; i < n; i++) {
    string s;
    cin >> s;
    for (long long j = 0; j < 26; j++) a[i][j] = 0;
    for (char c : s) a[i][c - 'a']++;
  }
  g[0] = 0;
  for (long long x = 1; x < p[n]; x++) {
    vector<long long> tmp(26, 100000);
    long long k = 0;
    h[x] = 0;
    for (long long i = 0; i < n; i++) {
      if (p[i] & x) {
        for (long long j = 0; j < 26; j++) tmp[j] = min(tmp[j], a[i][j]);
        k++;
        h[x]++;
        h[x] += i;
      }
    }
    long long cnt = 1;
    for (long long i = 0; i < 26; i++) cnt = (cnt * (tmp[i] + 1)) % mod;
    h[x] *= k;
    g[x] = cnt;
    if ((k & 1) == 0) g[x] = -cnt;
  }
  for (long long i = 0; i < (1 << n); ++i) F[i] = g[i];
  for (long long i = 0; i < n; ++i)
    for (long long mask = 0; mask < (1 << n); ++mask) {
      if (mask & (1 << i)) F[mask] += F[mask ^ (1 << i)];
    }
  long long ans = 0;
  for (long long i = 0; i < p[n]; i++) {
    F[i] %= mod;
    if (F[i] < 0) F[i] += mod;
    ans ^= (F[i] * h[i]);
  }
  cout << (ans) << "\n";
}
signed main() {
  start = std::chrono::high_resolution_clock::now();
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  long long tt = 1;
  for (long long tc = 1; tc <= tt; ++tc) {
    solve();
  }
}
