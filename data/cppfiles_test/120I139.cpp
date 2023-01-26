#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
#pragma GCC optimization("unroll-loops")
bool isprime(long long n) {
  for (long long i = 2; i * i <= n; i++) {
    if (n % i == 0) return 0;
  }
  return 1;
}
long long gcd(long long a, long long b) {
  if (b == 0) {
    return a;
  }
  return gcd(b, a % b);
}
long long lcm(long long a, long long b) { return (a / gcd(a, b)) * b; }
using namespace std;
long long value(long long n) {
  long long cnt = -1;
  while (n != 0) {
    n /= 2;
    cnt++;
  }
  return cnt;
}
void solve() {
  long long l;
  cin >> l;
  long long r;
  cin >> r;
  long long pw = value(r);
  long long ans1 = r - pow(2, pw) + 1;
  long long ans2 = pow(2, pw) - pow(2, pw - 1);
  long long max1 = max(ans1 * 1LL, ans2 * 1LL);
  long long ans3 =
      ((r - l + 1) % 2) ? ((r - l + 1) / 2 + 1) : ((r - l + 1) / 2);
  max1 = max(max1, ans3 * 1LL);
  cout << (r - l + 1) - max1 << endl;
}
signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  long long t = 1;
  cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}
