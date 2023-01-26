#include <bits/stdc++.h>
using namespace std;
long long dirs8[] = {0, -1, -1, 0, 1, -1, 1, 1, 0};
long long dirs4[] = {0, 1, 0, -1, 0};
long long dirs2[] = {0, 1, 0};
long long fact(long long n) {
  long long ans = 1;
  while (n) ans *= n--;
  return ans;
}
bool isPrime(long long &n) {
  for (long long i = 2; i * i <= n; ++i)
    if (n % i == 0) return 0;
  return 1;
}
vector<pair<long long, long long>> getPrimeFactors(long long n) {
  vector<pair<long long, long long>> facts;
  for (long long i = 2; i * i <= n; ++i) {
    if (n % i == 0) {
      long long cnt = 0;
      while (n % i == 0) {
        ++cnt;
        n /= i;
      }
      facts.push_back({i, cnt});
    }
  }
  if (n > 1) facts.push_back({n, 1});
  return facts;
}
const long long N = 200005;
long long dp[N][32];
void solve() {
  long long low, high;
  cin >> low >> high;
  low--;
  long long res = INT_MAX;
  for (long long i = 0; i < 32; i++) {
    res = min(res, high - low - dp[high][i] + dp[low][i]);
  }
  cout << res << '\n';
}
int32_t main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  memset(dp[0], 0, sizeof dp[0]);
  for (long long i = 1; i <= N; i++) {
    for (long long c = 0; c < 32; c++) {
      dp[i][c] = dp[i - 1][c];
    }
    bitset<19> b(i);
    for (long long j = 0; j < 32; j++) {
      if (b[j] == true) {
        dp[i][j]++;
      }
    }
  }
  long long t;
  cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}
