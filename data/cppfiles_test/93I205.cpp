#include <bits/stdc++.h>
using namespace std;
long long pow(long long x, long long y) {
  if (y == 0) {
    return 1;
  }
  return x * pow(x, y - 1);
}
void solve() {
  long long n, k;
  cin >> n >> k;
  if (n == 1) {
    cout << 0 << "\n";
    return;
  }
  long long p, i = 0, q;
  while (k >= pow(2, i)) {
    p = i + 1;
    q = pow(2, i + 1);
    i++;
  }
  long long rem = n - q;
  long long ans = 0;
  if (rem > 0) {
    if (rem % k != 0) {
      ans = (rem / k) + 1;
    } else {
      ans = rem / k;
    }
  }
  cout << ans + p << "\n";
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  long long tc;
  cin >> tc;
  while (tc--) {
    solve();
  }
  return 0;
}
