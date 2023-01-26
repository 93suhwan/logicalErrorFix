#include <bits/stdc++.h>
const long long mod = 998244353;
using namespace std;
bool isprime(long long k) {
  for (long long i = 2; i <= sqrt(k); i++)
    if (k % i == 0) return false;
  return true;
}
long long bm(long long a, long long b, long long mod) {
  if (b == 0) return 1;
  long long t = bm(a, b / 2, mod);
  t = t * t % mod;
  return (b % 2 == 1 ? t * a % mod : t);
}
long long inv(long long a, long long mod) { return bm(a, mod - 2, mod); }
void gay(long long TC) { cout << "Case #" << TC << ": "; }
long long ncr_pre[5005][5005];
long long ncr(long long n, long long r) {
  if (n < r) return 0;
  return ncr_pre[n][r];
}
void solve(long long TC) {
  long long n, k;
  cin >> n >> k;
  string s;
  cin >> s;
  long long ans = 1;
  long long tc = 0;
  for (auto x : s) tc += x - '0';
  if (tc < k || k == 0) {
    cout << "1\n";
    return;
  }
  for (long long i = 0; i < n; i++) {
    if (i != 0 && s[i - 1] != '1') continue;
    long long j = i - 1, id = -1, cnt = 0;
    while (cnt <= k && !(j == n - 1 || (cnt == k && s[j + 1] == '1'))) {
      j++;
      cnt += s[j] - '0';
      if (s[j] == '1' && id == -1) id = j;
    }
    if (cnt == 0) continue;
    long long len = j - i + 1;
    long long len2 = j - id;
    ans += ncr(len, cnt) - ncr(len2, cnt - 1);
    ans %= mod;
  }
  ans = ans + mod;
  ans %= mod;
  cout << ans << '\n';
}
signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  long long t = 1;
  for (long long i = 0; i <= 5000; i++) {
    for (long long j = 0; j <= i; j++) {
      if (j == 0 || j == i)
        ncr_pre[i][j] = 1;
      else
        ncr_pre[i][j] = ncr_pre[i - 1][j] + ncr_pre[i - 1][j - 1];
      ncr_pre[i][j] %= mod;
    }
  }
  for (long long i = 1; i <= t; i++) solve(i);
  return 0;
}
