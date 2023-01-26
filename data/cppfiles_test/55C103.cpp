#include <bits/stdc++.h>
using namespace std;
const long long mod = 1000000007LL;
long long dp[64];
long long solve(long long k) {
  if (dp[k] != -1) return dp[k];
  if (k == 0) return 1LL;
  return ((16LL * solve(k - 1) % mod) * (solve(k - 1) % mod) % mod + mod) % mod;
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  long long k;
  cin >> k;
  for (int i = (0); i < (64); i++) dp[i] = -1;
  cout << ((6LL * solve(k - 1)) % mod + mod) % mod << endl;
  return 0;
}
