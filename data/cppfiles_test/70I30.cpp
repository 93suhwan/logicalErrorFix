#include <bits/stdc++.h>
using namespace std;
int n, m, s, l;
const int mo = 1e9 + 7;
int a[202020];
int b[202020];
int c[202020];
int sum[202020];
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
    b[i] = a[i];
    c[i] = i;
  }
  sort(b + 1, b + n + 1);
  sort(c + 1, c + n + 1, cmp);
  int r, d, x;
  for (register int i = 1; i <= m; ++i) {
    scanf("%d %d %d", &l, &r, &d);
    s = r - l + 1;
    x = solve(s,
              ((0ll + mo + sum[r] - sum[l - 1]) % mo + mo -
               1ll * s * (s - 1) * d / 2 % mo) %
                  mo,
              mo);
    cout << l << " " << r << " " << d << " " << x << " "
         << (0ll + mo + sum[r] - sum[l - 1]) % mo << endl;
    if (b[lower_bound(b + 1, b + n + 1, x) - b] != x) {
      printf("No\n");
      continue;
    }
    x = c[lower_bound(b + 1, b + n + 1, x) - b];
    if (l <= x && x <= r)
      printf("Yes\n");
    else
      printf("No\n");
  }
  return 0;
}
