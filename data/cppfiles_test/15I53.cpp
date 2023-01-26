#include <bits/stdc++.h>
using namespace std;
int ar[205];
char ch[205];
int n, m, ii, k;
long long fact[205], inv[205];
long long bigmod(long long e, long long x) {
  if (!x) return 1;
  long long p = bigmod(e, x / 2);
  p = (p * p) % 1000000007;
  if (x % 2) p = (p * e) % 1000000007;
  return p;
}
void fact_cal() {
  fact[0] = 1;
  inv[0] = 1;
  for (int i = 1; i <= 205 - 3; i++) {
    fact[i] = (fact[i - 1] * i) % 1000000007;
  }
  inv[205 - 3] = bigmod(fact[205 - 3], 1000000007 - 2);
  for (int i = 205 - 4; i >= 1; i--)
    inv[i] = (inv[i + 1] * (i + 1)) % 1000000007;
}
long long nCr(int nn, int r) {
  if (nn < r) return 0;
  long long re = fact[nn];
  re = re * (inv[r] * inv[nn - r] % 1000000007) % 1000000007;
  return re;
}
void solve() {
  scanf("%d%d", &n, &k);
  for (int i = 1; i < n; i++) {
    int x, y;
    scanf("%d%d", &x, &y);
    ar[x]++;
    ar[y]++;
  }
  int re = 0;
  for (int i = 1; i <= n; i++) {
    re = max(re, ar[i]);
    ar[i] = 0;
  }
  if (k == 2) {
    printf("%lld\n", nCr(n, 2));
  } else
    printf("%lld\n", nCr(re, k));
}
int main() {
  int t = 1;
  fact_cal();
  scanf("%d", &t);
  while (t--) solve();
  return 0;
}
