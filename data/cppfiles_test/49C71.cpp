#include <bits/stdc++.h>
using namespace std;
void solve(int __) {
  int n, q;
  cin >> n >> q;
  vector<vector<int>> G(n + 1);
  vector<int> t(n + 1, 0), a(n + 1), c(n + 1, 0), ans(q);
  vector<set<int>> S(n + 1);
  vector<vector<array<int, 3>>> Q(n + 1);
  int al = 0;
  for (int i = 1; i <= n; ++i) {
    cin >> a[i];
    S[0].insert(i);
  }
  for (int i = 2, p; i <= n; ++i) {
    cin >> p;
    G[p].push_back(i);
  }
  for (int i = 0, v, l, k; i < q; ++i) {
    cin >> v >> l >> k;
    Q[v].push_back({--l, k, i});
  }
  auto upd = [&](int x, int v) {
    for (; x <= n; x += x & -x) t[x] += v;
  };
  auto add = [&](int x, int v) {
    S[c[x]].erase(S[c[x]].find(x));
    if (c[x]) upd(c[x], -1);
    c[x] += v;
    if (c[x]) upd(c[x], 1);
    S[c[x]].insert(x);
    if (c[x] == 1 && v == 1) ++al;
    if (c[x] == 0 && v == -1) --al;
  };
  auto sum = [&](int x) {
    int ret = 0;
    for (; x; x -= x & -x) ret += t[x];
    return ret;
  };
  auto kmin = [&](int k) {
    int Ans = 0, cnt = 0;
    for (int i = 20; ~i; --i) {
      Ans += 1 << i;
      if (Ans > n || cnt + t[Ans] >= k) {
        Ans -= 1 << i;
      } else {
        cnt += t[Ans];
      }
    }
    return Ans + 1;
  };
  function<void(int)> dfs = [&](int u) {
    add(a[u], 1);
    for (auto& [l, k, i] : Q[u]) {
      k += sum(l);
      if (k > al) {
        ans[i] = -1;
      } else {
        ans[i] = *S[kmin(k)].begin();
      }
    }
    for (int v : G[u]) {
      dfs(v);
    }
    add(a[u], -1);
  };
  dfs(1);
  for (int i = 0; i < q; ++i) cout << ans[i] << " \n"[i == q - 1];
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  for (int QAQ = 0, __ = 1;
       (QAQ > 0 ? __ <= QAQ : static_cast<bool>(cin >> QAQ)); ++__) {
    solve(__);
  }
}
