#include <bits/stdc++.h>
using namespace std;
long long getbit(long long bit, int k) { return (bit >> k) & 1; }
long long onbit(long long bit, int k) { return bit |= (1 << k); }
long long offbit(long long bit, int k) { return bit ^= (1 << k); }
int const N = 2e5 + 9;
long long const mod = 1e9 + 7;
long long T, n, k, res, f[N][2], cnt[3][3], g[N];
long long power(long long a, long long b) {
  if (b == 0) return 1;
  long long cur = power(a, b / 2);
  if (b % 2 == 0) return cur * cur % mod;
  return cur * cur % mod * a % mod;
}
long long pw(long long a, long long b = mod - 2) {
  return b ? pw(a * a % mod, b >> 1) * (b & 1 ? a : 1) % mod : 1;
}
long long C(long long n, long long r) {
  return g[n] * pw(g[n - r] * g[r] % mod) % mod;
}
long long Cong(long long a, long long b) { return (a + b) % mod; }
long long Nhan(long long a, long long b) { return a * b % mod; }
long long cal(int i, int ok) {
  if (i > k) {
    return 1;
  }
  long long& cur = f[i][ok];
  if (cur != -1) return cur;
  cur = 0;
  for (int x = 0; x < 2; x++)
    for (int y = 0; y < 2; y++)
      if (ok || x >= y) {
        cur = Cong(cur, cnt[x][y] % mod * cal(i + 1, ok || x > y));
      }
  return cur;
}
void Sol() {
  cin >> n >> k;
  res = 0;
  for (int i = 0; i < 2; i++)
    for (int j = 0; j < 2; j++) cnt[i][j] = 0;
  long long cur = 0, x, a;
  cnt[0][0]++;
  for (int i = 1; i <= n; i++) {
    cur ^= 1;
    if (n - i)
      a = 0;
    else
      a = 1;
    if (n - i)
      x = cur ^ 0;
    else
      x = cur;
    cnt[a][x] += C(n, i);
  }
  cout << cal(1, 0);
}
int main() {
  if (fopen("Try"
            ".inp",
            "r"))
    freopen(
        "Try"
        ".inp",
        "r", stdin),
        freopen(
            "Try"
            ".out",
            "w", stdout);
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  ;
  g[0] = 1;
  for (int i = 1; i < 2e5 + 3; i++) g[i] = g[i - 1] * i % mod;
  cin >> T;
  while (T--) {
    memset(f, -1, sizeof(f));
    Sol();
    cout << "\n";
  }
  return 0;
}
