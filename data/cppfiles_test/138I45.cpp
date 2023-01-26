#include <bits/stdc++.h>
using namespace std;
const int MAXN = 4e5 + 5;
pair<int, bool> num[MAXN];
long long ps[MAXN], ans[MAXN];
int for_mon[MAXN], par[MAXN];
pair<int, int> k[MAXN], adj[MAXN];
int get_par(int v) {
  if (par[v] < 0) return v;
  return par[v] = get_par(par[v]);
}
bool merge(int v, int u) {
  v = get_par(v), u = get_par(u);
  if (v == u) return false;
  if (par[v] > par[u]) swap(v, u);
  par[v] += par[u];
  par[u] = v;
  for_mon[v] += for_mon[u];
  return true;
}
int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  memset(par, -1, sizeof par);
  int n, m, q;
  cin >> n >> m >> q;
  for (int i = 0; i < n; i++) {
    int a;
    cin >> a;
    num[i] = {a, true};
  }
  for (int i = 0; i < m; i++) {
    int b;
    cin >> b;
    num[n + i] = {b, false};
  }
  sort(num, num + n + m);
  for (int i = 1; i <= n + m; i++) ps[i] = ps[i - 1] + num[i - 1].first;
  for (int i = 0; i < n + m; i++) {
    for_mon[i] = num[i].second;
    adj[i] = {num[i + 1].second - num[i].second, i};
  }
  for (int i = 0; i < q; i++) {
    cin >> k[i].first;
    k[i].second = i;
  }
  sort(k, k + q);
  sort(adj, adj + n + m - 1);
  int ptr = 0;
  for (int i = 0; i < q; i++) {
    int cur = k[i].first;
    long long sum = 0;
    while (ptr < n + m - 1 && adj[ptr].first <= cur) {
      int ind = adj[ptr].second;
      merge(ind, ind + 1);
      int parent = get_par(ind);
      sum += ps[ind + 1] - ps[ind + 1 - for_mon[(parent < 0 ? ind : parent)]];
      ptr++;
    }
    ans[k[i].second] = sum;
  }
  for (int i = 0; i < q; i++) cout << ans[i] << '\n';
}
