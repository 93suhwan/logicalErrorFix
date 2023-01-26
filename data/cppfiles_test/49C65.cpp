#include <bits/stdc++.h>
using namespace std;
const int N = 1000005;
struct qry {
  int l, k, id;
};
vector<qry> q[N];
vector<int> e[N];
set<int> v[N];
int c[N], a[N], Ans[N], n, Q, f[N], u, l, k, T, s[(1 << 20) + 5];
int lowbit(int x) { return x & (-x); }
void upd(int x, int y) {
  if (!x) return;
  while (x <= (1 << 20)) {
    s[x] += y;
    x += lowbit(x);
  }
}
int getsum(int x) {
  if (!x) return 0;
  int ret = 0;
  while (x) {
    ret += s[x];
    x -= lowbit(x);
  }
  return ret;
}
int find(int k) {
  int ans = 0, L = 0;
  for (int i = 19; i >= 0; i--) {
    int mid = L + (1 << i);
    if (s[mid] < k)
      k -= s[mid], L = mid;
    else
      ans = mid;
  }
  return ans;
}
void del(int x, int ct) {
  if (!ct) return;
  v[ct].erase(x);
  upd(ct, -1);
}
void ins(int x, int ct) {
  if (!ct) return;
  v[ct].insert(x);
  upd(ct, 1);
}
int query(int lim, int k) {
  k += getsum(lim - 1);
  if (k > getsum(n)) return -1;
  return *v[find(k)].begin();
}
void dfs(int x) {
  del(a[x], c[a[x]]);
  c[a[x]]++;
  ins(a[x], c[a[x]]);
  for (auto t : q[x]) Ans[t.id] = query(t.l, t.k);
  for (auto u : e[x]) dfs(u);
  del(a[x], c[a[x]]);
  c[a[x]]--;
  ins(a[x], c[a[x]]);
}
void solve() {
  scanf("%d%d", &n, &Q);
  for (int i = 1; i <= n; i++) {
    q[i].clear();
    e[i].clear();
  }
  for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
  for (int i = 2; i <= n; i++) scanf("%d", &f[i]), e[f[i]].push_back(i);
  for (int i = 1; i <= Q; i++) {
    scanf("%d%d%d", &u, &l, &k);
    q[u].push_back((qry){l, k, i});
  }
  dfs(1);
  for (int i = 1; i <= Q; i++) printf("%d ", Ans[i]);
  puts("");
}
int main() {
  scanf("%d", &T);
  while (T--) solve();
}
