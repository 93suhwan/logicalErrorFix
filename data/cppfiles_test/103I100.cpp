#include <bits/stdc++.h>
#pragma GCC optimization("O3")
#pragma GCC optimization("unroll-loops")
#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
using namespace std;
mt19937 rnd(42);
template <typename T>
istream& operator>>(istream& in, vector<T>& vec) {
  for (int i = 0; i < vec.size(); i++) {
    in >> vec[i];
  }
  return in;
}
template <typename T>
ostream& operator<<(ostream& out, const vector<T>& vec) {
  for (const auto& x : vec) {
    out << x << " ";
  }
  return out;
}
template <class P, class D>
ostream& operator<<(ostream& os, pair<P, D> p) {
  os << "{" << p.first << ", " << p.second << "}";
  return os;
}
const long long inf = numeric_limits<long long>::max();
const long double infLd = numeric_limits<long double>::max();
const long long MOD = 1000000007;
const long long gayMOD = 998244353;
const long double PI = 3.14159265358979323846;
vector<long long> xs{0, 1, 0, -1};
vector<long long> ys{-1, 0, 1, 0};
map<char, long long> where;
bool ok(long long y, long long x, vector<string>& field) {
  if (y < 0 or x < 0 or y >= field.size() or x >= field[0].size()) {
    return false;
  }
  return true;
}
long long timer = 0;
pair<pair<long long, long long>, long long> dfs(
    long long y, long long x, vector<string>& field,
    vector<vector<long long> >& used, vector<vector<long long> >& dp,
    vector<vector<long long> >& tin) {
  timer++;
  tin[y][x] = timer;
  used[y][x] = 1;
  long long dir = where[field[y][x]];
  long long ny = y + ys[dir];
  long long nx = x + xs[dir];
  if (ok(ny, nx, field)) {
    if (used[ny][nx] == 2) {
      dp[y][x] = dp[ny][nx] + 1;
      return {{-1, -1}, dp[y][x] + 1};
    } else if (used[ny][nx] == 1) {
      dp[y][x] = timer - tin[ny][nx] + 1;
      return {{ny, nx}, dp[y][x] + 1};
    } else if (used[ny][nx] == 0) {
      auto res = dfs(ny, nx, field, used, dp, tin);
      dp[y][x] = res.second;
      if (res.first.first == y and res.first.second) {
        return {{-1, -1}, dp[y][x] - 1};
      } else {
        return {{res.first.first, res.first.second}, dp[y][x]};
      }
    }
  } else {
    dp[y][x] = 1;
    return {{-1, -1}, 2};
  }
  used[y][x] = 2;
}
void solve() {
  long long n, m;
  cin >> n >> m;
  vector<string> field(n);
  cin >> field;
  vector<vector<long long> > used(n, vector<long long>(m, 0));
  vector<vector<long long> > dp(n, vector<long long>(m, 0));
  vector<vector<long long> > tin(n, vector<long long>(m, 0));
  timer = 0;
  for (long long i = 0; i < n; i++) {
    for (long long g = 0; g < m; g++) {
      if (!used[i][g]) {
        dfs(i, g, field, used, dp, tin);
      }
    }
  }
  long long maxAns = 0;
  long long ansY = 0;
  long long ansX = 0;
  for (long long i = 0; i < n; i++) {
    for (long long g = 0; g < m; g++) {
      if (dp[i][g] > maxAns) {
        maxAns = dp[i][g];
        ansY = i;
        ansX = g;
      }
    }
  }
  cout << ansY + 1 << " " << ansX + 1 << " " << maxAns << "\n";
}
signed main() {
  where['U'] = 0;
  where['R'] = 1;
  where['D'] = 2;
  where['L'] = 3;
  cin.tie(NULL);
  ios_base::sync_with_stdio(false);
  long long tt;
  tt = 1;
  cin >> tt;
  while (tt--) {
    solve();
  }
}
