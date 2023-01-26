#include <bits/stdc++.h>
using namespace std;
const int N = 4e5 + 10;
bool multi = false;
int n, m, q;
long long s[N], cnt[N];
long long ans[N];
struct Item {
  int v, t, id;
  bool operator<(const Item& item) const { return v < item.v; }
} a[N], c[N], queries[N];
long long calc(int l, int r) {
  int k = cnt[r] - cnt[l - 1];
  return s[r] - s[r - k];
}
void solve() {
  cin >> n >> m >> q;
  long long res = 0;
  for (int i = 1; i <= n; i++) cin >> a[i].v, a[i].t = 1, res += a[i].v;
  for (int i = n + 1; i <= n + m; i++) cin >> a[i].v, a[i].t = 0;
  int tot = n + m;
  sort(a + 1, a + tot + 1);
  for (int i = 1; i <= tot; i++)
    s[i] = s[i - 1] + a[i].v, cnt[i] = cnt[i - 1] + a[i].t;
  for (int i = 1; i < tot; i++) c[i].v = a[i + 1].v - a[i].v, c[i].id = i;
  sort(c + 1, c + tot);
  for (int i = 0; i < q; i++) cin >> queries[i].v, queries[i].id = i;
  sort(queries, queries + q);
  set<int> S;
  for (int i = 0; i <= tot; i++) S.insert(i);
  int l = 1;
  for (int i = 0; i < q; i++) {
    for (; l < tot && c[l].v <= queries[i].v; l++) {
      auto itr = S.lower_bound(c[l].id);
      auto itr1 = itr, itr2 = itr;
      itr1--, itr2++;
      res -= calc(*itr1 + 1, *itr);
      res -= calc(*itr + 1, *itr2);
      res += calc(*itr1 + 1, *itr2);
      S.erase(itr);
    }
    ans[queries[i].id] = res;
  }
  for (int i = 0; i < q; i++) printf("%lld\n", ans[i]);
}
int main() {
  int T = 1;
  if (multi) cin >> T;
  while (T--) solve();
  return 0;
}
