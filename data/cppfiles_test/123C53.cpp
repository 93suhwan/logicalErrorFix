#include <bits/stdc++.h>
using namespace std;
const int inf = 1000000007;
const int maxn = 200010;
vector<int> g[maxn];
vector<pair<int, int> > vt;
int lenu[maxn], sonu[maxn];
void dfs(int u, int f) {
  sonu[u] = u;
  lenu[u] = 0;
  for (int i = 0; i < g[u].size(); ++i) {
    int v = g[u][i];
    if (v != f) {
      dfs(v, u);
      if (lenu[sonu[v]] > lenu[sonu[u]]) {
        sonu[u] = sonu[v];
      }
    }
  }
  for (int i = 0; i < g[u].size(); ++i) {
    int v = g[u][i];
    if (v != f && sonu[u] != sonu[v]) {
      vt.emplace_back(sonu[v], lenu[sonu[v]]);
    }
  }
  lenu[sonu[u]]++;
}
long long solve(int n, int k) {
  dfs(1, 0);
  vt.emplace_back(sonu[1], lenu[sonu[1]]);
  sort(vt.begin(), vt.end(),
       [](const pair<int, int>& x, const pair<int, int>& y) {
         return x.second > y.second;
       });
  if (k >= vt.size()) {
    long long r = min(k, n / 2);
    if (r < vt.size()) {
      r = vt.size();
    }
    long long w = n - r;
    return w * r;
  }
  long long r = k, b = 0, w = n - k;
  for (int i = k; i < vt.size(); ++i) {
    b += vt[i].second;
    w -= vt[i].second;
  }
  auto three = [&]() {
    long long bx = 0, by = b;
    while (by > bx) {
      long long b1 = bx + (by - bx) / 3, b2 = by - (by - bx) / 3;
      long long r1 = (w + (b - b1)) * (r - b1);
      long long r2 = (w + (b - b2)) * (r - b2);
      if (r1 > r2) {
        bx = b1 + 1;
      } else {
        by = b2 - 1;
      }
    }
    w += b - bx;
    b = by;
    return w * (r - b);
  };
  return three();
}
int main() {
  int n, k, u, v;
  cin >> n >> k;
  for (int i = 1; i < n; ++i) {
    scanf("%d %d", &u, &v);
    g[u].push_back(v);
    g[v].push_back(u);
  }
  cout << solve(n, k) << endl;
  return 0;
}
