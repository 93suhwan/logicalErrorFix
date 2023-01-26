#include <bits/stdc++.h>
using namespace std;
long long div_up(long long a, long long b) {
  if (a % b != 0) return a / b + 1;
  return a / b;
}
long long binPow(long long a, long long n) {
  if (n == 0) return 1;
  if (n % 2 == 0) {
    long long d = binPow(a, n / 2);
    return d * d;
  } else
    return a * binPow(a, n - 1);
}
long long lg(long long k) {
  long long l = -1, r = 64;
  while (r - l > 1) {
    long long m = (l + r) / 2;
    if (binPow(2, m) >= k)
      r = m;
    else
      l = m;
  }
  return r;
}
bool ok(long long m, long long n, long long k) {
  long long lgk = lg(k);
  long long ans = binPow(2, min(m, lgk));
  ans += k * max(1ll * 0, m - lgk);
  return ans >= n;
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  long long t;
  cin >> t;
  while (t--) {
    long long n, k;
    cin >> n >> k;
    long long lgk = lg(k);
    long long cnt = binPow(2, lgk);
    if (n <= cnt) {
      cout << lg(n) << endl;
    } else {
      cout << lg(k) + div_up((n - cnt), k) << endl;
    }
  }
  return 0;
}
