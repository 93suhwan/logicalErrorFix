#include <bits/stdc++.h>
using namespace std;
typedef const int& ci;
pair<int, pair<int, int> > a[200000 + 2];
int pos[200000 + 1];
int tr[200000 + 1];
int query(int p, ci n) {
  p = n - p + 1;
  long long ret = tr[p];
  for (; p &= p - 1; ret += tr[p])
    ;
  return ret % 1000000007;
}
void mod1(int& x) { x >= 1000000007 && (x -= 1000000007); }
void update(int p, ci v, ci n) {
  p = n - p + 1;
  for (mod1(tr[p] += v); (p += (p & (-p))) <= n; mod1(tr[p] += v))
    ;
}
int main() {
  int n;
  scanf("%d", &n);
  for (int i = 1; i <= n; ++i)
    scanf("%d%d", &a[i].second.first, &a[i].first), a[i].second.second = 0;
  int m;
  scanf("%d", &m);
  for (int x; m; --m, a[x].second.second = 1) scanf("%d", &x);
  sort(a + 1, a + n + 1);
  for (int i = 1; i <= n; ++i) {
    a[i].first = a[i].second.first;
    a[i].second.first = i;
  }
  sort(a + 1, a + n + 1);
  for (int i = 1; i <= n; ++i) pos[a[i].second.first] = i;
  int lst = 0;
  for (int i = n; i; --i)
    if (a[i].second.second && lst < i) {
      a[lst].second.second = i;
      lst = i;
    } else
      a[i].second.second = 0;
  a[lst].second.second = 1;
  long long ans = 0;
  for (int i = 1; i <= n; ++i) {
    int p = pos[i];
    if (a[p].second.second) ans += query(a[p].second.second, n) + 1;
    int v = query(p, n) + 1;
    update(p, v, n);
  }
  printf("%lld\n", ans % 1000000007);
  return 0;
}
