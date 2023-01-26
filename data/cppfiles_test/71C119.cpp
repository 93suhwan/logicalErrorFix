#include <bits/stdc++.h>
using namespace std;
const int MAX_N = 5e5 + 5;
const int INF = 0x3f3f3f3f;
const int mod = 1e9 + 7;
const double eps = 1e-6;
int n, k;
long long sum(long long first) {
  long long ans = 0;
  while (first) {
    if (first & 1) ans++;
    first >>= 1;
  }
  return ans;
}
long long calc(long long first) {
  long long p = 0;
  while (first) {
    p |= (1 << (first % 10));
    first /= 10;
  }
  return sum(p);
}
void solve() {
  cin >> n >> k;
  while (calc(n) > k) {
    long long p = n;
    long long r = 1;
    while (calc(p) > k) {
      p /= 10;
      r *= 10;
    }
    r /= 10;
    n = ((n / r) + 1) * r;
  }
  cout << n << "\n";
}
signed main() {
  ios::sync_with_stdio(false);
  int test = 1;
  cin >> test;
  while (test--) {
    solve();
  }
  return 0;
}
