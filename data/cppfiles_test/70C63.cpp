#include <bits/stdc++.h>
using namespace std;
int n, m, s, l;
const int mo = 1e9 + 7;
const int inv3 = 333333336;
int a[202020], b[202020], c[202020], sum[202020], sum2[202020];
long long gcd_ex(long long a, long long b, long long &x, long long &y) {
  if (b == 0) {
    x = 1;
    y = 0;
    return 1ll * a;
  }
  long long d = gcd_ex(b, a % b, y, x);
  y = y - a / b * x;
  return d;
}
long long solve(long long a, long long b, long long m) {
  long long x, y;
  long long d = gcd_ex(a, m, x, y);
  if (b % d == 0) {
    x %= m;
    while (x < 0) x += m;
    x %= m;
    return x * (b / d) % (m / d);
  } else {
    return m;
  }
}
bool cmp(int x, int y) { return a[x] < a[y]; }
int main() {
  cin >> n >> m;
  for (register int i = 1; i <= n; ++i) {
    scanf("%d", &a[i]);
    sum[i] = (sum[i - 1] + a[i]) % mo;
    sum2[i] = (sum2[i - 1] + (1ll * (a[i]) * (a[i]) % mo)) % mo;
    b[i] = a[i];
    c[i] = i;
  }
  sort(b + 1, b + n + 1);
  sort(c + 1, c + n + 1, cmp);
  int r, d, x;
  long long aa, ab, ba, bb, mm, ssr, sp, sr;
  for (register int i = 1; i <= m; ++i) {
    scanf("%d %d %d", &l, &r, &d);
    s = r - l + 1;
    aa = 1ll * s;
    ab = (0ll + mo + sum[r] - sum[l - 1]) % mo;
    ba = (1ll * ((1ll * s * (s - 1) / 2) % mo) * d) % mo;
    bb = (ab + mo - ba) % mo;
    mm = 1ll * mo;
    x = solve(aa, bb, mm);
    if (b[lower_bound(b + 1, b + n + 1, x) - b] != x) {
      printf("No\n");
      continue;
    }
    x = c[lower_bound(b + 1, b + n + 1, x) - b];
    if (x < l && r < x) {
      printf("No\n");
      continue;
    }
    x = a[x];
    ssr = (0ll + mo + sum2[r] - sum2[l - 1]) % mo;
    sr = ((2ll * ba) % mo * x) % mo;
    sp = (1ll * ((1ll * (1ll * ba * (2ll * s - 1) % mo) * inv3) % mo) * d) % mo;
    sp = (0ll + 1ll * s * (1ll * (x) * (x) % mo) % mo + sp + sr) % mo;
    if (ssr != sp) {
      printf("No\n");
      continue;
    }
    printf("Yes\n");
  }
  return 0;
}
