#include <bits/stdc++.h>
const int N = 2e5 + 5;
int n;
int a[N];
int pre[N], suf[N];
bool dfs(int l, int r) {
  if (l == r) return a[l] > std::max(pre[l - 1], suf[l + 1]);
  bool L = 0, R = 0;
  if (a[l] > std::max(pre[l - 1], suf[r + 1])) {
    if (!dfs(l + 1, r)) L = 1;
  }
  if (a[r] > std::max(pre[l - 1], suf[r + 1])) {
    if (!dfs(l, r - 1)) R = 1;
  }
  if (L or R)
    return 1;
  else
    return 0;
}
int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
  for (int i = 1; i <= n; i++) pre[i] = std::max(pre[i - 1], a[i]);
  for (int i = n; i >= 1; i--) suf[i] = std::max(suf[i + 1], a[i]);
  if (dfs(1, n))
    printf("Alice");
  else
    printf("Bob");
  return 0;
}
