#include <bits/stdc++.h>
using namespace std;
inline void debugMode() {}
long long dp[2][100001];
const long long mod = 998244353;
inline long long ceil(long long a, long long x) {
  return a / x + ((a % x) != 0);
}
void solvecases(int cse) {
  int n;
  cin >> n;
  vector<int> d(n);
  for (auto& e : d) cin >> e;
  int cur = 1;
  vector<vector<int>> indx(2);
  long long ans = 0;
  for (int i = n - 1; i >= 0; --i) {
    int lindx = -1;
    int prev = cur ^ 1;
    for (auto e : indx[prev]) {
      int curindx = d[i] / ceil(d[i], e);
      dp[cur][curindx] += dp[prev][e];
      if (curindx != lindx) {
        indx[cur].push_back(curindx);
        lindx = curindx;
      }
      ans += (i + 1) * dp[prev][e] * (ceil(d[i], e) - 1) % mod;
    }
    ans %= mod;
    for (auto e : indx[prev]) dp[prev][e] = 0;
    if (!dp[cur][d[i]]) {
      indx[cur].push_back(d[i]);
    }
    ++dp[cur][d[i]];
    indx[prev].clear();
    cur ^= 1;
  }
  for (auto e : indx[cur ^ 1]) dp[cur ^ 1][e] = 0;
  cout << ans << '\n';
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  ;
  int t = 1;
  cin >> t;
  for (int i = 1; i <= t; i++) {
    solvecases(i);
  }
}
