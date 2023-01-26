#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
using namespace std;
const int MOD = (int)1e9 + 7;
const int N = (int)2e5;
const long long INF = (long long)1e18;
int T;
int n;
int v[100005], w[100005];
int dp[100005], dp2[100005];
int f[100005];
vector<int> divs[100005];
int lgput(int n, long long p) {
  int ans = 1, first = n;
  while (p) {
    if (p & 1) ans = 1LL * ans * first % MOD;
    first = 1LL * first * first % MOD;
    p >>= 1;
  }
  return ans;
}
void precalc() {
  for (int i = 1; i <= 100000; i++) {
    for (int j = i; j <= 100000; j += i) divs[j].push_back(i);
  }
}
int solve(int v[], int n) {
  int ans = 0;
  vector<int> vals;
  for (int i = 1; i <= n; i++) {
    for (auto &d : divs[v[i]]) {
      if (!f[d]) vals.push_back(d);
      f[d]++;
    }
  }
  for (int i = (int)vals.size() - 1; i >= 0; i--) {
    int nr = vals[i];
    dp2[nr] = (dp2[nr] + 1LL * f[nr] * f[nr]) % MOD;
    ans = (ans + 1LL * nr * dp2[nr]) % MOD;
    for (auto &d : divs[nr]) {
      dp2[d] = (dp2[d] - dp2[nr] + MOD) % MOD;
    }
  }
  for (auto &d : vals) f[d] = dp2[d] = 0;
  return ans;
}
void solve() {
  cin >> n;
  for (int i = 1; i <= n; i++) cin >> v[i];
  int ans = 0;
  for (int d = n; d >= 1; d--) {
    int m = 0;
    for (int i = d; i <= n; i += d) {
      w[++m] = v[i];
    }
    dp[d] = solve(w, m);
    for (int i = 2 * d; i <= n; i += d) {
      dp[d] = (dp[d] - dp[i] + MOD) % MOD;
    }
    ans = (ans + 1LL * d * dp[d]) % MOD;
  }
  cout << ans << "\n";
}
int main() {
  ios_base ::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  T = 1;
  precalc();
  for (; T; T--) {
    solve();
  }
  return 0;
}
