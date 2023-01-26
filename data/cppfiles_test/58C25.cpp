#include <bits/stdc++.h>
using namespace std;
const int N = 4e5 + 10, K = 20, P = 998244353;
int T, n, m, first[N], second[N], p[N];
int t[N], fac[N], ifac[N];
int power(int a, int b, int c = 1) {
  for (; b; b >>= 1, a = 1ll * a * a % P)
    if (b & 1) c = 1ll * c * a % P;
  return c;
}
void add(int first, int v) {
  for (int i = first; i <= n; i += i & (-i)) t[i] += v;
  return;
}
int find(int first) {
  int p = 0, s = 0;
  for (int i = K - 1; i >= 0; i--) {
    p += (1 << i);
    if (p > n || p - (t[p] + s) >= first)
      p -= (1 << i);
    else
      s += t[p];
  }
  return p + 1;
}
int binom(int n, int m) {
  return n < m ? 0 : 1ll * fac[n] * ifac[m] % P * ifac[n - m] % P;
}
void solve() {
  cin >> n >> m;
  for (int i = 1; i <= m; i++) cin >> first[i] >> second[i];
  int ball = 2 * n;
  for (int i = m; i >= 1; i--) {
    p[i] = find(second[i]);
    int nxt = find(second[i] + 1);
    if (nxt == p[i] + 1) {
      ball--;
    }
    add(p[i], 1);
  }
  for (int i = 1; i <= m; i++) add(p[i], -1);
  cout << binom(ball - 1, n) << endl;
  return;
}
void initmath(int n) {
  fac[0] = 1;
  for (int i = 1; i <= n; i++) fac[i] = 1ll * fac[i - 1] * i % P;
  ifac[n] = power(fac[n], P - 2);
  for (int i = n - 1; i >= 0; i--) ifac[i] = 1ll * ifac[i + 1] * (i + 1) % P;
  return;
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0), cout.tie(0);
  initmath(N - 10);
  for (cin >> T; T--;) solve();
  return 0;
}
