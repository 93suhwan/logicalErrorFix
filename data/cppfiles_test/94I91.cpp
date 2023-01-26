#include <bits/stdc++.h>
using namespace std;
inline long long md(long long m, long long v) { return ((v % m) + m) % m; }
inline long long poww(long long a, long long b, long long mod = -1) {
  long long ret = 1;
  while (b) {
    if (b & 1) {
      ret *= a;
      if (~mod) ret %= mod;
    }
    a *= a;
    if (~mod) a %= mod;
    b >>= 1;
  }
  return ret;
}
void solve() {
  long long n;
  cin >> n;
  vector<int> debt(100);
  long long a = 0;
  int a_cnt = 0;
  long long b = 0;
  int b_cnt = 0;
  int m = 1;
  for (int i = 0; n; i++) {
    if (i % 2 == 0) {
      a += (n % 10) * m;
      a_cnt++;
    } else {
      b += (n % 10) * m;
      b_cnt++;
    }
    n /= 10;
    if (i % 2 == 1) m *= 10;
  }
  if (a > b) swap(a, b);
  1;
  if (a == 0 && b == 0) {
    cout << 1 << "\n";
  } else if (a == 0) {
    cout << b - 1 << "\n";
  } else if (a == 1) {
    cout << b * 2 << "\n";
  } else {
    cout << (a - 1) * (b - 1) << "\n";
  }
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(NULL);
  int tt;
  cin >> tt;
  for (int t = 1; t <= tt; t++) {
    solve();
  }
  return 0;
}
