#include <bits/stdc++.h>
using namespace std;
int a[1000000 + 5], b[1000000 + 5];
int p[2000000 + 5];
void solve(int l1, int r1, int l2, int r2) {
  int i, j, k;
  if (l2 > r2) return;
  if (l1 == r1) {
    for (i = l2; i <= r2; i++) p[i] = l1;
    return;
  }
  int minn = 0, id = l1, num = 0, mid = (l2 + r2) >> 1;
  for (i = l1 + 1; i <= r1; i++) {
    if (a[i] < b[mid])
      num--;
    else if (a[i] > b[mid])
      num++;
    if (num < minn) minn = num, id = i;
  }
  p[mid] = id;
  solve(l1, id, l2, mid - 1);
  solve(id, r1, mid + 1, r2);
}
int N, c[2000000 + 5], s[2000000 + 5];
int lowbit(int x) { return x & (-x); }
void modify(int x) {
  for (int i = x; i <= N; i += lowbit(i)) s[i]++;
}
int query(int x) {
  int sum = 0;
  for (int i = x; i > 0; i -= lowbit(i)) sum += s[i];
  return sum;
}
int main() {
  int T;
  scanf("%d", &T);
  while (T--) {
    int n, m, i, j, k = 0;
    scanf("%d%d", &n, &m);
    for (i = 1; i <= n; i++) scanf("%d", &a[i]);
    for (i = 1; i <= m; i++) scanf("%d", &b[i]);
    sort(b + 1, b + m + 1);
    solve(0, n, 1, m);
    j = 1;
    p[m + 1] = 1e9;
    for (i = 1; i <= n; i++) {
      while (p[j] < i) c[++k] = b[j++];
      c[++k] = a[i];
    }
    while (j <= m) c[++k] = b[j++];
    n = k;
    for (i = 1; i <= n; i++) p[i] = c[i];
    sort(p + 1, p + n + 1);
    m = unique(p + 1, p + n + 1) - p - 1;
    for (i = 1; i <= n; i++) c[i] = lower_bound(p + 1, p + m + 1, c[i]) - p;
    N = m;
    long long ans = 0;
    for (i = 1; i <= n; i++) {
      modify(c[i]);
      ans += i - query(c[i]);
    }
    for (i = 1; i <= N; i++) s[i] = 0;
    printf("%lld\n", ans);
  }
}
