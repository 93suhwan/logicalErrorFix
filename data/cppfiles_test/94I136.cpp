#include <bits/stdc++.h>
using namespace std;
long long t, n, k;
void solve() {
  cin >> n >> k;
  long long a[11];
  long long res = 0;
  for (long long i = 1; i <= n; i++) {
    long long num;
    cin >> a[i];
  }
  for (long long i = 1; i <= n - 1; i++) {
    if (k > pow(10, a[i + 1] - a[i]) - 1) {
      res += pow(10, a[i + 1]) - pow(10, a[i]);
      k -= pow(10, a[i + 1] - a[i]) - 1;
    } else if (k < pow(10, a[i + 1] - a[i]) - 1) {
      res += (k + 1) * pow(10, a[i]);
      cout << res << endl;
      return;
    }
  }
  cout << res + (long long)pow(10, a[n]) * (k + 1) << endl;
}
int main() {
  cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}
