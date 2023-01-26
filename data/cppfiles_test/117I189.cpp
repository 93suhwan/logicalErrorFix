#include <bits/stdc++.h>
using namespace std;
template <class A, class B>
ostream& operator<<(ostream& out, const pair<A, B>& a) {
  return out << "(" << a.first << ", " << a.second << ")";
}
template <class A>
ostream& operator<<(ostream& out, const vector<A>& v) {
  out << "[";
  for (int64_t i = 0; i < v.size(); i++) {
    if (i) out << ", ";
    out << v[i];
  }
  return out << "]";
}
const int64_t mod = 998244353;
int64_t Mod(int64_t x) {
  x %= mod;
  if (x < 0) x += mod;
  return x;
}
int64_t Pow(int64_t x, int64_t n) {
  if (n == 0) return 1;
  int64_t t = Pow(x, n / 2);
  t = Mod(t * t);
  if (n & 1) t = Mod(t * x);
  return t;
}
int64_t gcd(int64_t a, int64_t b) {
  if (b == 0) return a;
  return gcd(b, a % b);
}
vector<pair<int64_t, int64_t> > get_neighbours(pair<int64_t, int64_t> pos,
                                               vector<vector<int64_t> >& vis,
                                               vector<vector<int64_t> >& a) {
  vector<int64_t> dx = {0, 0, 1, -1};
  vector<int64_t> dy = {1, -1, 0, 0};
  int64_t m = a.size(), n = a[0].size();
  vector<pair<int64_t, int64_t> > ngbrs;
  for (int64_t i = 0; i < 4; i++) {
    int64_t x = pos.first + dx[i];
    int64_t y = pos.second + dy[i];
    if (x >= 0 && y >= 0 && x < m && y < n && a[x][y] > 0)
      ngbrs.push_back({x, y});
  }
  return ngbrs;
}
void solve() {
  int64_t m, n;
  cin >> m >> n;
  vector<vector<int64_t> > a(m, vector<int64_t>(n, 1));
  pair<int64_t, int64_t> lab;
  for (int64_t i = 0; i < m; i++) {
    for (int64_t j = 0; j < n; j++) {
      char x;
      cin >> x;
      if (x == '#') a[i][j] = 0;
      if (x == 'L') lab = {i, j};
    }
  }
  vector<vector<int64_t> > vis(m, vector<int64_t>(n, 0));
  vector<vector<int64_t> > ans(m, vector<int64_t>(n, 0));
  vis[lab.first][lab.second] = 1;
  ans[lab.first][lab.second] = 1;
  queue<pair<int64_t, int64_t> > q;
  vector<pair<int64_t, int64_t> > nn = get_neighbours(lab, vis, a);
  for (auto x : nn) {
    q.push(x);
  }
  while (q.size()) {
    pair<int64_t, int64_t> x = q.front();
    q.pop();
    vector<pair<int64_t, int64_t> > ngbrs = get_neighbours(x, vis, a);
    int64_t cnt = 0;
    for (pair<int64_t, int64_t> y : ngbrs)
      if (ans[y.first][y.second]) cnt++;
    if (ngbrs.size() <= 2 or ngbrs.size() == cnt) {
      ans[x.first][x.second] = 1;
      for (pair<int64_t, int64_t> y : ngbrs) {
        if (ans[y.first][y.second]) continue;
        q.push(y);
      }
    }
  }
  for (int64_t i = 0; i < m; i++) {
    for (int64_t j = 0; j < n; j++) {
      if (a[i][j] == 0)
        cout << "#";
      else if (i == lab.first and j == lab.second)
        cout << "L";
      else if (ans[i][j])
        cout << "+";
      else
        cout << ".";
    }
    cout << endl;
  }
}
int64_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int64_t te;
  cin >> te;
  while (te--) solve();
}
