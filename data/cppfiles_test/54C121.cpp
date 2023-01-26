#include <bits/stdc++.h>
using namespace std;
const int INF = 0x3f3f3f3f;
const long long LINF = 0x3f3f3f3f3f3f3f3fLL;
const long long MOD = 1e9 + 7;
const int MAX = 2e5 + 10;
long long aux[MAX][2];
long long dp[MAX][2];
int N, K;
long long fexp(long long a, long long e) {
  long long ans = 1;
  while (e) {
    if (e & 1) ans = ans * a % MOD;
    a = a * a % MOD;
    e >>= 1;
  }
  return ans;
}
long long solve(int pos, bool won) {
  if (pos == K) return 1;
  long long &ans = dp[pos][won];
  if (ans != -1) return ans;
  ans = 0;
  if (won) {
    ans = (ans + fexp(2, N) * solve(pos + 1, 1) % MOD) % MOD;
  } else {
    ans = (ans + solve(pos + 1, !(N & 1))) % MOD;
    ans = (ans + (aux[N][0] + MOD - !(N & 1)) * solve(pos + 1, 0) % MOD) % MOD;
  }
  return ans;
}
inline void test_case() {
  cin >> N >> K;
  memset(dp, -1, sizeof dp);
  cout << solve(0, 0) << '\n';
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  aux[0][0] = 1;
  for (int i = 1; i < MAX; i++) {
    for (int k : {0, 1}) {
      aux[i][k] = (aux[i - 1][k] + aux[i - 1][not k]) % MOD;
    }
  }
  int number_of_tests;
  cin >> number_of_tests;
  while (number_of_tests--) {
    test_case();
  }
  return 0;
}
