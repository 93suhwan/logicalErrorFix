#include <bits/stdc++.h>
using namespace std;
long long solve();
vector<long long> a;
string s;
long long n;
int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  long long t = 1;
  while (t--) {
    solve();
  }
  return 0;
}
long long in(vector<long long> &a, long long n) {
  long long i = 0, x, sum = 0;
  for (i = 0; i < n; i++) {
    cin >> x;
    a.push_back({x});
  }
  return sum;
}
vector<long long> seive[200001];
void init() {
  long long i, j;
  for (i = 2; i < 100001; i++) {
    for (j = 2 * i; j <= 200000; j += i) {
      seive[j].push_back(i);
    }
  }
}
long long solve() {
  a.clear();
  s.clear();
  long long i = 0, j = 0, k = 0;
  long long flag = 0;
  long long x = 0, y = 0, z = 0;
  init();
  cin >> n;
  long long m;
  cin >> m;
  long long prefixsum = 8;
  if (n == 2) {
    cout << 2 << "\n";
    return 0;
  }
  long long dp[n + 1];
  dp[1] = 1;
  dp[2] = 2;
  dp[3] = 5;
  long long divisorsum = 2;
  for (i = 4; i <= n; i++) {
    for (auto u : seive[i]) {
      x = i / u;
      divisorsum -= dp[x - 1];
      if (divisorsum < 0) divisorsum += m;
      divisorsum += dp[x];
      divisorsum %= m;
    }
    divisorsum += 1;
    dp[i] = prefixsum + divisorsum;
    dp[i] %= m;
    prefixsum += dp[i];
    prefixsum %= m;
  }
  cout << dp[n] << "\n";
  return 0;
}
