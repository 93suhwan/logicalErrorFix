#include <bits/stdc++.h>
using namespace std;
template <typename Arg1>
void pn(Arg1&& arg1) {
  cout << arg1 << "\n";
}
template <typename Arg1, typename... Args>
void pn(Arg1&& arg1, Args&&... args) {
  cout << arg1 << "\n";
  pn(args...);
}
template <typename Arg1>
void ps(Arg1&& arg1) {
  cout << arg1 << " ";
}
template <typename Arg1, typename... Args>
void ps(Arg1&& arg1, Args&&... args) {
  cout << arg1 << " ";
  ps(args...);
}
template <typename Arg1>
void pvs(Arg1&& arg1, long long n) {
  for (long long i = 0; i < n; i++) ps(arg1[i]);
}
template <typename Arg1>
void pvn(Arg1&& arg1, long long n) {
  for (long long i = 0; i < n; i++) pn(arg1[i]);
}
long long sum(long long n) {
  long long v = 0;
  while (n != 0) {
    v += (n % 10);
    n /= 10;
  }
  return v;
}
long long log(long long n, long long b) {
  long long c = 0;
  while (n > (b - 1)) {
    c++;
    n /= b;
  }
  return c;
}
const long long MOD = 998244353;
const long long inf = 1e18;
const long long MAX = 2e5 + 1;
long long GCD(long long a, long long b) {
  if (b == 0)
    return a;
  else
    return GCD(b, a % b);
}
long long mulmod(long long x, long long n, long long M) {
  long long result = 1;
  while (n > 0) {
    if (n % 2 == 1) result = (result * x) % M;
    x = (x * x) % M;
    n = n / 2;
  }
  return result;
}
bool isPowerOfTwo(long long n) {
  if (n == 0) return 0;
  while (n != 1) {
    if (n % 2 != 0) return 0;
    n = n / 2;
  }
  return 1;
}
void solve() {
  long long a, b, c;
  cin >> a >> b >> c;
  long long p = min(a, b);
  long long q = max(a, b);
  long long bottom = q - p + 1;
  long long total = 2 * (bottom - 1);
  if (p == 1) {
    if (q == bottom) {
      long long ans = bottom + c - 1;
      pn(ans);
    } else {
      pn(-1);
    }
    return;
  }
  if (c > total || p >= bottom || q <= bottom) {
    pn(-1);
    return;
  }
  long long ans = bottom + c - 1;
  if (c == bottom) ans = 1;
  pn(ans);
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  ;
  long long t;
  cin >> t;
  for (long long tt = 1; tt <= t; tt++) {
    solve();
  }
}
