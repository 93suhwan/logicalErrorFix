#include <bits/stdc++.h>
using namespace std;
vector<long long> a;
string s;
long long n;
long long dp[100000];
long long memo[100000][200 + 1];
long long find(long long pos, long long val) {
  if (pos < 0) return 0;
  if (a[pos - 1] <= val) return dp[pos - 1];
  if (val <= 200 && memo[pos][val] != -1) return memo[pos][val];
  long long x = a[pos - 1] / val;
  if (a[pos - 1] % val) x++;
  long long nex = a[pos - 1] / x;
  long long cnt = x - 1;
  long long ans = (find(pos - 1, nex) + (cnt * (pos)) % 998244353) % 998244353;
  if (val <= 200) memo[pos][val] = ans;
  return ans;
}
long long solve() {
  a.clear();
  s.clear();
  long long i = 0, j = 0, k = 0, x = 0, y = 0, z = 0;
  cin >> n;
  a.resize(n);
  for (i = 0; i < n; i++) cin >> a[i];
  for (i = 0; i < n; i++) {
    dp[i] = 0;
    for (j = 0; j <= 200; j++) memo[i][j] = -1;
  }
  long long ans = 0;
  for (i = 1; i < n; i++) {
    dp[i] = find(i, a[i]);
    ans = (ans + dp[i]) % 998244353;
  }
  cout << ans << "\n";
  return 0;
}
int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  long long testcases = 1;
  cin >> testcases;
  while (testcases--) {
    solve();
  }
  return 0;
}
