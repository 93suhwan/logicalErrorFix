#include <bits/stdc++.h>
using namespace std;
long long C3(long long n) {
  if (n < 0) return 0;
  return n * (n - 1) * (n - 2) / 6;
}
long long C2(long long n) {
  if (n < 0) return 0;
  return n * (n - 1) / 2;
}
void solve() {
  long long n;
  cin >> n;
  double p;
  cin >> p;
  if (p == 0) {
    cout << "0\n";
    return;
  }
  for (long long k = 1;; k++) {
    double pr = (double)(k * C2(n - k) / 2.0 + C2(k) * (n - k) + C3(k)) /
                (C3(n - k) + k * C2(n - k) + C2(k) * (n - k) + C3(k));
    if (pr >= p) {
      cout << k << "\n";
      return;
    }
  }
}
signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  long long testcases = 1;
  while (testcases--) solve();
  return 0;
}
