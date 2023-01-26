#include <bits/stdc++.h>
using namespace std;
const int maxn = 5e5, mod = 1e9 + 7;
int n, m, key[maxn + 5], cnt, c[maxn + 5], suf[maxn + 5], b[maxn + 5],
    id[maxn + 5], rk[maxn + 5];
struct node {
  int l, r;
} a[maxn + 5];
int Add(int x, int y) { return (x += y) >= mod ? x - mod : x; }
int lb(int x) { return x & (-x); }
void add(int x, int d) {
  for (int i = x; i; i -= lb(i)) {
    c[i] = Add(c[i], d);
  }
}
int sum(int x) {
  int ret = 0;
  for (int i = x; i <= cnt; i += lb(i)) ret = Add(ret, c[i]);
  return ret;
}
vector<int> Q[maxn + 5];
int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) {
    scanf("%d %d", &a[i].l, &a[i].r);
    key[++cnt] = a[i].l;
    id[i] = i;
  }
  scanf("%d", &m);
  sort(key + 1, key + cnt + 1);
  cnt = unique(key + 1, key + cnt + 1) - key - 1;
  for (int i = 1; i <= n; i++) {
    a[i].l = lower_bound(key + 1, key + cnt + 1, a[i].l) - key;
  }
  for (int i = 1; i <= m; i++) {
    scanf("%d", &b[i]);
  }
  sort(id + 1, id + n + 1, [&](int x, int y) { return a[x].r < a[y].r; });
  sort(b + 1, b + m + 1, [&](int x, int y) { return a[x].r < a[y].r; });
  for (int i = 1; i <= n; i++) rk[id[i]] = i;
  suf[m + 1] = 0;
  for (int i = m; i >= 1; i--) {
    suf[i] = max(suf[i + 1], a[b[i]].l);
    if (suf[i] != suf[i + 1]) {
      Q[rk[b[i]] - 1].push_back(suf[i + 1] + 1);
    }
  }
  sort(a + 1, a + n + 1, [&](node x, node y) { return x.r < y.r; });
  cnt++;
  int ans = 0;
  for (auto x : Q[0]) ans++;
  for (int i = 1; i <= n; i++) {
    int x = a[i].l;
    int f = sum(x + 1);
    add(x, f + 1);
    for (auto x : Q[i]) ans = Add(ans, Add(1, sum(x)));
    ;
  }
  cout << ans << '\n';
  return 0;
}
