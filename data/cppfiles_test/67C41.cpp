#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int t;
  t = 1;
  while (t--) {
    long long n, k;
    double p;
    cin >> n >> p;
    long long p1 = p * 10000000;
    for (k = 0; k <= n; k++) {
      long long ans = 0;
      if (n - k >= 2) ans += 3 * (k * (n - k) * (n - k - 1));
      if (n - k >= 1) ans += 6 * (k * (k - 1) * (n - k));
      if (k >= 3) ans += 2 * (k * (k - 1) * (k - 2));
      ans = (ans * 60000000);
      if (ans - p1 * (n * (n - 1) * (n - 2)) * 12 >= 0) break;
    }
    cout << k << endl;
  }
  return 0;
}
