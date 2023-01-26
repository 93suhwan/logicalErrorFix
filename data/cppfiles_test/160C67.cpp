#include <bits/stdc++.h>
using namespace std;
long long binpow(long long a, long long b) {
  long long res = 1;
  while (b > 0) {
    if (b & 1) res = res * a;
    a = a * a;
    b >>= 1;
  }
  return res;
}
long long binpow(long long a, long long b, long long m) {
  a %= m;
  long long res = 1;
  while (b > 0) {
    if (b & 1) res = res * a % m;
    a = a * a % m;
    b >>= 1;
  }
  return res;
}
long long mod_inv(long long n, long long md) { return binpow(n, md - 2, md); }
long long fact(int n) {
  long long f = 1;
  for (long long i = 1; i <= n; i++) {
    f = (f * i) % 1000000007;
  }
  return f;
}
long long ncr(int n, int r) {
  long long fn = fact(n);
  long long fr = fact(r);
  long long fnr = fact(n - r);
  long long ans = (fn * mod_inv(fr, 1000000007)) % 1000000007;
  ans = (ans * mod_inv(fnr, 1000000007)) % 1000000007;
  return ans;
}
void solve() {
  int n, m, rb, cb, rd, cd;
  cin >> n >> m >> rb >> cb >> rd >> cd;
  int count = 0;
  int inr = 1, inc = 1, flagr = 1, flagc = 1;
  while (rb != rd && cb != cd) {
    if (rb < n && flagr)
      inr = 1;
    else if (rb < n && !flagr) {
      inr = -1;
    } else if (rb >= n) {
      inr = -1;
      flagr = 0;
    }
    if (cb < m && flagc)
      inc = 1;
    else if (cb < m && !flagc)
      inc = -1;
    else if (cb >= m)
      inc = -1, flagc = 0;
    rb += inr;
    cb += inc;
    count++;
  }
  cout << count << "\n";
}
int main() {
  ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
  long long t = 1;
  cin >> t;
  while (t--) {
    solve();
  }
}
