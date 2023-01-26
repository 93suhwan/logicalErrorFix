#include <bits/stdc++.h>
using namespace std;
using vi = vector<int>;
using vvi = vector<vi>;
using vvvi = vector<vvi>;
using ll = long long;
using vll = vector<ll>;
using vvll = vector<vll>;
using vvvll = vector<vvll>;
using ull = unsigned long long;
using vb = vector<bool>;
using vvb = vector<vb>;
using vd = vector<double>;
using vvd = vector<vd>;
using vvvd = vector<vvd>;
using vs = vector<string>;
using vvs = vector<vs>;
using vc = vector<char>;
using vvc = vector<vc>;
using ii = pair<int, int>;
using vii = vector<ii>;
using vvii = vector<vii>;
using dd = pair<double, double>;
using vdd = vector<dd>;
using vvdd = vector<vdd>;
using Mii = map<int, int>;
using vMii = vector<Mii>;
using Si = set<int>;
using vSi = vector<Si>;
using vvSi = vector<vSi>;
int n, m;
vvi mat;
vvb vis;
int dfs(int r, int c) {
  if (r < 0 or c < 0 or r >= n or c >= m or vis[r][c]) return 0;
  int ans = 1;
  vis[r][c] = true;
  int x = mat[r][c];
  vi dh = {-1, 0, 1, 0};
  vi dv = {0, 1, 0, -1};
  for (int i = 0; i < 4; ++i) {
    if (not(x & (1 << i))) {
      ans += dfs(r + dv[i], c + dh[i]);
    }
  }
  return ans;
}
int main() {
  cin.tie(NULL);
  ios_base::sync_with_stdio(false);
  while (cin >> n >> m) {
    mat = vvi(n, vi(m));
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < m; ++j) {
        cin >> mat[i][j];
      }
    }
    vi ans;
    vis = vvb(n, vb(m, false));
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < m; ++j) {
        if (not vis[i][j]) {
          ans.push_back(dfs(i, j));
        }
      }
    }
    sort(ans.rbegin(), ans.rend());
    for (int i = 0; i < int(ans.size()); ++i) {
      cout << ans[i] << ' ';
    }
    cout << '\n';
  }
}
