#include <bits/stdc++.h>
using namespace std;
template <typename T>
int smin(T& a, const T& b) {
  return b < a ? a = b, 1 : 0;
}
template <typename T>
int smax(T& a, const T& b) {
  return b > a ? a = b, 1 : 0;
}
mt19937_64 rng;
const int MX = 2e5 + 10;
const char nl = '\n';
void solve() {
  int n;
  cin >> n;
  vector<int> a(n + 1), b(n + 1);
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  for (int i = 1; i <= n; i++) {
    cin >> b[i];
  }
  set<int> todo;
  for (int i = 0; i < n; i++) {
    todo.insert(i);
  }
  vector<array<pair<int, int>, 2>> parent(n + 1);
  vector<array<bool, 2>> vis(n + 1);
  vis[n][1] = true;
  deque<pair<int, int>> dq;
  dq.push_back({n, 1});
  while (((int)(dq.size()))) {
    auto [v, t] = dq.front();
    dq.pop_front();
    if (t == 1) {
      while (true) {
        auto it = todo.upper_bound(v);
        if (it == todo.begin()) {
          break;
        }
        --it;
        if (*it < v - a[v]) {
          break;
        }
        int u = *it;
        todo.erase(u);
        if (!vis[u][0]) {
          vis[u][0] = true;
          parent[u][0] = {v, t};
          dq.push_back({u, 0});
        }
      }
    } else {
      int u = v + b[v];
      if (!vis[u][1]) {
        vis[u][1] = true;
        parent[u][1] = {v, t};
        dq.push_front({u, 1});
      }
    }
  }
  if (!vis[0][0]) {
    cout << "-1\n";
    return;
  }
  vector<int> path;
  int v = 0, t = 0;
  while (true) {
    if (t == 0) {
      path.push_back(v);
    }
    if (v == n) {
      break;
    }
    auto [x, y] = parent[v][t];
    v = x;
    t = y;
  }
  reverse(path.begin(), path.end());
  cout << ((int)(path.size())) << nl;
  for (int d : path) {
    cout << d << " ";
  }
  cout << nl;
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int te = 1;
  while (te--) {
    solve();
  }
  return 0;
}
