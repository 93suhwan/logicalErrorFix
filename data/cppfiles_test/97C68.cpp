#include <bits/stdc++.h>
#pragma GCC optimize("O3")
#pragma GCC target("sse4")
using namespace std;
using ll = long long;
using vi = vector<int>;
using pii = pair<int, int>;
using vpi = vector<pii>;
using pll = pair<ll, ll>;
using vl = vector<ll>;
using vpl = vector<pll>;
using ld = long double;
const int INF = 1e9;
const ll LINF = 1e18;
const int MOD = 1e9 + 7;
const ld PI = acos((ld)-1.0);
const int dx[4] = {1, 0, -1, 0}, dy[4] = {0, 1, 0, -1};
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
template <typename T>
using pqg = priority_queue<T, vector<T>, greater<T>>;
template <typename T>
bool ckmin(T &a, const T &b) {
  return b < a ? a = b, 1 : 0;
}
template <typename T>
bool ckmax(T &a, const T &b) {
  return b > a ? a = b, 1 : 0;
}
template <typename A, typename B>
ostream &operator<<(ostream &os, const pair<A, B> &p) {
  return os << '(' << p.first << ", " << p.second << ')';
}
template <typename T_container, typename T = typename enable_if<
                                    !is_same<T_container, string>::value,
                                    typename T_container::value_type>::type>
ostream &operator<<(ostream &os, const T_container &v) {
  os << '{';
  string sep;
  for (const T &x : v) os << sep << x, sep = ", ";
  return os << '}';
}
void dbg_out() { cerr << endl; }
template <typename Head, typename... Tail>
void dbg_out(Head H, Tail... T) {
  cerr << ' ' << H;
  dbg_out(T...);
}
struct chash {
  static uint64_t splitmix64(uint64_t x) {
    x += 0x9e3779b97f4a7c15;
    x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
    x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
    return x ^ (x >> 31);
  }
  size_t operator()(uint64_t x) const {
    static const uint64_t FIXED_RANDOM =
        chrono::steady_clock::now().time_since_epoch().count();
    return splitmix64(x + FIXED_RANDOM);
  }
  size_t operator()(pair<uint64_t, uint64_t> x) const {
    static const uint64_t FIXED_RANDOM =
        chrono::steady_clock::now().time_since_epoch().count();
    return splitmix64(x.first + FIXED_RANDOM) ^
           (splitmix64(x.second + FIXED_RANDOM) >> 1);
  }
};
void setIO(string s) {
  freopen((s + ".in").c_str(), "r", stdin);
  freopen((s + ".out").c_str(), "w", stdout);
}
int grid[501][501];
int ans[501][501];
bool vis[501][501];
int n, m;
vi g[250000];
void add(int x, int y) { g[x].push_back(y), g[y].push_back(x); }
int conv(pii z) {
  auto [x, y] = z;
  return x * m + y;
}
pii conv(int x) { return {x / m, x % m}; }
bool good(int x, int y) { return x >= 0 && x < n && y >= 0 && y < m; }
void solve() {
  cin >> n >> m;
  for (int i = (0); i < (n); ++i)
    for (int j = (0); j < (m); ++j) {
      char c;
      cin >> c;
      if (c == '.')
        grid[i][j] = 0;
      else
        grid[i][j] = 1;
    }
  for (int i = (0); i < (n); ++i)
    for (int j = (0); j < (m); ++j) {
      if (!grid[i][j]) continue;
      int cnt = 0;
      vpi adj;
      for (int k = (0); k < (4); ++k) {
        int ni = i + dx[k], nj = j + dy[k];
        if (good(ni, nj) && !grid[ni][nj]) adj.emplace_back(ni, nj), cnt++;
      }
      if (cnt & 1) {
        cout << "NO\n";
        return;
      } else
        ans[i][j] = cnt * 5 / 2;
      42;
      for (int k = (0); k < ((int)(adj).size()); ++k) {
        add(conv(adj[k]), conv(adj[(k + 1) % (int)(adj).size()]));
      }
    }
  function<void(int, int, int)> dfs = [&](int x, int y, int z) {
    vis[x][y] = 1;
    ans[x][y] = (z ? 1 : 4);
    42;
    for (auto e : g[conv(make_pair(x, y))]) {
      42;
      auto [x1, y1] = conv(e);
      if (!vis[x1][y1]) dfs(x1, y1, z ^ 1);
    }
  };
  for (int i = (0); i < (n); ++i)
    for (int j = (0); j < (m); ++j) {
      if (!grid[i][j] && !vis[i][j]) {
        dfs(i, j, 0);
      }
    }
  cout << "YES"
       << "\n";
  for (int i = (0); i < (n); ++i) {
    for (int j = (0); j < (m); ++j) {
      cout << ans[i][j] << " ";
    }
    cout << "\n";
  }
}
int main() {
  cin.tie(0)->sync_with_stdio(0);
  cin.exceptions(cin.failbit);
  int testcase = 1;
  while (testcase--) {
    solve();
  }
}
