#include <bits/stdc++.h>
using namespace std;
long long power(long long x, long long y) {
  if (y == 1) return x;
  return ((y & 1) ? (x * pow(x, y - 1)) : (pow(x * x, y / 2)));
}
void solve() {
  long long l, r;
  cin >> l >> r;
  if (r == l + 1) {
    if ((l & r) == 0)
      cout << 1;
    else
      cout << 0;
    return;
  }
  long long x = 0;
  long long M = LONG_MAX;
  long long k = floor(log2(r));
  for (long long i = k; (i >= k - 2 && i >= 0); i--) {
    x = 0;
    for (long long j = l; j <= r; j++) {
      if ((j & (1 << i)) == 0) {
        x++;
      }
    }
    M = min(M, x);
    x = 0;
  }
  cout << M;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int test_case;
  cin >> test_case;
  for (int t = 1; t <= test_case; t++) {
    solve();
    cout << endl;
  }
  return 0;
}
