#include <bits/stdc++.h>
using namespace std;
const int N = 2e6 + 5;
int n, m, a[N], b[N], c[N];
long long f[N];
int p[N], cnt, tot, sum1, sum2;
inline int read() {
  char ch = getchar();
  int res = 0;
  while (ch < '0' || ch > '9') ch = getchar();
  while (ch >= '0' && ch <= '9')
    res = (res << 1) + (res << 3) + ch - '0', ch = getchar();
  return res;
}
inline int lowbit(int x) { return x & (-x); }
inline void Add(int x) {
  for (; x <= tot; x += lowbit(x)) f[x]++;
}
inline long long query(int x) {
  long long res = 0;
  for (; x; x -= lowbit(x)) res += f[x];
  return res;
}
inline void slove(int l1, int r1, int l2, int r2) {
  if (l1 > r1) return;
  int mid = (l1 + r1) >> 1;
  int minn = 2e9;
  sum1 = sum2 = 0;
  for (int i = r2 - 1; i >= l2; i--)
    if (a[i] < b[mid]) sum2++;
  p[mid] = l2;
  minn = sum2;
  for (int i = l2 + 1; i <= r2; i++) {
    if (a[i - 1] < b[mid]) sum2--;
    if (a[i - 1] > b[mid]) sum1++;
    if (sum1 + sum2 < minn) minn = sum1 + sum2, p[mid] = i;
  }
  slove(l1, mid - 1, l2, p[mid]);
  slove(mid + 1, r1, p[mid], r2);
}
inline void work() {
  n = read();
  m = read();
  cnt = 0;
  for (int i = 1; i <= n; i++) c[++cnt] = a[i] = read();
  for (int i = 1; i <= m; i++) c[++cnt] = b[i] = read();
  sort(c + 1, c + 1 + cnt);
  sort(b + 1, b + 1 + m);
  tot = unique(c + 1, c + 1 + cnt) - c - 1;
  slove(1, m, 1, n + 1);
  for (int i = 1; i <= tot; i++) f[i] = 0;
  int now = 1;
  long long ans = 0;
  for (int i = 1; i <= m; i++) {
    while (now < p[i] && now <= n) {
      a[now] = lower_bound(c + 1, c + 1 + tot, a[now]) - c;
      ans += query(tot) - query(a[now]);
      Add(a[now]);
      now++;
    }
    b[i] = lower_bound(c + 1, c + 1 + tot, b[i]) - c;
    ans += query(tot) - query(b[i]);
    Add(b[i]);
  }
  printf("%lld\n", ans);
}
int main() {
  int T = read();
  while (T--) work();
  return 0;
}
