#include <bits/stdc++.h>
using namespace std;
long long power(long long x, long long y) {
  long long res = 1;
  x = x % 1000000007;
  while (y > 0) {
    if (y & 1) res = (res * x) % 1000000007;
    y = y >> 1;
    x = (x * x) % 1000000007;
  }
  return res % 1000000007;
}
long long inv(long long n) { return power(n, 1000000007 - 2) % 1000000007; }
long long isprime(long long n) {
  if (n < 2) return 0;
  long long i;
  for (i = 2; i * i <= n; i++)
    if (n % i == 0) return 0;
  return 1;
}
void solve() {
  long long ans = 1e18;
  string s;
  long long n;
  cin >> n >> s;
  for (char ch = 'a'; ch <= 'z'; ch++) {
    long long i = 0, j = n - 1;
    long long moves = 0;
    long long ok = 1;
    while (i < j) {
      if (s[i] == s[j]) {
        i++, j--;
      } else if (s[i] == ch) {
        i++;
        moves++;
      } else if (s[j] == ch) {
        j--;
        moves++;
      } else {
        ok = 0;
        break;
      }
    }
    if (ok) {
      ans = min(ans, moves);
    }
  }
  if (ans > n) ans = -1;
  cout << ans << "\n";
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
