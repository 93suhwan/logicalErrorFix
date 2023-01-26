#include <bits/stdc++.h>
using namespace std;
using vi = vector<int>;
using vvi = vector<vi>;
using ll = long long;
using vll = vector<ll>;
using vvll = vector<vll>;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
using vpii = vector<pii>;
using vpll = vector<pll>;
int n, q;
vi a;
vi p;
vvi children;
vi ans;
struct query {
  int l;
  int k;
  int i;
};
vector<vector<query>> queries;
vi occ;
struct val {
  int v;
};
bool operator<(val A, val B) {
  if (occ[A.v] != occ[B.v])
    return occ[A.v] < occ[B.v];
  else
    return A.v < B.v;
}
set<val> V;
vector<vector<int>> occ_list;
struct segtree {
  int l;
  int r;
  int sm = 0;
  segtree* left = NULL;
  segtree* right = NULL;
  segtree() { ; }
  segtree(int L, int R) {
    l = L;
    r = R;
    if (l == r) return;
    int m = (l + r) / 2;
    left = new segtree(l, m);
    right = new segtree(m + 1, r);
  }
  void add(int I, int V) {
    if (l == r)
      sm += V;
    else {
      sm += V;
      if (I <= (l + r) / 2)
        left->add(I, V);
      else
        right->add(I, V);
    }
  }
  int rangesum(int L, int R) {
    if (R < l || r < L)
      return 0;
    else if (L <= l && r <= R)
      return sm;
    else
      return left->rangesum(L, R) + right->rangesum(L, R);
  }
  int max_pos(int u) {
    if (l == r)
      return l;
    else if (right->sm >= u)
      return right->max_pos(u);
    else
      return left->max_pos(u - right->sm);
  }
};
segtree ST;
void change_value(int v, int ch) {
  ST.add(occ[v], -1);
  occ[v] += ch;
  occ_list[occ[v]].push_back(v);
  ST.add(occ[v], +1);
}
void dfs(int u) {
  change_value(a[u], +1);
  for (auto qr : queries[u]) {
    int badval = ST.rangesum(0, qr.l - 1);
    int goodval = n - badval;
    if (goodval < qr.k) {
      ans[qr.i] = -1;
      continue;
    }
    int good_occ = ST.max_pos(goodval - qr.k + 1);
    while (occ[occ_list[good_occ].back()] != good_occ)
      occ_list[good_occ].pop_back();
    ans[qr.i] = occ_list[good_occ].back();
  }
  for (int v : children[u]) dfs(v);
  change_value(a[u], -1);
}
void run() {
  cin >> n >> q;
  a = vi(1 + n);
  p = vi(1 + n);
  children = vvi(1 + n);
  ans = vi(1 + q);
  queries = vector<vector<query>>(1 + n);
  occ_list = vector<vector<int>>(1 + n);
  for (int i = 1; i <= n; i++) cin >> a[i];
  for (int i = 2; i <= n; i++) {
    cin >> p[i];
    children[p[i]].push_back(i);
  }
  for (int i = 1; i <= q; i++) {
    int v, l, k;
    cin >> v >> l >> k;
    queries[v].push_back(query{l, k, i});
  }
  occ = vi(1 + n, 0);
  occ[0] = n;
  ST = segtree(0, n);
  for (int i = 0; i <= n; i++) ST.add(i, occ[i]);
  for (int i = 1; i <= n; i++) occ_list[occ[i]].push_back(i);
  dfs(1);
  for (int j = 1; j <= q; j++) cout << ans[j] << ' ';
  cout << '\n';
}
bool multitest = 1;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int t;
  if (multitest)
    cin >> t;
  else
    t = 1;
  while (t--) run();
}
