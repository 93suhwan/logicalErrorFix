#include <bits/stdc++.h>
using namespace std;
#pragma GCC optimize("O3")
#pragma GCC target("sse4")
long double pi = 3.141592653589793238462643383279;
const long long INF = 1e18 + 10;
template <typename Arg1>
void __f(const char* name, Arg1&& arg1) {
  std::cerr << name << " : " << arg1 << endl;
}
template <typename Arg1, typename... Args>
void __f(const char* names, Arg1&& arg1, Args&&... args) {
  const char* comma = strchr(names + 1, ',');
  std::cerr.write(names, comma - names) << " : " << arg1 << " | ";
  __f(comma + 1, args...);
}
const long long mod = 998244353;
long long power(long long x, long long y) {
  long long res = 1;
  if (x == 0) return 0;
  while (y > 0) {
    if (y & 1) res = (res * x) % mod;
    y = y >> 1;
    x = (x * x) % mod;
  }
  return res;
}
void bruteforce() {}
void init() {}
const long long mxN = 1e5 + 10;
void solve() {
  long long n;
  cin >> n;
  long long s = 0;
  for (long long i = 0; i < n; i++) {
    long long x;
    cin >> x;
    s += x;
  }
  if (s % n) {
    cout << "1\n";
  } else {
    cout << "0\n";
  }
}
signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  init();
  long long T = 1;
  cin >> T;
  for (long long i = 1; i <= T; i++) {
    solve();
  }
}
