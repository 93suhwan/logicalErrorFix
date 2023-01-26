#include <bits/stdc++.h>
using namespace std;
const int maxn = 202020;
int n, k;
string c;
int l[maxn], r[maxn];
vector<int> in_order;
void build_in_order(int u) {
  if (u == 0) return;
  build_in_order(l[u]);
  in_order.push_back(u);
  build_in_order(r[u]);
}
bool good[maxn];
bool duplicated[maxn];
void dfs(int u, int cost = 1) {
  if (u == 0) return;
  if (cost > k) return;
  dfs(l[u], cost + 1);
  if (duplicated[l[u]]) {
    duplicated[u] = true;
  } else if (good[u]) {
    duplicated[u] = true;
    k -= cost;
  }
  if (duplicated[u])
    dfs(r[u], 1);
  else
    dfs(r[u], cost + 1);
}
int main() {
  cin.tie(0)->sync_with_stdio(0);
  cin >> n >> k;
  cin >> c;
  c = ' ' + c;
  for (int i = 1; i <= n; ++i) {
    cin >> l[i] >> r[i];
  }
  build_in_order(1);
  char last_diff = c[in_order.back()];
  for (int i = n - 2; i >= 0; --i) {
    int u = in_order[i];
    int v = in_order[i + 1];
    if (c[u] != c[v]) {
      last_diff = c[v];
    }
    if (c[u] < last_diff) {
      good[u] = true;
    }
  }
  dfs(1);
  for (auto u : in_order) {
    cout << c[u];
    if (duplicated[u]) cout << c[u];
  }
  return 0;
}
