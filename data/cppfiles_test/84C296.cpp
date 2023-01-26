#include <bits/stdc++.h>
using namespace std;
long long int mod = 1e9 + 7;
long long int POW(long long int x, long long int y) {
  long long int res = 1;
  if (y < 0) {
    res = 0;
  }
  while (y > 0) {
    if (y & 1) {
      res = (res * x) % mod;
      y--;
    }
    x = (x * x) % mod;
    y = y >> 1;
  }
  return res;
}
void soln() {
  long long int i, j, i1, i2, i3;
  long long int n, m, q, k, x;
  cin >> n >> k;
  long long int l1 = (n + 1) / 2 - 1;
  cout << k / (n - l1) << "\n";
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  long long int TC;
  cin >> TC;
  while (TC--) {
    soln();
  }
  return 0;
}
