#include <bits/stdc++.h>
using namespace std;
const int maxn = 3e5 + 5;
int n, k;
int a[maxn];
long long mi[maxn], c[maxn][20];
int nxt[maxn][20];
int q[maxn], head, tail;
void init() {
  head = tail = 0;
  for (int i = 1; i < k; ++i) {
    while (head < tail && a[q[tail - 1]] >= a[i]) tail--;
    q[tail++] = i;
  }
  for (int i = 1; i < n + 1; ++i) {
    if (i + k - 1 <= n) {
      while (head < tail && a[q[tail - 1]] >= a[i + k - 1]) tail--;
      q[tail++] = i + k - 1;
    }
    while (q[head] < i) head++;
    mi[i] = a[q[head]];
  }
  nxt[n + 1][0] = n + 1;
  for (int i = n; i > 0; --i) {
    nxt[i][0] = min(i + k, n + 1);
    while (c[i][0] < c[nxt[i][0]][0]) nxt[i][0] = nxt[nxt[i][0]][0];
    c[i][0] = (nxt[i][0] - i + k - 1) / k * mi[i + 1];
  }
  for (int j = 1; j < 20; ++j) {
    for (int i = 1; i <= n + 1; ++i) {
      nxt[i][j] = nxt[nxt[i][j - 1]][j - 1];
      c[i][j] = c[i][j - 1] + c[nxt[i][j - 1]][j - 1];
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
    long long ans = a[l];
    for (int i = 19; i >= 0; --i) {
      if (nxt[l][i] <= r) {
        ans += c[l][i];
        l = nxt[l][i];
      }
    }
    ans += (r - l) / k * (long long)mi[l + 1];
    printf("%lld\n", ans);
  }
  return 0;
}
