#include <bits/stdc++.h>
using namespace std;
#pragma GCC target("popcnt")
template <typename T, typename T2>
inline void nmax(T &a, T2 b) {
  a = max(a, (T)b);
}
template <typename T, typename T2>
inline void nmin(T &a, T2 b) {
  a = min(a, (T)b);
}
mt19937 rnd(time(NULL));
mt19937_64 rndll(time(NULL));
const int N = 2e5 + 10;
const int INF = 1e9 + 10;
const long long INFLL = 4e18 + 10;
const long long MOD = 1e9 + 7;
const long double EPS = 1e-6;
struct Mine {
  int x, y, t;
};
int n, k, mn;
bool used[N];
vector<int> kx, ky, mas;
map<int, vector<pair<int, int>>> X, Y;
vector<Mine> a;
int getx(int x, int y) {
  int l = 0, r = (int)X[x].size();
  while (r - l > 1) {
    int m = (l + r) >> 1;
    (X[x][m].first <= y ? l : r) = m;
  }
  return l;
}
int gety(int x, int y) {
  int l = 0, r = (int)Y[y].size();
  while (r - l > 1) {
    int m = (l + r) >> 1;
    (Y[y][m].first <= x ? l : r) = m;
  }
  return l;
}
void dfs(int i) {
  nmin(mn, a[i].t);
  used[i] = 1;
  int x = a[i].x, y = a[i].y;
  int ind = getx(x, y);
  if (ind && !used[X[x][ind - 1].second] && y - X[x][ind - 1].first <= k)
    dfs(X[x][ind - 1].second);
  if (ind + 1 < (int)X[x].size() && !used[X[x][ind + 1].second] &&
      X[x][ind + 1].first - y <= k)
    dfs(X[x][ind + 1].second);
  ind = gety(x, y);
  if (ind && !used[Y[y][ind - 1].second] && x - Y[y][ind - 1].first <= k)
    dfs(Y[y][ind - 1].second);
  if (ind + 1 < (int)Y[y].size() && !used[Y[y][ind + 1].second] &&
      Y[y][ind + 1].first - x <= k)
    dfs(Y[y][ind + 1].second);
}
void solve() {
  X.clear();
  Y.clear();
  kx.clear();
  ky.clear();
  mas.clear();
  for (int i = 0; i < n; ++i) used[i] = 0;
  cin >> n >> k;
  a.resize(n);
  int id = 0;
  for (auto &[x, y, t] : a) {
    cin >> x >> y >> t;
    X[x].emplace_back(y, id);
    Y[y].emplace_back(x, id);
    kx.emplace_back(x);
    ky.emplace_back(y);
    ++id;
  }
  for (int i : kx) sort((X[i]).begin(), (X[i]).end());
  for (int i : ky) sort((Y[i]).begin(), (Y[i]).end());
  for (int i = 0; i < n; ++i) {
    if (used[i]) continue;
    mn = INF;
    dfs(i);
    mas.emplace_back(mn);
  }
  sort((mas).rbegin(), (mas).rend());
  for (int i = 0; i < (int)mas.size(); ++i) {
    if (i + 1 == (int)mas.size() || mas[i + 1] <= i) {
      cout << i << '\n';
      return;
    }
  }
}
signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  ;
  int t = 1;
  cin >> t;
  while (t--) solve();
}
