#include <bits/stdc++.h>
#pragma GCC optimize("O3")
using namespace std;
void eras(map<int, int> &m, int x) {
  m[x]--;
  if (!m[x]) m.erase(x);
}
const int N = (int)2e5 + 100;
const int M = (int)1e7 + 10;
const int inf = (int)1e7 + 10000;
const double eps = 1e-9;
vector<int> v[N], g[N];
int was[N];
pair<int, int> dfs(int x, int c = 0) {
  was[x] = c + 1;
  pair<int, int> o = {0, 0};
  if (c)
    o.second++;
  else
    o.first++;
  for (auto y : v[x]) {
    if (was[y]) {
      if (was[y] != was[x]) return {-1, -1};
      continue;
    }
    pair<int, int> t = dfs(y, c);
    if (t.first == -1) return {-1, -1};
    o.first += t.first;
    o.second += t.second;
  }
  for (auto y : g[x]) {
    if (was[y]) {
      if (was[y] == was[x]) return {-1, -1};
      continue;
    }
    pair<int, int> t = dfs(y, 1 - c);
    if (t.first == -1) return {-1, -1};
    o.first += t.first;
    o.second += t.second;
  }
  return o;
}
int main() {
  mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
  srand(time(0));
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int T;
  cin >> T;
  while (T--) {
    int n, m, i, j;
    cin >> n >> m;
    for ((i) = 0; (i) < (m); (i)++) {
      int a, b;
      string c;
      cin >> a >> b >> c;
      a--;
      b--;
      if (c[0] != 'i') {
        v[a].push_back(b);
        v[b].push_back(a);
      } else {
        g[a].push_back(b);
        g[b].push_back(a);
      }
    }
    int ans = 0;
    for ((i) = 0; (i) < (n); (i)++) {
      if (was[i]) continue;
      pair<int, int> c = dfs(i);
      if (c.first == -1) {
        ans = -1;
        break;
      }
      ans += max(c.first, c.second);
    }
    cout << ans << '\n';
    for ((i) = 0; (i) < (n); (i)++) {
      was[i] = 0;
      g[i].clear();
      v[i].clear();
    }
  }
}
