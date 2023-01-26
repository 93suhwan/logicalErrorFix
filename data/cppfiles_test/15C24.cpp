#include <bits/stdc++.h>
using namespace std;
vector<string> vec_splitter(string s) {
  for (char& c : s) c = c == ',' ? ' ' : c;
  stringstream ss;
  ss << s;
  vector<string> res;
  for (string z; ss >> z; res.push_back(z))
    ;
  return res;
}
void debug_out(vector<string> args, int idx) { cerr << endl; }
template <typename Head, typename... Tail>
void debug_out(vector<string> args, int idx, Head H, Tail... T) {
  if (idx > 0) cerr << ", ";
  stringstream ss;
  ss << H;
  cerr << args[idx] << " = " << ss.str();
  debug_out(args, idx + 1, T...);
}
void localTest() {}
const long long MOD = 1e9 + 7, N = 105;
vector<long long> V[N];
long long dp[N][N], level[N];
void dfs(long long node, long long p, long long l) {
  level[l]++;
  for (auto child : V[node]) {
    if (child == p) {
      continue;
    }
    dfs(child, node, l + 1);
  }
  return;
}
void add(long long& x, long long y) {
  x += y;
  x %= MOD;
  return;
}
long long mul(long long x, long long y) {
  x %= MOD;
  y %= MOD;
  return (x * y) % MOD;
}
void solver() {
  int n, k;
  cin >> n >> k;
  for (int i = 1; i <= n; ++i) {
    V[i].clear();
  }
  for (int i = 1; i < n; ++i) {
    int x, y;
    cin >> x >> y;
    V[x].push_back(y);
    V[y].push_back(x);
  }
  if (k == 2) {
    cout << (n * (n - 1)) / 2 << "\n";
    return;
  }
  long long ans = 0;
  for (int root = 1; root <= n; ++root) {
    if ((int)V[root].size() < k) {
      continue;
    }
    memset(dp, 0, sizeof dp);
    for (int i = 1; i <= n; ++i) {
      dp[i][0] = 1;
    }
    for (auto u : V[root]) {
      memset(level, 0, sizeof level);
      dfs(u, root, 1);
      for (int i = 1; i <= n; ++i) {
        for (int j = k - 1; j >= 0; --j) {
          add(dp[i][j + 1], mul(dp[i][j], level[i]));
        }
      }
    }
    for (int i = 1; i <= n; ++i) {
      add(ans, dp[i][k]);
    }
  }
  cout << ans << "\n";
  return;
}
int main() {
  localTest();
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int t;
  cin >> t;
  while (t--) {
    solver();
  }
  return 0;
}
