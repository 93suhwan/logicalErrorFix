#include <bits/stdc++.h>
using namespace std;
const int N = 1000006, INF = 1e9, P = 998244353;
int n, m, ans = INF, tree[4 * N], E[4 * N];
pair<int, pair<int, int> > p[N];
void push(int v, int tl, int tr) {
  if (E[v] != 0 && v * 2 + 1 < 4 * N) {
    E[v << 1] += E[v];
    E[v << 1 ^ 1] += E[v];
    tree[v << 1] += E[v];
    tree[v << 1 ^ 1] += E[v];
    E[v] = 0;
  }
}
void add(int l, int r, int val, int v, int tl, int tr) {
  if (l <= tl && tr <= r) {
    tree[v] += val;
    E[v] += val;
    return;
  }
  if (tr < l || r < tl) return;
  push(v, tl, tr);
  int tm = tl + tr >> 1;
  add(l, r, val, v << 1, tl, tm);
  add(l, r, val, v << 1 ^ 1, tm + 1, tr);
  if (tree[v << 1] < tree[v << 1 ^ 1])
    tree[v] = tree[v << 1];
  else
    tree[v] = tree[v << 1 ^ 1];
}
int main() {
  cin >> n >> m;
  m--;
  for (int i = 1; i <= n; i++) {
    cin >> p[i].second.first >> p[i].second.second >> p[i].first;
    p[i].second.first--;
    p[i].second.second -= 2;
  }
  sort(p + 1, p + n + 1);
  int R = 1;
  for (int i = 1; i <= n; i++) {
    while (!tree[1] && R <= n)
      add(p[R].second.first, p[R].second.second, 1, 1, 0, m - 1), R++;
    if (!tree[1]) break;
    ans = min(p[R - 1].first - p[i].first, ans);
    add(p[i].second.first, p[i].second.second, -1, 1, 0, m - 1);
  }
  cout << ans;
}
