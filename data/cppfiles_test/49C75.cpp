#include <bits/stdc++.h>
#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("avx,avx2,fma")
using namespace std;
using ll = long long;
using ii = pair<int, int>;
using ull = unsigned long long;
using db = long double;
const int N = 1e6 + 5, LG = 18, MOD = 1e9 + 7;
const long double PI = acos(-1);
int t[N << 2];
int a[N], n, q;
vector<vector<int>> adj;
vector<vector<int>> qr;
int v[N], l[N], k[N];
int ans[N];
vector<int> go[N];
int freq[N];
void update(int node, int s, int e, int index, int val) {
  if (s == e) {
    t[node] += val;
    return;
  }
  int md = (s + e) >> 1;
  if (index <= md)
    update(node << 1, s, md, index, val);
  else
    update(node << 1 | 1, md + 1, e, index, val);
  t[node] = t[node << 1] + t[node << 1 | 1];
}
int query(int node, int s, int e, int l, int r) {
  if (r < s || e < l || l > r) return 0;
  if (l <= s && e <= r) {
    return t[node];
  }
  int md = (s + e) >> 1;
  return query(node << 1, s, md, l, r) + query(node << 1 | 1, md + 1, e, l, r);
}
int bsearch(int node, int s, int e, int k) {
  if (s == e) return s;
  int md = (s + e) >> 1;
  if (t[node << 1] >= k) return bsearch(node << 1, s, md, k);
  return bsearch(node << 1 | 1, md + 1, e, k - t[node << 1]);
}
void upd(int x, int v) {
  if (freq[x]) {
    update(1, 1, 1000000, freq[x], -1);
  }
  freq[x] += v;
  if (freq[x]) {
    go[freq[x]].push_back(x);
    update(1, 1, 1000000, freq[x], +1);
  }
}
void dfs(int node) {
  upd(a[node], +1);
  for (auto q : qr[node]) {
    k[q] += query(1, 1, 1000000, 1, l[q] - 1);
    if (t[1] < k[q]) {
      ans[q] = -1;
      continue;
    }
    ans[q] = bsearch(1, 1, 1000000, k[q]);
    int x = ans[q];
    while (freq[go[x].back()] != x) go[x].pop_back();
    ans[q] = go[x].back();
  }
  for (auto v : adj[node]) dfs(v);
  upd(a[node], -1);
}
void doWork() {
  cin >> n >> q;
  adj.assign(n + 1, vector<int>());
  qr.assign(n + 1, vector<int>());
  for (int i = 1; i < n + 1; i++) cin >> a[i];
  for (int i = 2; i < n + 1; i++) {
    int p;
    cin >> p;
    adj[p].push_back(i);
  }
  for (int i = 0; i < q; i++) {
    cin >> v[i] >> l[i] >> k[i];
    qr[v[i]].push_back(i);
  }
  dfs(1);
  for (int i = 0; i < q; i++) cout << ans[i] << " \n"[i + 1 == q];
  for (int i = 0; i < n + 1; i++) go[i].clear(), go[i].shrink_to_fit();
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int t = 1;
  cin >> t;
  while (t--) {
    doWork();
  }
  return 0;
}
