#include <bits/stdc++.h>
using namespace std;
using LL = long long;
int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int n, m, q;
  cin >> n >> m >> q;
  LL cur = 0;
  vector<LL> a(n), b(m), k(q), ans(q);
  vector<pair<LL, int>> vp;
  for (LL& x : a) {
    cin >> x;
    vp.emplace_back(x, 1);
    cur += x;
  }
  for (LL& x : b) {
    cin >> x;
    vp.emplace_back(x, 0);
  }
  sort(vp.begin(), vp.end());
  vector<LL> sum(n + m);
  vector<int> cnt(n + m);
  for (int i = 0; i < n + m; i += 1) {
    sum[i] = vp[i].first;
    if (i) sum[i] += sum[i - 1];
    cnt[i] = vp[i].second;
    if (i) cnt[i] += cnt[i - 1];
  }
  vector<LL> pre(n + m), nxt(n + m);
  vector<int> f(n + m - 1);
  for (int i = 0; i < n + m; i += 1) {
    pre[i] = nxt[i] = i;
    if (i) f[i - 1] = i - 1;
  }
  sort(f.begin(), f.end(), [&](int x, int y) {
    return vp[x + 1].first - vp[x].first < vp[y + 1].first - vp[y].first;
  });
  for (LL& x : k) cin >> x;
  vector<int> g(q);
  for (int i = 0; i < q; i += 1) g[i] = i;
  sort(g.begin(), g.end(), [&](int x, int y) { return k[x] < k[y]; });
  function<int(int)> getp = [&](int u) {
    return pre[u] == u ? u : pre[u] = getp(pre[u]);
  };
  function<int(int)> getn = [&](int u) {
    return nxt[u] == u ? u : nxt[u] = getn(nxt[u]);
  };
  auto get = [&](int i) {
    int L = getp(i), R = getn(i);
    int c = cnt[R];
    if (L) c -= cnt[L - 1];
    LL res = sum[R];
    if (R - c >= 0) res -= sum[R - c];
    return res;
  };
  for (int i = 0, j = 0; i < q; i += 1) {
    while (j < n + m - 1 and vp[f[j] + 1].first - vp[f[j]].first <= k[g[i]]) {
      cur -= get(f[j]) + get(f[j] + 1);
      nxt[f[j]] = f[j] + 1;
      pre[f[j] + 1] = f[j];
      cur += get(f[j]);
      j += 1;
    }
    ans[g[i]] = cur;
  }
  for (LL x : ans) cout << x << "\n";
  return 0;
}
