#include <bits/stdc++.h>
using namespace std;
void setIO(string s) {
  freopen((s + ".in").c_str(), "r", stdin);
  freopen((s + ".out").c_str(), "w", stdout);
}
const long long mod = 1e9 + 7;
void modify(long long &a) { a %= mod; }
long long pow2(long long a, long long b) {
  long long ans = 1;
  while (b) {
    if (b & 1) ans *= a;
    a *= a;
    b /= 2;
    modify(a);
    modify(ans);
  }
  return ans;
}
long long inv(long long a) { return pow2(a, mod - 2); }
long long fun(int n) {
  if (n == 1) return 6;
  long long x = fun(n - 1);
  x *= x;
  x %= mod;
  x *= 8;
  x %= mod;
  x *= inv(3);
  x %= mod;
  return x;
}
void solve() {
  long long k;
  cin >> k;
  cout << fun(k) << '\n';
}
int main() {
  std::ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  ;
  long long tc = 1;
  for (long long i = 1; i <= tc; i++) {
    solve();
  }
}
