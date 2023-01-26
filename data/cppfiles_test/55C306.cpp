#include <bits/stdc++.h>
const long long MOD = 1000000007;
int solve(int n, int k);
using namespace std;
int main() {
  int n;
  cin >> n;
  long long ans = 0;
  long long dp = 1;
  for (int i = 1; i < n; i++) {
    dp = (16 * dp % MOD) * dp;
    dp %= MOD;
  }
  cout << (dp * 6) % MOD << endl;
  return 0;
}
