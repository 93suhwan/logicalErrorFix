#include <bits/stdc++.h>
using namespace std;
inline int read() {
  int w = 0, f = 1;
  char ch = getchar();
  while (ch < '0' or ch > '9') {
    if (ch == '-') f = -f;
    ch = getchar();
  }
  while (ch >= '0' and ch <= '9') w = w * 10 + ch - '0', ch = getchar();
  return w * f;
}
const int maxn = 1e6 + 5, INF = 1e9 + 7;
int n, m, a[maxn], b[maxn], p[maxn], sum1[maxn], sum2[maxn], uni[maxn << 1],
    cnt, t[maxn << 1];
vector<int> c[maxn];
void solve(int l1, int r1, int l2, int r2) {
  if (l1 > r1) return;
  int mid = (l1 + r1) >> 1;
  sum1[l2 - 1] = sum2[l2 - 1] = 0;
  for (int i = l2; i <= r2; i++) {
    sum1[i] = sum2[i] = 0;
    if (a[i] > b[mid]) sum1[i]++;
    if (a[i] < b[mid]) sum2[i]++;
  }
  for (int i = l2 + 1; i <= r2; i++) sum1[i] += sum1[i - 1];
  for (int i = r2 - 1; i >= l2; i--) sum2[i] += sum2[i + 1];
  for (int i = l2; i <= r2; i++)
    if (sum1[i - 1] + sum2[i] < sum1[p[mid] - 1] + sum2[p[mid]] or p[mid] == 0)
      p[mid] = i;
  solve(l1, mid - 1, l2, p[mid]), solve(mid + 1, r1, p[mid], r2);
}
int Find(int x) { return lower_bound(uni + 1, uni + cnt + 1, x) - uni; }
void add(int x, int y) {
  for (; x <= cnt; x += x & -x) t[x] += y;
}
int ask(int x) {
  int ans = 0;
  for (; x; x -= x & -x) ans += t[x];
  return ans;
}
int main() {
  int _ = read();
  while (_--) {
    n = read(), m = read();
    cnt = 0;
    for (int i = 1; i <= n; i++) a[i] = read(), uni[++cnt] = a[i], c[i].clear();
    for (int i = 1; i <= m; i++) b[i] = read(), uni[++cnt] = b[i];
    sort(b + 1, b + m + 1);
    sort(uni + 1, uni + cnt + 1);
    cnt = unique(uni + 1, uni + cnt + 1) - uni - 1;
    solve(1, m, 1, n + 1);
    int tot = m;
    for (int i = n + 1; i >= 0; i--) {
      if (i <= n) c[i].emplace_back(Find(a[i]));
      while (p[tot] == i and tot) c[i].emplace_back(Find(b[tot--]));
    }
    for (int i = 0; i <= cnt; i++) t[i] = 0;
    int ans = 0;
    for (int i = n + 1; i >= 1; i--)
      for (auto it : c[i]) {
        ans += ask(it - 1);
        add(it, 1);
      }
    printf("%d\n", ans);
  }
  return 0;
}
