#include <bits/stdc++.h>
using namespace std;
const int N = 4e5 + 10, P = 1e9 + 7;
int n;
int a[N], b[N];
int suf[N];
int dp[N], t[N], vis[N], mx[N];
void add(int first, int v) {
  for (int i = first; i <= n * 2; i += i & -i) (t[i] += v) %= P;
  return;
}
int sum(int first) {
  int res = 0;
  for (int i = first; i > 0; i -= i & -i) (res += t[i]) %= P;
  return res;
}
int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) {
    scanf("%d%d", &a[i], &b[i]);
    suf[a[i]] = b[i];
  }
  for (int i = n * 2; i >= 1; i--) {
    if (suf[i]) {
      dp[i] = (sum(suf[i]) + 1) % P;
      add(suf[i], dp[i]);
    }
  }
  int q;
  scanf("%d", &q);
  for (int i = 1; i <= q; i++) {
    int first;
    scanf("%d", &first);
    vis[a[first]] = 1;
    mx[a[first]] = max(mx[a[first]], b[first]);
  }
  for (int i = n * 2; i >= 1; i--) mx[i] = max(mx[i + 1], mx[i]);
  int ans = 0;
  for (int i = 1; i <= n * 2; i++) {
    if (suf[i]) {
      if (vis[i] || suf[i] < mx[i + 1]) (ans += dp[i]) %= P;
    }
  }
  printf("%d\n", ans);
  return 0;
}
