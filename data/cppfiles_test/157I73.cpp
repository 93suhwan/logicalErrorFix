#include <bits/stdc++.h>
using namespace std;
const long long MAX = 2000000;
const long long MOD = 998244353;
const long long OO = 0x3f3f3f3f;
const double EPS = 1e-9;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
long long cnt;
long long dp[5005][5005];
long long seen[5005][5005];
long long C(long long n, long long k) {
  if (k > n) return 0;
  if (seen[n][k]) return dp[n][k];
  if (n == k or k == 0) return 1;
  long long r = (C(n - 1, k - 1) + C(n - 1, k)) % MOD;
  seen[n][k] = 1;
  return dp[n][k] = r;
}
void solve() {
  long long n, k;
  string s;
  cin >> n >> k >> s;
  vector<long long> ones;
  ones.push_back(0);
  for (long long i = 1; i <= n; ++i)
    if (s[i - 1] == '1') ones.push_back(i);
  ones.push_back(n + 1);
  if ((long long)ones.size() - 2 < k or k == 0) {
    cout << "1\n";
    return;
  }
  long long last_r = 0, ans = 0;
  for (long long i = 1; i + k < (long long)ones.size(); ++i) {
    long long l = ones[i - 1] + 1;
    long long r = ones[i + k] - 1;
    ans = (ans + C(r - l + 1, k)) % MOD;
    if (last_r >= l) ans = (ans - C(last_r - l + 1, k - 1) + MOD) % MOD;
    last_r = r;
  }
  cout << ans << '\n';
}
int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  ;
  long long t = 1;
  for (long long caso = 1; caso <= t; ++caso) {
    solve();
  }
  return 0;
}
