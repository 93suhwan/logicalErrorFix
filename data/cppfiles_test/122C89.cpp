#include <bits/stdc++.h>
using namespace std;
template <typename T>
using vec = vector<T>;
template <typename T, typename V = vector<T>, typename C = less<T> >
using pQ = priority_queue<T, V, C>;
template <typename t>
ostream& operator<<(ostream& os, vector<t> v) {
  for (int i = 0; i < v.size(); i++) {
    os << v[i] << " ";
  }
  return os;
}
template <typename t>
istream& operator>>(istream& is, vector<t>& v) {
  for (int i = 0; i < v.size(); i++) {
    is >> v[i];
  }
  return is;
}
void solve() {
  int N, M;
  cin >> N >> M;
  vector<vector<pair<long long int, long long int> > > t(N);
  vector<vector<pair<long long int, long long int> > > g(N);
  vector<int> val(N);
  vector<bool> vis(N, 0);
  queue<int> q;
  for (int i = 0; i < N - 1; i++) {
    int a, b, v;
    cin >> a >> b >> v;
    a--;
    b--;
    t[a].push_back({b, v});
    t[b].push_back({a, v});
  }
  q.push(0);
  while (!q.empty()) {
    int x = q.front();
    q.pop();
    for (auto [y, v] : t[x])
      if (!vis[y]) {
        vis[y] = 1;
        q.push(y);
        if (v != -1) {
          v = __builtin_popcount(v) % 2;
          g[x].push_back({y, v});
          g[y].push_back({x, v});
        }
      }
  }
  while (M--) {
    int a, b, v;
    cin >> a >> b >> v;
    a--;
    b--;
    g[a].push_back({b, v});
    g[b].push_back({a, v});
  }
  vis.assign(N, 0);
  for (int x = 0; x < N; x++)
    if (!vis[x]) {
      q.push(x);
      vis[x] = 1;
      val[x] = 0;
      while (!q.empty()) {
        int x = q.front();
        q.pop();
        for (auto [y, v] : g[x]) {
          if (!vis[y]) {
            val[y] = val[x] ^ v;
            vis[y] = 1;
            q.push(y);
          } else if (val[y] != val[x] ^ v) {
            cout << "NO\n";
            return;
          }
        }
      }
    }
  q.push(0);
  vis.assign(N, 0);
  vis[0] = 1;
  cout << "YES\n";
  while (!q.empty()) {
    int x = q.front();
    q.pop();
    for (auto [y, v] : t[x])
      if (!vis[y]) {
        cout << x + 1 << " " << y + 1 << " "
             << (v == -1 ? bool(val[y] != val[x]) : v) << "\n";
        vis[y] = true;
        q.push(y);
      }
  }
}
int main() {
  int t = 1;
  cin >> t;
  while (t--) {
    solve();
  }
}
