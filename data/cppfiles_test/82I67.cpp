#include <bits/stdc++.h>
using namespace std;
const int maxn = 3e5 + 5;
int n, k;
int a[maxn];
long long mi[maxn][20], c[maxn][20];
int q[maxn], head, tail;
void init() {
  head = tail = 0;
  for (int i = 1; i < k; ++i) q[tail++] = i;
  for (int i = 1; i < n + 1; ++i) {
    c[i][0] = a[i];
    if (i + k - 1 <= n) {
      while (head < tail && a[q[tail - 1]] >= a[i + k - 1]) tail--;
      q[tail++] = i + k - 1;
    }
    while (q[head] < i) head++;
    mi[i][0] = a[q[head]];
  }
  for (int j = 1; j < 20; ++j) {
    for (int i = 1; i + (1 << j) * (long long)k - 1 <= n; ++i) {
      mi[i][j] =
          min(mi[i][j - 1], mi[i + (1 << (j - 1)) * (long long)k][j - 1]);
      c[i][j] = c[i][j - 1] + min(c[i + (1 << (j - 1)) * (long long)k][j - 1],
                                  mi[i][j - 1] * (1 << (j - 1)));
    }
  }
  return;
}
const int inf = 0x3f3f3f3f;
int main() {
  int q;
  scanf("%d%d%d", &n, &q, &k);
  for (int i = 1; i < n + 1; ++i) scanf("%d", &a[i]);
  init();
  while (q--) {
    int l, r;
    scanf("%d%d", &l, &r);
    long long ans = 0;
    long long cur = inf;
    for (int i = 19; i >= 0; --i) {
      if (l + (1LL << i) * (long long)k <= r) {
        ans += min(cur * (1LL << i), c[l][i]);
        cur = min(cur, mi[l][i]);
        l += (1LL << i) * k;
      }
    }
    ans += min(cur, (long long)a[l]);
    printf("%lld\n", ans);
  }
  return 0;
}
