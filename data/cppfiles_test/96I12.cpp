#include <bits/stdc++.h>
using namespace std;
long long MOD = 998244353;
int x = 0;
long long memo(int amt, int damage, vector<vector<long long>>& dp,
               vector<vector<long long>>& choose);
void solve(int t) {
  int n;
  cin >> n >> x;
  vector<vector<long long>> dp(n + 1, vector<long long>(x + 1, -1));
  vector<vector<long long>> choose(n + 1, vector<long long>(n + 1, -1));
  for (int i = 0; i <= n; i++) {
    for (int j = 0; j <= i; j++) {
      if (j == 0 || j == i)
        choose[i][j] = 1;
      else
        choose[i][j] = choose[i - 1][j] + choose[i - 1][j - 1];
      choose[i][j] %= MOD;
    }
  }
  cout << memo(n, 0, dp, choose) << endl;
}
long long expo(int a, int b) {
  if (b == 0) return 1;
  long long half = expo(a, b / 2);
  if (b % 2 == 1) return half * half * a % MOD;
  return half * half % MOD;
}
long long memo(int amt, int damage, vector<vector<long long>>& dp,
               vector<vector<long long>>& choose) {
  if (amt == 1) return 0;
  if (amt == 0) return 1;
  if (damage == x) return 0;
  if (dp[amt][damage] != -1) return dp[amt][damage];
  long long ans = 0;
  for (int alive = 0; alive <= amt; alive++) {
    int nextDamage = min(x, damage + amt - 1);
    long long totalWays = choose[amt][amt - alive];
    long long assignHealth = expo(nextDamage - damage, amt - alive);
    ans = ans +
          totalWays * assignHealth * memo(alive, nextDamage, dp, choose) % MOD;
    ans = ans % MOD;
  }
  return dp[amt][damage] = ans;
}
int main(void) {
  for (int i = 1; i <= 1; i++) {
    solve(i);
  }
}
