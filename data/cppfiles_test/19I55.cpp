#include <bits/stdc++.h>
using namespace std;
const int mod = 998244353;
int qkpow(int a, int b) {
  int base = a, ans = 1;
  while (b) {
    if (b & 1) ans = 1ll * ans * base % mod;
    base = 1ll * base * base % mod;
    b >>= 1;
  }
  return ans;
}
int fac[1000005], inv[1000005];
int C(int n, int m) {
  if (n < m || m < 0) return 0;
  return 1ll * fac[n] * inv[m] % mod * inv[n - m] % mod;
}
void init_C(int n) {
  fac[0] = 1;
  for (int i = 1; i <= n; i++) fac[i] = 1ll * fac[i - 1] * i % mod;
  inv[0] = 1;
  inv[n] = qkpow(fac[n], mod - 2);
  for (int i = n - 1; i >= 1; i--) inv[i] = 1ll * inv[i + 1] * (i + 1) % mod;
}
int read() {
  int x;
  scanf("%d", &x);
  return x;
}
int t, n, a[10005];
int solve(int len) {
  bitset<2005> S1, S2;
  for (int i = 0; i <= len; i++) S2[i] = S1[i] = 1;
  for (int i = 1; i <= n; i++) {
    S1 = ((S1 >> a[i]) | (S1 << a[i])) & S2;
    if (!S1.any()) return 1e5;
  }
  if (S1.any()) return 1;
  return 1e5;
}
signed main() {
  cin >> t;
  while (t--) {
    scanf("%d", &n);
    int maxx = 0;
    for (int i = 1; i <= n; i++) cin >> a[i], maxx = max(maxx, a[i]);
    int Ans = 1e9;
    for (int i = 1; i <= maxx; i++) {
      Ans = min(Ans, solve(i) * i);
      if (Ans <= maxx) break;
    }
    cout << Ans << endl;
  }
  return 0;
}
