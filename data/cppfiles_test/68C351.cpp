#include <bits/stdc++.h>
using namespace std;
long long power(long long a, long long b) {
  long long x = 1;
  while (b--) x *= a;
  return x;
}
void solve() {
  long long n;
  cin >> n;
  long long x = sqrt(n);
  long long y = n - x * x;
  if (y == 0)
    cout << x << " " << 1 << "\n";
  else {
    long long z = y - (x + 1);
    if (y <= x + 1)
      cout << y << " " << x + 1 << "\n";
    else
      cout << x + 1 << " " << x + 1 - z << "\n";
  }
}
signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  long long t;
  cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}
