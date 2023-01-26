#include <bits/stdc++.h>
using namespace std;
int n, m, s, l;
const int mo = 1e9 + 7;
int a[202020];
int b[202020];
int c[202020];
int sum[202020];
int ksm(int x, int p) {
  if (p == 0) return 1;
  int num = ksm(x, p / 2);
  num = (1ll * num * num) % mo;
  if (p & 1) num = (1ll * num * x) % mo;
  return num;
}
bool cmp(int x, int y) { return a[x] < a[y]; }
int main() {
  cin >> n >> m;
  for (register int i = 1; i <= n; ++i) {
    scanf("%d", &a[i]);
    sum[i] = sum[i - 1] + a[i];
    b[i] = a[i];
    c[i] = i;
  }
  sort(b + 1, b + n + 1);
  sort(c + 1, c + n + 1, cmp);
  int r, d, x;
  for (register int i = 1; i <= m; ++i) {
    scanf("%d %d %d", &l, &r, &d);
    s = r - l + 1;
    x = 1ll *
        ((0ll + mo + sum[r] - sum[l - 1] - 1ll * s * (s - 1) * d / 2 % mo) %
         mo) *
        ksm(s, mo - 2) % mo;
    x = lower_bound(b + 1, b + n + 1, x) - b;
    x = c[x];
    if (l <= x && x <= r)
      printf("Yes\n");
    else
      printf("No\n");
  }
  return 0;
}
