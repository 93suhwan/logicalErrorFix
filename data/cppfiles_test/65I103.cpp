#include <bits/stdc++.h>
using namespace std;
using lli = long long int;
using ulli = unsigned long long int;
using Ld = long double;
using pii = pair<int, int>;
using pll = pair<lli, lli>;
using pld = pair<Ld, Ld>;
int pi[2001];
const lli MOD = 998244353;
pii p[51];
lli dp[51][100001];
lli GetRes(int n, int m, int g) {
  for (int i = (0); i <= (m); i++) dp[0][i] = 1;
  for (int k = (0); k < (n); k++) {
    lli l = (p[k].first + g - 1) / g, r = p[k].second / g;
    if (l > r) return 0;
    for (int i = (1); i <= (m); i++) {
      lli s = 0;
      if (i - l >= 0) s = dp[k][i - l];
      lli mi = 0;
      if (i - r - 1 >= 0) mi = dp[k][i - r - 1];
      dp[k + 1][i] = s - mi;
    }
    dp[k + 1][0] = 0;
    for (int i = (1); i <= (m); i++) {
      dp[k + 1][i] += dp[k + 1][i - 1];
      dp[k + 1][i] %= MOD;
    }
  }
  return dp[n][m];
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int n, m;
  cin >> n >> m;
  for (int i = (0); i < (n); i++) cin >> p[i].first >> p[i].second;
  pi[1] = 1;
  lli res = 0;
  for (int i = (1); i <= (m / n + 1); i++) {
    if (pi[i] == 0) continue;
    res += pi[i] * GetRes(n, m / i, i);
    for (int j = i + i; j <= m / n; j += i) pi[j] -= pi[i];
  }
  cout << (res + MOD) % MOD;
  return 0;
}
