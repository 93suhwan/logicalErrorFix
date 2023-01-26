#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
#pragma GCC optimization("unroll-loops, no-stack-protector")
#pragma GCC target("avx,avx2,fma")
using namespace std;
mt19937_64 rnd;
const long long maxn = 5e2 + 50;
const long long mod = 1e9 + 7;
const long long base = 1e13;
const long long magic = 2000;
struct aho_corasick {
  struct tk {
    long long link;
    long long nxt[27];
    long long par;
    char ch;
    long long go[27];
    long long val;
    long long leaf;
    tk(long long par = -1, char ch = '0') : par(par), ch(ch) {
      memset(nxt, -1, sizeof(nxt));
      memset(go, -1, sizeof(go));
      val = -1;
      link = -1;
      leaf = 0;
    }
  };
  vector<tk> vt;
  void init() {
    vt.clear();
    vt.push_back({-1, '0'});
  }
  long long add(string s, long long val) {
    long long nw = 0;
    for (auto to : s) {
      if (vt[nw].nxt[to - '0' + 1] == -1) {
        vt[nw].nxt[to - '0' + 1] = vt.size();
        vt.push_back({nw, to});
      }
      nw = vt[nw].nxt[to - '0' + 1];
    }
    vt[nw].leaf = val;
    return nw;
  }
  long long get_val(long long u) {
    if (u == 0) return 0;
    if (vt[u].val == -1) {
      vt[u].val = vt[u].leaf + get_val(get_link(u));
    }
    return vt[u].val;
  }
  long long go(long long v, long long t) {
    if (vt[v].go[t] == -1) {
      if (vt[v].nxt[t] != -1) {
        vt[v].go[t] = vt[v].nxt[t];
      } else {
        if (v == 0)
          vt[v].go[t] = 0;
        else
          vt[v].go[t] = go(get_link(v), t);
      }
    }
    return vt[v].go[t];
  }
  long long get_link(long long v) {
    if (vt[v].link == -1) {
      if (vt[v].par == 0 || v == 0)
        vt[v].link = 0;
      else
        vt[v].link = go(get_link(vt[v].par), vt[v].ch - '0' + 1);
    }
    return vt[v].link;
  }
  long long get(string s) {
    long long nw = 0;
    long long ans = 0;
    for (auto to : s) {
      nw = go(nw, to - 'a' + 1);
      ans += get_val(nw);
    }
    return ans;
  }
} man;
long long dp[2][maxn][maxn];
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  if (fopen("t.inp", "r")) {
    freopen("test.inp", "r", stdin);
    freopen("test.out", "w", stdout);
  }
  man.init();
  long long n, m;
  cin >> n >> m;
  string s;
  cin >> s;
  string s1;
  cin >> s1;
  man.add(s1, 0);
  long long k = n - m + 1;
  long long sl = man.vt.size() - 1;
  for (int i = 0; i <= 1; i++) {
    for (int j = 0; j <= sl; j++) {
      for (int h = 0; h <= k; h++) {
        dp[i][j][h] = base;
      }
    }
  }
  s = " " + s;
  dp[0][0][0] = 0;
  for (int i = 1; i <= n; i++) {
    long long nw = i % 2;
    long long pre = 1 - nw;
    for (int j = 0; j <= sl; j++) {
      for (int h = 0; h <= k; h++) {
        if (dp[pre][j][h] == base) continue;
        for (int t = 0; t <= 1; t++) {
          dp[nw][man.go(j, t + 1)][h + (man.go(j, t + 1) == sl)] =
              min(dp[nw][man.go(j, t + 1)][h + (man.go(j, t + 1) == sl)],
                  dp[pre][j][h] + ((s[i] - '0') != t));
        }
        dp[pre][j][h] = base;
      }
    }
  }
  for (int h = 0; h <= k; h++) {
    long long ans = base;
    for (int j = 0; j <= sl; j++) ans = min(ans, dp[n % 2][j][h]);
    if (ans == base) ans = -1;
    cout << ans << " ";
  }
}
