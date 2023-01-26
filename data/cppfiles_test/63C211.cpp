#include <bits/stdc++.h>
using namespace std;
map<pair<long long, long long>, long long> mp;
vector<long long> v[10007 + 3];
vector<pair<long long, long long> > h;
map<long long, long long> vis;
long long moc[10007 + 36], din[10007 + 32], color[10007 + 32];
void dfs(long long u, long long tag, long long flag) {
  vis[u] = true;
  if (flag == -1) moc[u] = tag;
  if (flag == -2) din[u] = tag;
  for (long long i : v[u]) {
    if (!vis[i]) dfs(i, tag, flag);
  }
}
int main() {
  long long a, b, c, d, e, l = 0, x, g, r, i, j, t, k, n, y, z = 0, w;
  cin >> n;
  cin >> x >> y;
  for (i = 0; i < x; i++) {
    cin >> a >> b;
    v[a].emplace_back(b);
    v[b].emplace_back(a);
    mp[{a, b}]++;
  }
  for (long long i = 1; i <= n; i++) {
    if (!vis[i]) {
      l++;
      dfs(i, l, -1);
    }
  }
  l = 0;
  for (i = 0; i <= n; i++) v[i].clear();
  vis.clear();
  for (i = 0; i < y; i++) {
    cin >> a >> b;
    v[a].emplace_back(b);
    v[b].emplace_back(a);
    mp[{a, b}]++;
  }
  for (long long i = 1; i <= n; i++) {
    if (!vis[i]) {
      l++;
      dfs(i, l, -2);
    }
  }
  l = 0;
  for (i = 1; i <= n; i++) {
    g = 0;
    for (j = i + 1; j <= n; j++) {
      a = moc[i];
      b = moc[j];
      c = din[i];
      d = din[j];
      if (a != b && c != d) {
        h.emplace_back(i, j);
        l++;
        g++;
        break;
      }
    }
    if (g == 1) {
      for (j = 1; j <= n; j++) {
        if (moc[j] == b) moc[j] = a;
        if (din[j] == d) din[j] = c;
      }
    }
  }
  cout << l << "\n";
  for (i = 0; i < l; i++) {
    cout << h[i].first << ' ' << h[i].second << "\n";
  }
}
