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
struct aho {
  struct tk {
    long long link;
    char a;
    long long par;
    long long val;
    long long leaf;
    long long go[3];
    long long nxt[3];
    tk(long long par, char a) : par(par), a(a) {
      link = -1;
      val = -1;
      memset(go, -1, sizeof(go));
      memset(nxt, -1, sizeof(nxt));
      leaf = 0;
    }
  };
  vector<tk> vt;
  void init() { vt.push_back({-1, '0'}); }
  void add(string s, long long val) {
    long long nw = 0;
    for (auto to : s) {
      long long ch = to - '0' + 1;
      if (vt[nw].nxt[ch] == -1) {
        vt[nw].nxt[ch] = vt.size();
        vt.push_back({nw, to});
      }
      nw = vt[nw].nxt[ch];
    }
    vt[nw].leaf += val;
  }
  long long get_val(long long u) {
    if (vt[u].val != -1) return vt[u].val;
    if (u == 0) return vt[u].val = vt[u].leaf;
    return vt[u].val = vt[u].leaf + get_val(get_link(u));
  }
  long long get_link(long long u) {
    if (vt[u].link != -1) return vt[u].link;
    if (u == 0 || vt[u].par == 0) return vt[u].link = 0;
    return vt[u].link = go(get_link(vt[u].par), vt[u].a - '0' + 1);
  }
  long long go(long long u, long long ch) {
    if (vt[u].go[ch] != -1) return vt[u].go[ch];
    if (vt[u].nxt[ch] != -1) return vt[u].go[ch] = vt[u].nxt[ch];
    if (u == 0)
      return vt[u].go[ch] = 0;
    else
      return vt[u].go[ch] = go(get_link(u), ch);
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
