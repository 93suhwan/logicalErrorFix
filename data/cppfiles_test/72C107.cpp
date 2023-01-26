#include <bits/stdc++.h>
using namespace std;
int count(int n) {
  int mask = 0;
  while (n != 0) {
    mask |= 1 << (n % 10);
    n /= 10;
  }
  return __builtin_popcount(mask);
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int T;
  cin >> T;
  while (T--) {
    int n, k;
    cin >> n >> k;
    while (count(n) > k) {
      int r = 1, tmp = n;
      while (count(tmp) > k) {
        tmp /= 10;
        r *= 10;
      }
      r /= 10;
      n = (n / r + 1) * r;
    }
    cout << n << '\n';
  }
  return 0;
}
