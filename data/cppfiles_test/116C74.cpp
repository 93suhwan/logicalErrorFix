#include <bits/stdc++.h>
using namespace std;
namespace IO {
char in[1 << 26];
char const *o;
void init_in() {
  o = in;
  in[fread(in, 1, sizeof(in) - 4, stdin)] = 0;
}
int rd() {
  unsigned u = 0, s = 0;
  while (*o && *o <= 32) ++o;
  if (*o == '-')
    s = ~s, ++o;
  else if (*o == '+')
    ++o;
  while (*o >= '0' && *o <= '9') u = (u << 3) + (u << 1) + (*o++ - '0');
  return static_cast<int>((u ^ s) + !!s);
}
char *rdstr(char *s) {
  while (*o && *o <= 32) ++o;
  while (*o > 32) *s++ = *o++;
  *s = '\0';
  return s;
}
}  // namespace IO
template <typename T>
void chkmax(T &a, const T &b) {
  a = max(a, b);
}
template <typename T>
void chkmin(T &a, const T &b) {
  a = min(a, b);
}
pair<int, int> operator+(const pair<int, int> &a, const pair<int, int> &b) {
  return make_pair(a.first + b.first, a.second + b.second);
}
using IO::rd;
const int N = 300005;
int vis[N], vvis[N], dfn[N], t[N], in[N], cnt[N], low, tot;
vector<int> G[N];
int n, m, k;
bool dfs(int u) {
  dfn[u] = ++tot;
  if (G[u].empty() && in[u] < 2) return true;
  int v = G[u][0];
  if (dfn[v]) return false;
  return dfs(v);
}
void solve() {
  n = rd(), m = rd(), k = rd();
  int sp = k;
  for (int i = 0; i < n; ++i) {
    int c = rd();
    bool valid = 1;
    for (int j = 0; j < c; ++j) {
      t[j] = rd();
      if (vis[t[j]] == i + 1) {
        valid = 0;
      }
      vis[t[j]] = i + 1;
    }
    if (valid) {
      for (int j = 0; j < c; ++j) {
        if (!vvis[t[j]]) --sp;
        vvis[t[j]] = 1;
        if (j) {
          G[t[j - 1]].push_back(t[j]);
        }
      }
    } else {
      for (int j = 0; j < c; ++j) dfn[t[j]] = 1;
    }
  }
  for (int i = 1; i < k + 1; ++i) {
    sort(begin(G[i]), end(G[i]));
    G[i].erase(unique(G[i].begin(), G[i].end()), G[i].end());
    for (auto v : G[i]) {
      ++in[v];
    }
  }
  for (int i = 1; i < k + 1; ++i)
    if (G[i].size() > 1 || in[i] > 1) dfn[i] = 1;
  tot = 1;
  vector<int> con;
  for (int i = 1; i < k + 1; ++i) {
    if (!dfn[i] && in[i] == 0) {
      low = tot;
      if (dfs(i)) {
        ++cnt[tot - low];
        con.push_back(tot - low);
      }
    }
  }
  sort(begin(con), end(con));
  con.erase(unique(con.begin(), con.end()), con.end());
  static int dp[N];
  const int mod = 998244353;
  dp[0] = 1;
  for (int i = 1; i < m + 1; ++i) {
    for (auto l : con) {
      if (l > i) break;
      dp[i] = (dp[i] + 1ll * dp[i - l] * cnt[l]) % mod;
    }
  }
  cout << dp[m] << '\n';
}
int main() {
  IO::init_in();
  solve();
  return 0;
}
