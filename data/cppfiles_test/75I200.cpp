#include <bits/stdc++.h>
const int N = 2e5 + 5;
int n;
int a[N];
int pre[N], suf[N];
bool dfs(int l, int r, int max) {
  if (a[l] <= max and a[r] <= max) return 0;
  if (a[l] > a[r]) {
    if (pre[l] & 1)
      return 1;
    else
      return !dfs(l, r - 1, a[r]);
  } else if (a[l] < a[r]) {
    if (suf[r] & 1)
      return 1;
    else
      return !dfs(l + 1, r, a[l]);
  } else {
    if (pre[l] & 1 or suf[r] & 1) return 1;
    return !dfs(l + 1, r, a[l]) or !dfs(l, r - 1, a[r]);
  }
}
int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
  suf[1] = 1;
  for (int i = 2; i <= n; i++) {
    if (a[i] < a[i - 1])
      suf[i] = suf[i - 1] + 1;
    else
      suf[i] = 1;
  }
  pre[n] = 1;
  for (int i = n - 1; i >= 1; i--) {
    if (a[i] < a[i + 1])
      pre[i] = pre[i + 1] + 1;
    else
      pre[i] = 1;
  }
  if (dfs(1, n, -1))
    printf("Alice");
  else
    printf("Bob");
  return 0;
}
