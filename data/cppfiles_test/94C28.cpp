#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    long long n, k;
    cin >> n >> k;
    vector<long long> den;
    for (int i = 0; i < n; i++) {
      long long a;
      cin >> a;
      den.push_back(pow(10, a));
    }
    long long ans = 0;
    k++;
    for (int i = 0; i < n; i++) {
      if (i == n - 1) {
        ans += (k * den[i]);
      } else {
        long long ct = den[i + 1] / den[i];
        ct--;
        ans += den[i] * min(ct, k);
        k -= min(ct, k);
      }
    }
    if (den[0] != 1) {
      cout << 1 << "\n";
    } else {
      cout << ans << "\n";
    }
  }
}
