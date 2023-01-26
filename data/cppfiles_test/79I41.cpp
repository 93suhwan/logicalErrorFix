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
const int MX = 3e5 + 10;
const char nl = '\n';
int n, a[MX], b[MX];
pair<int, int> p[MX][2];
void solve() {
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  for (int i = 1; i <= n; i++) {
    cin >> b[i];
  }
  for (int i = 0; i < MX; i++) {
    for (int j = 0; j < 2; j++) {
      p[i][j] = {-1, -1};
    }
  }
  deque<pair<int, int> > qu;
  qu.push_back({n, 0});
  p[n][0] = {-2, -2};
  while (((int)(qu.size()))) {
    auto [v, t] = qu.front();
    qu.pop_front();
    if (t == 0) {
      if (p[v - a[v]][1].first == -1) {
        p[v - a[v]][1] = {v, t};
        qu.push_back({v - a[v], 1});
      }
      continue;
    }
    if (v < n) {
      if (p[v + 1][1].first == -1) {
        p[v + 1][1] = {v, t};
        qu.push_front({v + 1, 1});
      }
      if (p[v + b[v]][0].first == -1) {
        p[v + b[v]][0] = {v, t};
        qu.push_front({v + b[v], 0});
      }
    }
  }
  if (p[0][1].first == -1) {
    cout << "-1\n";
    return;
  }
  vector<pair<int, int> > path;
  int v = 0, t = 1;
  while (v != -2) {
    path.push_back({v, t});
    auto [x, y] = p[v][t];
    v = x;
    t = y;
  }
  reverse(path.begin(), path.end());
  vector<int> print;
  int m = ((int)(path.size()));
  for (int i = 0; i < m; i++) {
    auto [v, t] = path[i];
    if (t == 0) {
      int now = v - a[v];
      int j = i + 1;
      while (j < m && path[j].second == 1) {
        ++now;
        j++;
      }
      print.push_back(now - 1);
    }
  }
  cout << ((int)(print.size())) << nl;
  for (int x : print) {
    cout << x << " ";
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
