#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 5;
int n, k, l[N], r[N], ls;
bool f[N], vis[N];
char c[N];
vector<int> a;
void back(int u) {
  if (!u) return;
  back(l[u]);
  a.push_back(u);
  back(r[u]);
}
void dfs(int u, int sum) {
  if (!u || sum > k) return;
  dfs(l[u], sum + 1);
  if (vis[l[u]])
    vis[u] = 1;
  else if (f[u])
    vis[u] = 1, k -= sum;
  if (vis[u]) dfs(r[u], 1);
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  cin >> n >> k >> (c + 1);
  for (int i = 1; i <= n; i++) cin >> l[i] >> r[i];
  back(1);
  ls = 0;
  c[0] = 0;
  for (int i = n - 2; i >= 0; i--) {
    int u = a[i], v = a[i + 1];
    if (c[u] != c[v]) ls = v;
    if (c[u] < c[ls]) f[u] = 1;
  }
  dfs(1, 1);
  for (auto i : a) {
    cout << c[i];
    if (vis[i]) cout << c[i];
  }
  return 0;
}
