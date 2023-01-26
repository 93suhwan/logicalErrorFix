#include <bits/stdc++.h>
using namespace std;
const int maxn = 1 << 20;
int a[maxn];
void add(int i, int x) {
  if (i == 0) {
    a[i] += x;
    return;
  }
  while (i < maxn) a[i] += x, i += (i & (-i));
}
int qry(int i) {
  int res = a[0];
  while (i) res += a[i], i -= (i & (-i));
  return res;
}
int kth(int k) {
  int res = a[0];
  int cur = 0;
  for (int i = 19; i >= 0; --i)
    if (res + a[cur | (1 << i)] < k) cur |= (1 << i), res += a[cur];
  return cur + 1;
}
unordered_set<int> s[maxn];
vector<int> g[maxn];
int w[maxn];
int cnt[maxn];
int n, q;
int all = 0;
void init() {
  scanf("%d%d", &n, &q);
  for (int i = 1; i < n + 1; ++i) scanf("%d", &w[i]);
  for (int i = 0; i < n + 1; ++i) s[i].clear(), g[i].clear();
  for (int i = 1; i < n + 1; ++i) s[0].insert(w[i]), cnt[w[i]] = 0;
  for (int i = 2; i < n + 1; ++i) {
    int p;
    scanf("%d", &p);
    g[p].push_back(i);
  }
  a[0] = s[0].size();
  all = a[0];
}
struct node {
  int l, k, id;
};
vector<node> ask[maxn];
void go(int x) {
  int p = cnt[x];
  s[p].erase(x);
  s[p + 1].insert(x);
  cnt[x]++;
  add(p + 1, 1);
  add(p, -1);
}
void roll(int x) {
  int p = cnt[x];
  s[p].erase(x);
  s[p - 1].insert(x);
  cnt[x]--;
  add(p, -1);
  add(p - 1, 1);
}
int ans[maxn];
void dfs(int u) {
  go(w[u]);
  for (node p : ask[u]) {
    int l, k, id;
    l = p.l, k = p.k, id = p.id;
    int ex = 0;
    if (l > 0) ex += qry(l - 1);
    if (ex + k > all)
      ans[id] = -1;
    else {
      int p = kth(ex + k);
      assert(s[p].size());
      ans[id] = *s[p].begin();
    }
  }
  for (int v : g[u]) dfs(v);
  roll(w[u]);
}
void sol() {
  for (int i = 1; i < n + 1; ++i) ask[i].clear();
  for (int i = 1; i < q + 1; ++i) {
    int v, l, k;
    scanf("%d%d%d", &v, &l, &k);
    ask[v].push_back((node){l, k, i});
  }
  dfs(1);
  for (int i = 1; i < q + 1; ++i) printf("%d ", ans[i]);
  printf("\n");
}
int main() {
  int T;
  cin >> T;
  while (T--) {
    init();
    sol();
  }
  return 0;
}
