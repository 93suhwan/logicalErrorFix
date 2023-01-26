#include <bits/stdc++.h>
using namespace std;
const long long M = 1e9 + 7;
const long long INF = 1e9 + 7;
const long double eps = 1e-9;
const long long inf = 1e18;
const long long N1 = 2e5 + 10;
const long long MM = 998244353;
long long binexp(long long a, long long b) {
  if (b == 0) return 1;
  if (a == 0 || a == 1) return a;
  long long ret = binexp(a, b / 2);
  if (b % 2)
    return (((ret * ret) % INF) * a) % INF;
  else
    return (ret * ret) % INF;
}
long long fac(long long x) {
  long long fcto = 1;
  for (long long i = 2; i < x + 1; i++) {
    fcto *= i;
    fcto %= INF;
  }
  return fcto;
}
long long inv_fac(long long x) { return binexp(fac(x), INF - 2); }
long long mod_inv(long long x) { return binexp(x, INF - 2); }
long long ncr(long long n, long long r) {
  return ((fac(n) * inv_fac(n - r) % INF) * inv_fac(r)) % INF;
}
void solve(long long test);
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(NULL);
  cout.tie(NULL);
  long long ttt = 1;
  cin >> ttt;
  for (long long test = 0; test < ttt; test++) solve(test);
  return 0;
}
void solve(long long test) {
  long long n;
  cin >> n;
  ;
  cout << (fac(2 * n) * mod_inv(2)) % M << endl;
}
