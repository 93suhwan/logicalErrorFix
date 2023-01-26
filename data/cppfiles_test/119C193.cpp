#include <bits/stdc++.h>
using namespace std;
#pragma GCC optimize("-O3")
#pragma GCC optimize("unroll-loops")
long long gcd(long long n, long long n1) {
  while (n != 0 && n1 != 0) {
    if (n > n1)
      n %= n1;
    else
      n1 %= n;
  }
  return n + n1;
}
long long lcm(long long n, long long n1) {
  long long nod = gcd(n, n1);
  return (n / nod) * (n1 / nod) * nod;
}
long long binpow(long long n, long long m) {
  if (m == 0) return 1;
  if (m % 2 == 1)
    return binpow(n, m - 1) * n;
  else {
    long long b = binpow(n, m / 2);
    return b * b;
  }
}
long long INF = 999999999999999999;
long long mod = 998244353;
void solve() {
  long long n;
  cin >> n;
  long long sum = 0;
  for (int i = 0; i < n; i++) {
    long long x;
    cin >> x;
    sum += x;
  }
  cout << (bool)(sum % n) << '\n';
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int tt;
  cin >> tt;
  while (tt--) {
    solve();
  }
  return 0;
}
