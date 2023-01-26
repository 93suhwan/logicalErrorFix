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
  int p, i = 0, q;
  while (k >= pow(2, i)) {
    p = i + 1;
    q = pow(2, i + 1);
    i++;
  }
  if (n <= q) {
    int i = 0;
    int ans, ans1;
    while (n >= pow(2, i)) {
      ans = i;
      ans1 = pow(2, i);
      i++;
    }
    if (ans1 == n) {
      cout << ans << "\n";
    } else {
      cout << ans + 1 << "\n";
    }
  } else {
    int rem = n - q;
    if (rem % k == 0) {
      cout << p + (rem / k) << "\n";
    } else {
      cout << p + (rem / k) + 1 << "\n";
    }
  }
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
