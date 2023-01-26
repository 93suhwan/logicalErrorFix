#include <bits/stdc++.h>
using namespace std;
void err() { cout << endl; }
template <class T, class... Ts>
void err(T arg, Ts &...args) {
  cout << arg << ' ';
  err(args...);
}
const int N = 4e5 + 10;
const long long mod = 1e9 + 7;
mt19937 mt(chrono::steady_clock::now().time_since_epoch().count());
long long rng(long long l, long long r) {
  uniform_int_distribution<long long> uni(l, r);
  return uni(mt);
}
int a[N];
long long pre[N];
int b[N];
long long sum;
long long ans[N];
long long calc(long long r, long long x) { return pre[r] - pre[r - x]; }
struct query {
  int k, id;
  bool operator<(const query &ano) const { return k < ano.k; }
} Q[N];
struct DSU {
  int f[N];
  struct node {
    int l, r;
    int cnt;
  } info[N];
  void init(int n) {
    for (int i = 1; i <= n; ++i) {
      f[i] = -1;
      info[i].l = info[i].r = i;
      info[i].cnt = b[i];
      sum += calc(i, b[i]);
    }
  }
  int find(int x) { return f[x] < 0 ? x : f[x] = find(f[x]); }
  void merge(int x, int y) {
    int fx = find(x);
    int fy = find(y);
    if (fx == fy) return;
    if (f[fx] > f[fy]) swap(fx, fy);
    f[fx] += f[fy];
    f[fy] = fx;
    sum -= calc(info[fy].r, info[fy].cnt);
    sum -= calc(info[fx].r, info[fx].cnt);
    int l = min(info[fx].l, info[fy].l);
    int r = max(info[fx].r, info[fy].r);
    info[fx].cnt += info[fy].cnt;
    info[fx].l = l, info[fx].r = r;
    sum += calc(info[fx].r, info[fx].cnt);
  }
} dsu;
void solve(int tCase) {
  int n, m, q;
  cin >> n >> m >> q;
  vector<pair<int, int>> vec;
  for (int i = 1; i <= n; ++i) {
    int tmp;
    cin >> tmp;
    vec.emplace_back(tmp, 1);
  }
  for (int i = 1; i <= m; ++i) {
    int tmp;
    cin >> tmp;
    vec.emplace_back(tmp, 0);
  }
  sort(vec.begin(), vec.end());
  vector<pair<int, int>> edges;
  for (int i = 1; i <= n + m; ++i) {
    a[i] = vec[i - 1].first;
    b[i] = vec[i - 1].second;
    pre[i] = pre[i - 1] + a[i];
    if (i > 1) edges.emplace_back(a[i] - a[i - 1], i);
  }
  sort(edges.begin(), edges.end());
  for (int i = 1; i <= q; ++i) {
    cin >> Q[i].k;
    Q[i].id = i;
  }
  sort(Q + 1, Q + 1 + q);
  dsu.init(n + m);
  int now = 0;
  for (int i = 1; i <= q; ++i) {
    while (now < n + m - 1 && edges[now].first <= Q[i].k) {
      dsu.merge(edges[now].second - 1, edges[now].second);
      now++;
    }
    ans[Q[i].id] = sum;
  }
  for (int i = 1; i <= q; ++i) {
    cout << ans[i] << '\n';
  }
}
int main() {
  ios_base::sync_with_stdio(false);
  int T = 1;
  for (int t = 1; t <= T; ++t) {
    solve(t);
  }
  return 0;
}
