#include <bits/stdc++.h>
using namespace std;
struct AC {
  int v, next;
};
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n, m;
  cin >> n >> m;
  vector<pair<int, int>> q;
  vector<int> d(n + 1, -1);
  vector<AC> v;
  int idx = 0;
  function<void(int, int)> add = [&](int a, int b) {
    AC it = {b, d[a]};
    v.emplace_back(it);
    d[a] = idx++;
  };
  vector<int> flag(n + 1);
  for (int i = 1; i <= m; i++) {
    int a, b;
    cin >> a >> b;
    add(a, b);
    add(b, a);
  }
  vector<int> dep(n + 1);
  vector<int> to_fa(n + 1);
  function<void(int, int)> dfs = [&](int now, int fa) {
    dep[now] = dep[fa] + 1;
    to_fa[now] = fa;
    for (int i = d[now]; i != -1; i = v[i].next) {
      int to = v[i].v;
      if (dep[to] == 0 && to != fa) {
        dfs(to, now);
      }
    }
  };
  dfs(1, 0);
  function<void(int, int)> solve = [&](int a, int b) {
    if (dep[a] > dep[b]) swap(a, b);
    vector<int> ans1, ans2;
    while (dep[b] != dep[a]) {
      ans2.emplace_back(b);
      b = to_fa[b];
    }
    while (a != b) {
      ans1.emplace_back(a);
      ans2.emplace_back(b);
      a = to_fa[a];
      b = to_fa[b];
    }
    ans1.emplace_back(a);
    cout << ans1.size() + ans2.size() << '\n';
    for (auto it : ans1) {
      cout << it << ' ';
    }
    for (int i = ans2.size() - 1; i >= 0; i--) {
      cout << ans2[i] << ' ';
    }
    cout << '\n';
  };
  int T;
  cin >> T;
  while (T--) {
    int a, b;
    cin >> a >> b;
    flag[a]++;
    flag[b]++;
    q.emplace_back(make_pair(a, b));
  }
  int pre = 0;
  for (int i = 1; i <= n; i++) {
    if (flag[i] & 1) pre++;
  }
  if (pre != 0) {
    cout << "NO" << '\n';
    cout << pre / 2 << '\n';
    return 0;
  }
  cout << "YES" << '\n';
  for (auto it : q) {
    int a = it.first;
    int b = it.second;
    solve(a, b);
  }
  return 0;
}
