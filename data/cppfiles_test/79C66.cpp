#include <bits/stdc++.h>
using namespace std;
vector<long long> a, b;
long long vis[300005], d[300005][2];
pair<long long, long long> p[300005][2];
long long n;
void bfs() {
  long long uvis = n + 1;
  queue<pair<long long, long long>> q;
  q.push({n, 0});
  vis[n] = 1;
  p[n][0] = {-1, -1};
  while (((int)q.size())) {
    auto f = q.front();
    q.pop();
    if (!f.first) continue;
    if (f.second == 1) {
      long long x = f.first + b[f.first - 1];
      if (!vis[x]) {
        q.push({x, 0});
        vis[x] = 1;
        d[x][0] = d[f.first][f.second] + 1;
        p[x][0] = f;
      }
    } else {
      for (int i = f.first - a[f.first - 1], ggdem = uvis; i < ggdem; ++i) {
        q.push({i, 1});
        d[i][1] = d[f.first][f.second] + 1;
        p[i][1] = f;
      }
      uvis = min(f.first - a[f.first - 1], uvis);
    }
  }
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cin >> n;
  a.resize(n);
  b.resize(n);
  for (int i = 0, ggdem = n; i < ggdem; ++i) cin >> a[i];
  for (int i = 0, ggdem = n; i < ggdem; ++i) cin >> b[i];
  d[0][1] = 1e18;
  bfs();
  auto res = d[0][1];
  if (res > 1e17) {
    cout << "-1\n";
    return 0;
  }
  cout << (res + 1) / 2 << "\n";
  vector<long long> vres;
  long long va = 0;
  while (va != -1) {
    vres.push_back(va);
    va = p[va][1].first;
    va = p[va][0].first;
  }
  reverse(vres.begin(), vres.end());
  for (auto i : vres) cout << i << " ";
  cout << "\n";
  return 0;
}
