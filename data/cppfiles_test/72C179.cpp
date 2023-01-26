#include <bits/stdc++.h>
using namespace std;
int countDigits(int i) {
  int z = 0, c = i;
  while (c) {
    z |= (1 << (c % 10)), c /= 10;
  }
  return __builtin_popcount(z);
}
void solve() {
  int n, k;
  cin >> n >> k;
  while (countDigits(n) > k) {
    int r = 1, l = n;
    while (countDigits(l) > k) l /= 10, r *= 10;
    r /= 10;
    n = ((n / r) + 1) * r;
  }
  cout << n << endl;
}
int main() {
  ios_base::sync_with_stdio(false), cin.tie(nullptr);
  int T;
  cin >> T;
  while (T--) solve();
}
