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
    for (int i = 0; i < den.size(); i++) {
      if (i == den.size() - 1) {
        if (k > 0) {
          ans += den[i] * (k + 1);
        }
      } else {
        long long next = den[i + 1];
        long long ct = next / den[i];
        if (k >= (ct - 1)) {
          ct--;
          ans += ct * (den[i]);
          k -= ct;
        } else {
          ans += (k + 1) * (den[i]);
          k = 0;
          break;
        }
      }
    }
    if (den[0] != 1) {
      cout << 1 << "\n";
    } else {
      cout << ans << "\n";
    }
  }
}
