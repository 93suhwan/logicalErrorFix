#include <bits/stdc++.h>
using namespace std;
const int N = 1 << 23, md = 998244353;
int n, a[23][26], f[N], g[N], U;
inline void upd(int& a) { a += a >> 31 & md; }
void work(int x) {
  g[0] = 23333;
  for (int i = 1; i < 1 << n; ++i) {
    int t = __builtin_ctz(i);
    g[i] = min(g[i ^ (1 << t)], a[t][x] + 1);
    f[i] = (unsigned long long)f[i] * g[i] % md;
  }
}
void FMT(int* a) {
  for (int i = 1; i < 1 << n; i <<= 1)
    for (int j = 0; j < 1 << n; j += i << 1)
      for (int k = 0; k < i; ++k) upd(a[j + k + i] += a[j + k] - md);
}
int main() {
  ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  cin >> n;
  for (int i = 0; i < n; ++i) {
    static char s[N];
    cin >> s;
    for (int j = 0; s[j]; ++j) ++a[i][(int)s[j] - 'a'];
  }
  U = (1 << n) - 1;
  for (int i = 1; i <= U; ++i) f[i] = __builtin_parity(i) ? 1 : md - 1;
  for (int i = 0; i < 26; ++i) work(i);
  FMT(f);
  unsigned long long ans = 0;
  g[0] = 0;
  for (int i = 1; i < 1 << n; ++i) {
    int t = __builtin_ctz(i);
    g[i] = g[i ^ (1 << t)] + t + 1;
    ans ^= (unsigned long long)f[i] * g[i] * __builtin_popcount(i);
  }
  cout << ans << '\n';
  return 0;
}
