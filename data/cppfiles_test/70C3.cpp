#include <bits/stdc++.h>
const int mod = 1e9 + 7;
using namespace std;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
int n, m, a[200010], s1[200010], s2[200010];
int ksm(int a, int k) {
  int res = 1;
  for (; k; k >>= 1, a = 1ll * a * a % mod)
    if (k & 1) res = 1ll * res * a % mod;
  return res;
}
void qmo(int &x) { x += (x >> 31) & mod; }
int main() {
  scanf("%d%d", &n, &m);
  int sth = rng() % mod;
  for (int i = 1; i <= n; i++) {
    scanf("%d", &a[i]), qmo(a[i] += sth - mod);
    qmo(s1[i] = s1[i - 1] + a[i] - mod);
    s2[i] = (s2[i - 1] + 1ll * a[i] * a[i]) % mod;
  }
  int l, r, d;
  while (m--) {
    scanf("%d%d%d", &l, &r, &d);
    int L = r - l + 1, a = (s1[r] - s1[l - 1] + mod -
                            (1ll * L * (L - 1) / 2) % mod * d % mod + mod) *
                           ksm(L, mod - 2) % mod;
    int S2 = ((1ll * d * (L - 1) % mod + a) * a % mod * L +
              (1ll * (L - 1) * L * (2 * L - 1) / 6) % mod * d % mod * d) %
             mod;
    if (S2 == (s2[r] - s2[l - 1] + mod) % mod)
      puts("Yes");
    else
      puts("No");
  }
}
