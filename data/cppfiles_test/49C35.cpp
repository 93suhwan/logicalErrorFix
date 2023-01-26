#include <bits/stdc++.h>
using namespace std;
const int kN = 1e6;
int n, P, a[1 + kN], cnt[1 + kN], aib[1 + kN], sol[kN];
vector<int> g[1 + kN];
vector<tuple<int, int, int>> queries[1 + kN];
set<int> freq[1 + kN];
void update(int x, int t) {
  for (int i = x; i <= n; i += i & -i) {
    aib[i] += t;
  }
}
int query(int x) {
  int ans = 0;
  for (int i = x; i > 0; i = i & (i - 1)) {
    ans += aib[i];
  }
  return ans;
}
void dfs(int u) {
  int f = cnt[a[u]];
  if (f) {
    freq[f].erase(a[u]);
    update(f, -1);
  }
  ++f;
  cnt[a[u]] = f;
  freq[f].emplace(a[u]);
  update(f, 1);
  for (auto it : queries[u]) {
    int l, k, index;
    tie(l, k, index) = it;
    int erased = query(l - 1);
    int rem = query(n) - erased;
    if (rem < k) {
      continue;
    }
    int ans = 0, sum = -erased, step = P;
    while (step) {
      if ((ans | step) < n && sum + aib[ans | step] < k) {
        ans |= step;
        sum += aib[ans];
      }
      step /= 2;
    }
    sol[index] = *freq[ans + 1].begin();
  }
  for (int v : g[u]) {
    dfs(v);
  }
  freq[f].erase(a[u]);
  update(f, -1);
  --f;
  cnt[a[u]] = f;
  if (f) {
    freq[f].emplace(a[u]);
    update(f, 1);
  }
}
void testCase() {
  int q;
  cin >> n >> q;
  for (int i = 1; i <= n; ++i) {
    cin >> a[i];
    g[i].clear();
    queries[i].clear();
  }
  for (int v = 2; v <= n; ++v) {
    int u;
    cin >> u;
    g[u].emplace_back(v);
  }
  for (int i = 0; i < q; ++i) {
    int v, l, k;
    cin >> v >> l >> k;
    queries[v].emplace_back(l, k, i);
    sol[i] = -1;
  }
  P = 1;
  while (P * 2 <= n) {
    P *= 2;
  }
  dfs(1);
  for (int i = 0; i < q; ++i) {
    cout << sol[i] << ' ';
  }
  cout << '\n';
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int tests;
  cin >> tests;
  for (int tc = 0; tc < tests; ++tc) {
    testCase();
  }
  return 0;
}
