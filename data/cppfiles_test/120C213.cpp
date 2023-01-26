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
long long v[31][200005];
void pre() {
  for (long long i = 1; i < 200005; i++) {
    for (long long j = 0; j < 31; j++) {
      if ((i & (1 << j)) != 0) {
        v[j][i]++;
      }
      v[j][i] += v[j][i - 1];
    }
  }
}
void solve() {
  long long l;
  cin >> l;
  long long r;
  cin >> r;
  long long ans = INT_MAX;
  for (long long j = 0; j < 31; j++) {
    long long curr = v[j][r] - v[j][l - 1];
    ans = min(ans, r - l + 1 - curr);
  }
  cout << ans << '\n';
}
signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  pre();
  long long t = 1;
  cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}
