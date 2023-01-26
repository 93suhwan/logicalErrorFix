#include <bits/stdc++.h>
using namespace std;
const int MAXN = 300005;
vector<long long> g[MAXN];
long long vis[MAXN], p[MAXN], d[MAXN];
void dfs(long long v) {
  vis[v] = 1;
  for (auto i : g[v]) {
    if (!vis[i]) {
      d[i] = d[v] + 1;
      p[i] = v;
      dfs(i);
    }
  }
}
vector<long long> tr[MAXN];
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  long long n, m;
  cin >> n >> m;
  for (int i = 0, ggdem = m; i < ggdem; ++i) {
    long long x, y;
    cin >> x >> y;
    x--;
    y--;
    g[x].push_back(y);
    g[y].push_back(x);
  }
  p[0] = -1;
  dfs(0);
  for (int i = 1, ggdem = n; i < ggdem; ++i) {
    tr[p[i]].push_back(i);
  }
  vector<long long> c(n);
  vector<vector<long long>> res;
  long long q;
  cin >> q;
  while (q--) {
    long long x, y;
    cin >> x >> y;
    x--;
    y--;
    vector<long long> wx, wy;
    while (d[x] > d[y]) {
      wx.push_back(x);
      c[x] ^= 1;
      x = p[x];
    }
    while (d[y] > d[x]) {
      wy.push_back(y);
      c[y] ^= 1;
      y = p[y];
    }
    while (x != y) {
      wx.push_back(x);
      c[x] ^= 1;
      x = p[x];
      wy.push_back(y);
      c[y] ^= 1;
      y = p[y];
    }
    vector<long long> w;
    for (auto i : wx) w.push_back(i);
    w.push_back(x);
    reverse(wy.begin(), wy.end());
    for (auto i : wy) w.push_back(i);
    res.push_back(w);
  }
  long long br = 0;
  for (int i = 0, ggdem = n; i < ggdem; ++i) {
    if (c[i]) br++;
  }
  if (!br) {
    cout << "YES\n";
    for (auto i : res) {
      cout << ((int)i.size()) << "\n";
      for (auto j : i) cout << j + 1 << " ";
      cout << "\n";
    }
    return 0;
  }
  vector<pair<long long, long long>> dv;
  for (int i = 1, ggdem = n; i < ggdem; ++i) dv.push_back({d[i], i});
  sort(dv.begin(), dv.end());
  reverse(dv.begin(), dv.end());
  long long cant = 0;
  vector<long long> lz(n);
  for (auto i : dv) {
    c[i.second] ^= lz[i.second];
    if (c[i.second]) {
      cant++;
      if (p[i.second] != -1) {
        lz[p[i.second]] ^= 1;
      }
    }
    lz[p[i.second]] ^= lz[i.second];
  }
  cout << "NO\n" << (cant + 1) / 2 << "\n";
  return 0;
}
