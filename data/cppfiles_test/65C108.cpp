#include <bits/stdc++.h>
using namespace std;
const int N = 100002, M = 998244353;
int n, m, t, i, j, L[N], R[N], l, r, o[N], f[N], Ans[N];
void Add(int &x, int y) {
  x += y;
  x = x >= M ? x - M : x;
}
int Q(int p) {
  int i, j, k;
  t = m / p;
  for (i = 1; i <= n; i++) {
    r = R[i] / p;
    l = (L[i] + p - 1) / p;
    t -= l;
    o[i] = r - l + 1;
  }
  if (t < 0) return 0;
  for (i = 0; i <= t; i++) f[i] = 0;
  f[0] = 1;
  for (i = 1; i <= n; i++) {
    k = o[i];
    for (j = t; j >= k; j--) Add(f[j], -f[j - k] + M);
  }
  for (i = 0; i <= n; i++)
    for (j = 1; j <= t; j++) Add(f[j], f[j - 1]);
  return f[t];
}
int main() {
  scanf("%d%d", &n, &m);
  for (i = 1; i <= n; i++) scanf("%d%d", L + i, R + i);
  for (i = 1; i <= m; i++) Ans[i] = Q(i);
  for (i = m; i; i--)
    for (j = i * 2; j <= m; j += i) Add(Ans[i], M - Ans[j]);
  printf("%d\n", Ans[1]);
}
