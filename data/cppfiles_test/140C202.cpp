#include <bits/stdc++.h>
using namespace std;
long long dp[100000];
long long mod = 998244353;
void sieve() {
  memset(dp, true, sizeof(dp));
  for (long long i = 2; i < 100000; i++) {
    if (!dp[i]) continue;
    for (long long j = i * i; j < 10000; j += i) {
      dp[j] = false;
    }
  }
}
void reverse(long long i, long long j, long long a[]) {
  while (i < j) {
    swap(a[i], a[j]);
    i++, j--;
  }
}
bool ispallindrome(string s) {
  long long n = s.length();
  long long half = ceil(n / 2);
  for (long long i = 0; i < half; i++) {
    if (s[i] != s[n - i - 1]) return false;
  }
  return true;
}
long long power(long long n, long long p) {
  if (p == 0) return 1;
  if (n == 1) return 1;
  long long x = power(n, p / 2);
  if (p % 2 == 0) return (x * x) % mod;
  return ((n * x) % mod) * x % mod;
}
bool comp(pair<long long, long long> a, pair<long long, long long> b) {
  if (a.first == b.first) return a.second < b.second;
  return (a.first < b.first);
}
struct cmp1 {
  bool operator()(pair<long long, long long> a, pair<long long, long long> b) {
    if (a.first == b.first) return a.second < b.second;
    return a.first > b.first;
  }
};
void solve() {
  long long n;
  cin >> n;
  long long n1 = sqrt(n);
  long long n2 = cbrt(n);
  long long n3 = sqrt(n2);
  long long ans = n1 + n2 - n3;
  cout << ans << "\n";
}
signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  ;
  long long t;
  cin >> t;
  long long t1 = t;
  while (t--) {
    solve();
  }
  return 0;
}
