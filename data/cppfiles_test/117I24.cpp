#include <bits/stdc++.h>
using namespace std;
template <typename T>
istream& operator>>(istream& in, vector<T>& a) {
  for (int i = 0; i < a.size(); ++i) in >> a[i];
  return in;
}
template <typename T>
ostream& operator<<(ostream& out, vector<T>& a) {
  for (T i : a) out << i << ' ';
  return out;
}
template <typename T1, typename T2>
istream& operator>>(istream& in, pair<T1, T2>& p) {
  in >> p.first >> p.second;
  return in;
}
template <typename T1, typename T2>
ostream& operator<<(ostream& out, pair<T1, T2>& p) {
  out << p.first << ' ' << p.second;
  return out;
}
vector<vector<int>> used;
vector<string> p;
vector<vector<int>> ans;
pair<int, int> L;
int n, m;
vector<pair<int, int>> go = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
bool ok(pair<int, int> x) {
  return (0 <= x.first && 0 <= x.second && x.first < n && x.second < m);
};
void dfs(int x, int y, int kek = 1) {
  used[x][y] = 1;
  int cnt = 0;
  for (auto i : go) {
    int nx = x + i.first;
    int ny = y + i.second;
    if (ok({nx, ny}) && p[nx][ny] != '#') cnt++;
  }
  if (cnt > 2 && make_pair(x, y) != L) kek = 0;
  if (kek) ans[x][y] = 1;
  for (auto i : go) {
    int nx = x + i.first;
    int ny = y + i.second;
    if (ok({nx, ny})) {
      if (!used[nx][ny] && p[x][y] != '#') {
        dfs(nx, ny, kek);
      } else if (kek && used[nx][ny] && p[x][y] != '#' && !ans[nx][ny]) {
        dfs(nx, ny, kek);
      }
    }
  }
};
signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  cout.setf(ios::fixed);
  cout.precision(10);
  int ___;
  cin >> ___;
  while (___--) {
    cin >> n >> m;
    p = {};
    p.resize(n);
    cin >> p;
    used = {};
    used.resize(n, vector<int>(m));
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < m; ++j) {
        if (p[i][j] == 'L') {
          L = {i, j};
          break;
        }
      }
    }
    ans = {};
    ans.resize(n, vector<int>(m));
    dfs(L.first, L.second);
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < m; ++j) {
        if (p[i][j] != '.')
          cout << p[i][j];
        else {
          if (ans[i][j])
            cout << '+';
          else
            cout << '.';
        }
      }
      cout << '\n';
    }
  }
}
