#include <bits/stdc++.h>
using namespace std;
struct ST {
  vector<pair<long long, long long>> st;
  vector<long long> a, add;
  ST(vector<long long> &arr) {
    a = arr;
    st.resize(arr.size() * 4, {0, 0});
    add.resize(arr.size() * 4, 0);
    build(0, 0, arr.size());
  }
  void build(long long i, long long l, long long r) {
    if (l + 1 == r) {
      st[i] = {a[l], l};
      return;
    }
    long long m = (r + l) / 2;
    build(i * 2 + 1, l, m);
    build(i * 2 + 2, m, r);
    st[i] = max(st[i * 2 + 1], st[i * 2 + 2]);
  }
  void push(long long i, long long l, long long r) {
    st[i].first += add[i];
    if (l + 1 < r) {
      add[i * 2 + 1] += add[i];
      add[i * 2 + 2] += add[i];
    }
    add[i] = 0;
  }
  void update(long long i, long long l, long long r, long long ql, long long qr,
              long long qd) {
    push(i, l, r);
    if (ql == l && qr == r) {
      add[i] += qd;
      push(i, l, r);
      return;
    }
    long long m = (r + l) / 2;
    if (qr <= m) {
      update(i * 2 + 1, l, m, ql, qr, qd);
    } else if (ql >= m) {
      update(i * 2 + 2, m, r, ql, qr, qd);
    } else {
      update(i * 2 + 1, l, m, ql, m, qd);
      update(i * 2 + 2, m, r, m, qr, qd);
    }
    push(i * 2 + 1, l, m);
    push(i * 2 + 2, m, r);
    st[i] = max(st[i * 2 + 1], st[i * 2 + 2]);
  }
  pair<long long, long long> sum(long long i, long long l, long long r,
                                 long long ql, long long qr) {
    push(i, l, r);
    if (l == ql && r == qr) {
      return st[i];
    }
    long long m = (r + l) / 2;
    if (qr <= m) {
      return sum(i * 2 + 1, l, m, ql, qr);
    }
    if (ql >= m) {
      return sum(i * 2 + 2, m, r, ql, qr);
    }
    return max(sum(i * 2 + 1, l, m, ql, m), sum(i * 2 + 2, m, r, m, qr));
  }
};
const long long INF = (long long)1e9;
const long long MAXN = 200500;
vector<long long> g[MAXN];
long long nn[MAXN];
long long rr[MAXN];
long long nl[MAXN], nr[MAXN];
long long depth[MAXN];
long long cntv = 0;
long long pred[MAXN];
long long used[MAXN];
void dfs(long long v, long long p = MAXN - 1, long long dep = 1) {
  nl[v] = INF, nr[v] = -INF;
  pred[v] = p;
  depth[v] = dep;
  if (v != 1 && (long long)g[v].size() == 1) {
    rr[cntv] = v;
    nn[v] = cntv++;
    nl[v] = nr[v] = nn[v];
    return;
  }
  for (long long u : g[v]) {
    if (u != p) {
      dfs(u, v, dep + 1);
      nl[v] = min(nl[v], nl[u]);
      nr[v] = max(nr[v], nr[u]);
    }
  }
}
signed main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  long long n, k;
  cin >> n >> k;
  for (long long i = 0; i < n - 1; i++) {
    long long u, v;
    cin >> u >> v;
    g[u].push_back(v);
    g[v].push_back(u);
  }
  long long leaves = 0;
  for (long long v = 2; v <= n; v++) {
    if ((long long)g[v].size() == 1) {
      leaves++;
    }
  }
  if (k >= leaves) {
    long long ans = 0;
    for (long long i = leaves; i <= min(n, k); i++) {
      ans = max(ans, (n - i) * i);
    }
    cout << ans << '\n';
    return 0;
  }
  dfs(1);
  vector<long long> now(leaves);
  for (long long v = 2; v <= n; v++) {
    if ((long long)g[v].size() == 1) {
      now[nn[v]] = depth[v];
    }
  }
  ST st(now);
  long long kek = n;
  used[MAXN - 1] = 1;
  depth[MAXN - 1] = 0;
  for (long long _ = 0; _ < k; _++) {
    auto res = st.sum(0, 0, n, 0, n);
    kek -= res.first;
    long long v = rr[res.second];
    while (!used[v]) {
      used[v] = 1;
      st.update(0, 0, leaves, nl[v], nr[v] + 1, -1);
      v = pred[v];
    }
  }
  cout << (n - k - kek) * (k - kek) << '\n';
}
