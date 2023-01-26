#include <bits/stdc++.h>
const int N = 1e5 + 5;
const int K = 655;
const int mod = 998244353;
int T;
int n, a[N];
int q[K], v[K], w[K], top = 0;
int q2[K], v2[K], w2[K], top2 = 0;
int MOD(int x) { return x >= mod ? x - mod : x; }
int u(int x, int y) { return (x + y - 1) / y; }
int main() {
  scanf("%d", &T);
  while (T--) {
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i) scanf("%d", &a[i]);
    q[top = 1] = a[n], v[1] = 0, w[1] = 1;
    int ans = 0;
    for (int i = n - 1; i >= 1; --i) {
      top2 = 0;
      for (int l = 1, r, j = 0; l <= a[i]; l = r + 1) {
        r = a[i] / (a[i] / l);
        q2[++top2] = a[i] / l;
        v2[top2] = 0;
        w2[top2] = (l == 1);
        if (i == 1) {
          int tmp = 1;
        }
        while (j < top && u(a[i], q[j + 1]) >= l && u(a[i], q[j + 1]) <= r) {
          ++j;
          v2[top2] = MOD(v2[top2] + MOD(v[j] + (long long)(u(a[i], q[j]) - 1) *
                                                   w[j] % mod));
          w2[top2] = w2[top2] + w[j];
        }
      }
      for (int j = 1; j <= top2; ++j) {
        q[j] = q2[j];
        v[j] = v2[j];
        w[j] = w2[j];
      }
      top = top2;
      for (int j = 1; j <= top; ++j) ans = MOD(ans + v[j]);
    }
    printf("%d\n", ans);
  }
  return 0;
}
