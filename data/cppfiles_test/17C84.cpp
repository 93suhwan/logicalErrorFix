#include <bits/stdc++.h>
using namespace std;
long long power(long long x, long long y) {
  long long res = 1;
  x = x % 998244353;
  while (y > 0) {
    if (y & 1) res = (res * x) % 998244353;
    y = y >> 1;
    x = (x * x) % 998244353;
  }
  return res % 998244353;
}
long long inv(long long n) { return power(n, 998244353 - 2) % 998244353; }
long long isprime(long long n) {
  if (n < 2) return 0;
  long long i;
  for (i = 2; i * i <= n; i++)
    if (n % i == 0) return 0;
  return 1;
}
long long n, a[200005], b[200005], bit[200005];
long long cnt[200005], cnt2[200005];
void update(long long idx, long long val) {
  while (idx <= n) {
    bit[idx] += val;
    idx += idx & -idx;
  }
}
long long pref(long long idx) {
  long long ans = 0;
  while (idx > 0) {
    ans += bit[idx];
    idx -= idx & -idx;
  }
  return ans;
}
long long rsum(long long l, long long r) { return pref(r) - pref(l - 1); }
long long dp[200005];
void solve() {
  long long i;
  cin >> n;
  for (i = 1; i <= n; i++) {
    cin >> a[i];
    b[i] = a[i];
  }
  sort(b + 1, b + 1 + n);
  long long cur = 1;
  map<long long, long long> mp;
  for (i = 1; i <= n; i++) {
    if (mp[b[i]] == 0) {
      mp[b[i]] = cur++;
    }
  }
  for (i = 1; i <= n; i++) {
    a[i] = mp[a[i]];
    dp[i] = -1;
  }
  for (i = 1; i <= n + 2; i++) bit[i] = 0;
  for (i = 1; i <= n; i++) {
    long long l, r;
    l = a[i] + 1;
    r = n;
    cnt[i] = 0;
    if (l <= r) {
      cnt[i] = rsum(l, r);
    }
    update(a[i], 1);
  }
  for (i = 1; i <= n; i++) bit[i] = 0;
  for (i = 1; i <= n; i++) {
    long long l, r;
    l = 1;
    r = a[i] - 1;
    cnt2[i] = 0;
    if (l <= r) {
      cnt2[i] = rsum(l, r);
    }
    update(a[i], 1);
  }
  for (i = n; i >= 1; i--) dp[i] = min(cnt2[i], cnt[i]) + dp[i + 1];
  dp[1] = 0;
  for (i = 2; i <= n; i++) {
    dp[i] = dp[i - 1] + min(cnt2[i], cnt[i]);
  }
  cout << dp[n] << '\n';
}
int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  long long t = 1;
  long long tc = 0;
  cin >> t;
  while (t--) {
    tc++;
    solve();
  }
}
