#include <bits/stdc++.h>
using namespace std;
const int maxn = 4 * 1e5 + 10, mod = 1e9 + 7;
const int maxn_mp = 1005;
const int small_inf = 0x3f3f3f3f;
const double EPS = 1e-3;
long long n, m, k, z, h, cnt, flag;
long long ha1 = 227, ha2 = 197;
char c[1005][1005];
const int dx[4] = {0, 1, 0, -1};
const int dy[4] = {-1, 0, 1, 0};
bool cmp(pair<long long, long long> a, pair<long long, long long> b) {
  return a.first < b.first;
}
long long f[505][505];
int vis[maxn];
vector<int> G[maxn];
map<string, int> mp;
string s;
long long ans = 0x7fffffff;
bool check() {
  if (1)
    return 1;
  else
    return 0;
}
pair<long long, long long> a[maxn], b[maxn];
void dfs(int i) {
  vis[i] = 1;
  for (int j = 0; j < (int)G[i].size(); j++)
    if (!vis[G[i][j]]) dfs(G[i][j]);
  return;
}
int dp[maxn];
void solve() {
  memset(dp, 0, sizeof(dp));
  int x = 0;
  cin >> n >> k >> x;
  cin >> s;
  int pos = -1;
  dp[n] = 1;
  for (int i = n - 1; i >= 0; i--) {
    if (s[i] == '*' && s[i + 1] == 'a')
      dp[i] = dp[i + 1] * k + dp[i + 1];
    else if (s[i] == '*')
      dp[i] = dp[i + 1] + k;
    else
      dp[i] = dp[i + 1];
  }
  for (int i = 0; i < n; i++) {
    cout << dp[i] << ' ';
    if (dp[i] >= x) pos = i;
  }
  cout << pos;
  cout << endl;
  for (int i = 0; i < pos; i++)
    if (s[i] == 'a') cout << 'a';
  for (int i = pos; i < n; i++) {
    if (s[i] == 'a') continue;
    while (x > dp[i + 1]) {
      cout << 'b';
      x -= dp[i + 1];
    }
  }
  cout << endl;
}
signed main() {
  int ttt = 0;
  int tt;
  cin >> tt;
  while (tt--) solve();
  ios::sync_with_stdio(false);
  cin.tie(0);
  return 0;
}
