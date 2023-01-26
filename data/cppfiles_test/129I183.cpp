#include <bits/stdc++.h>
using namespace std;
long long gcd(long long a, long long b) { return b ? gcd(b, a % b) : a; }
int main() {
  long long t;
  cin >> t;
  while (t--) {
    long long n;
    cin >> n;
    vector<long long> a(n);
    for (long long i = 0; i < n; i++) {
      cin >> a[i];
    }
    sort(a.begin(), a.end());
    long long f = 0;
    long long ans = 0;
    for (long long i = 0; i < n; i++) {
      if (i + 1 != a[i]) {
        if (a[i] % 2 == 0 && a[i] / 2 > i + 1 ||
            a[i] % 2 == 1 && a[i] / 2 + 1 > i + 1) {
          ans++;
        } else {
          f = 1;
        }
      }
      if (f) {
        break;
      }
    }
    if (f) {
      cout << -1 << "\n";
    } else {
      cout << ans << "\n";
    }
  }
  return 0;
}
