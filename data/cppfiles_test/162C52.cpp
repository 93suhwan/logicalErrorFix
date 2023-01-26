#include <bits/stdc++.h>
using namespace std;
long long inf = (long long)1e18 + 7ll;
int main() {
  long long t;
  cin >> t;
  while (t--) {
    long long n;
    cin >> n;
    long long h[n];
    long long carry[n];
    for (int i = 0; i < n; i++) cin >> h[i];
    long long sum = 0;
    for (int i = 0; i < n; i++) sum += h[i];
    sum /= n;
    long long ans = 1;
    long long s = 0, f = sum + 1, m;
    bool ispossible;
    long long usablecomponent;
    while (s + 1 < f) {
      m = (s + f) / 2ll;
      memset(carry, 0ll, sizeof carry);
      ispossible = true;
      for (int i = n - 1; i >= 2; i--) {
        usablecomponent = h[i] + min(0ll, carry[i] - m);
        if (usablecomponent < 0) {
          ispossible = false;
          break;
        }
        usablecomponent /= 3ll;
        carry[i] -= (3ll * usablecomponent);
        carry[i - 1] += usablecomponent;
        carry[i - 2] += (2ll * usablecomponent);
      }
      if (ispossible) {
        ispossible = (((h[1] + carry[1]) >= m) and ((h[0] + carry[0]) >= m));
      }
      if (ispossible)
        s = m;
      else
        f = m - 1;
    }
    ans = s;
    if (s != f) {
      memset(carry, 0ll, sizeof carry);
      ispossible = true;
      for (int i = n - 1; i >= 2; i--) {
        usablecomponent = h[i] + min(0ll, carry[i] - f);
        if (usablecomponent < 0) {
          ispossible = false;
          break;
        }
        usablecomponent /= 3ll;
        carry[i] -= (3ll * usablecomponent);
        carry[i - 1] += usablecomponent;
        carry[i - 2] += (2ll * usablecomponent);
      }
      if (ispossible) {
        ispossible = (((h[1] + carry[1]) >= f) and ((h[0] + carry[0]) >= f));
      }
      if (ispossible) ans = f;
    }
    cout << ans << endl;
  }
  return 0;
}
