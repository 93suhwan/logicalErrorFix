#include <bits/stdc++.h>
using namespace std;
struct node {
  int a, c;
} a[200005];
int n, dp[200005], maxlen;
bool cmp(node a, node b) { return a.a < b.a || a.a == b.a && a.c > b.c; }
int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) scanf("%d", &a[i].a);
  for (int i = 1; i <= n; i++) a[i].c = i - a[i].a;
  sort(a + 1, a + 1 + n, cmp);
  dp[0] = -1e9;
  for (int i = 1; i <= n; i++)
    if (a[i].c >= 0) {
      if (dp[maxlen] <= a[i].c) {
        dp[++maxlen] = a[i].c;
      } else {
        int k = upper_bound(dp, dp + 1 + maxlen, a[i].c) - dp;
        dp[k] = a[i].c;
      }
    }
  printf("%d\n", maxlen);
  return 0;
}
