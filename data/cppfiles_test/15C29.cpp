#include <bits/stdc++.h>
const int INF = 2147483647;
const int INF2 = 0x3f3f3f3f;
const long long INF64 = (long long)1e18;
const double INFD = 1e30;
const double EPS = 1e-9;
const double PI = std::acos(-1);
const int MOD = 1e9 + 7;
template <typename T>
inline T read() {
  T X = 0, w = 0;
  char ch = 0;
  while (!isdigit(ch)) {
    w |= ch == '-';
    ch = getchar();
  }
  while (isdigit(ch)) X = (X << 3) + (X << 1) + (ch ^ 48), ch = getchar();
  return w ? -X : X;
}
const int MAXN = 105;
const int MAXV = (1 << 17) + 5;
int dr[4] = {0, 1, 0, -1};
int dc[4] = {-1, 0, 1, 0};
int dr2[8] = {1, 1, 1, -1, -1, -1, 0, 0};
int dc2[8] = {1, 0, -1, 1, 0, -1, 1, -1};
int CASE = 1;
int A[MAXN];
int fact[MAXN];
std::vector<int> G[MAXN];
int dep[MAXN];
int cnt[MAXN][MAXN];
int dp[MAXN][MAXN];
int fastExp(int x, int p, int mod) {
  int ans = 1;
  while (p) {
    if (p & 1) ans = (long long)ans * x % mod;
    x = (long long)x * x % mod;
    p >>= 1;
  }
  return ans;
}
int getInv(int x, int mod) { return fastExp(x, MOD - 2, MOD); }
int choose(int n, int k) {
  if (k > n || n < 0 || k < 0) return 0;
  return fact[n] * getInv(fact[k] * fact[n - k] % MOD, MOD) % MOD;
}
void dfs(int x, int p) {
  for (auto v : G[x]) {
    if (v == p) continue;
    dep[v] = dep[x] + 1;
    dfs(v, x);
  }
}
void dfscnt(int x, int p, int pp) {
  cnt[pp][dep[x]]++;
  for (auto v : G[x]) {
    if (v == p) continue;
    dfscnt(v, x, pp);
  }
}
void solve() {
  int n, k;
  scanf("%d%d", &n, &k);
  for (int i = 1; i <= n; i++) G[i].clear();
  for (int i = 1; i <= n - 1; i++) {
    int u, v;
    scanf("%d%d", &u, &v);
    G[u].push_back(v);
    G[v].push_back(u);
  }
  if (k == 2) {
    printf("%d\n", ((long long)n * (n - 1) / 2) % MOD);
    return;
  }
  int ans = 0;
  for (int i = 1; i <= n; i++) {
    dep[i] = 0;
    dfs(i, i);
    int sz = G[i].size();
    if (sz < k) continue;
    for (int a = 0; a <= n; a++) {
      for (int b = 0; b <= n; b++) {
        cnt[a][b] = 0;
      }
    }
    for (int j = 0; j < sz; j++) {
      auto v = G[i][j];
      dfscnt(v, i, v);
    }
    for (int s = 1; s <= n; s++) {
      dp[0][0] = 1;
      for (int j = 1; j <= sz; j++) {
        auto v = G[i][j - 1];
        for (int l = 0; l <= k; l++) {
          dp[j][l] = dp[j - 1][l];
          if (l > 0) {
            dp[j][l] = dp[j][l] + (long long)cnt[v][s] * dp[j - 1][l - 1] % MOD;
            dp[j][l] %= MOD;
          }
        }
      }
      ans += dp[sz][k];
      ans %= MOD;
    }
  }
  printf("%d\n", ans);
}
int main() {
  fact[0] = 1;
  for (int i = 1; i <= 100; i++) {
    fact[i] = (long long)fact[i - 1] * i % MOD;
  }
  int T = read<int>();
  while (T--) {
    solve();
  }
  return 0;
}
