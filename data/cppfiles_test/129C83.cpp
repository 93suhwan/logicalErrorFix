#include <bits/stdc++.h>
using namespace std;
long long gcd(long long a, long long b) { return b ? gcd(b, a % b) : a; }
int main() {
  long long t;
  cin >> t;
  while (t--) {
    long long n;
    cin >> n;
    vector<long long> a;
    vector<long long> b(n + 1);
    long long p;
    for (long long i = 0; i < n; i++) {
      cin >> p;
      if (p <= n && b[p] == 0) {
        b[p] = 1;
      } else {
        a.push_back(p);
      }
    }
    sort(a.begin(), a.end());
    long long f = 0;
    long long ans = 0;
    long long j = 0;
    for (long long i = 1; i <= n; i++) {
      if (b[i] == 1) {
        continue;
      }
      if (i != a[j]) {
        if (a[j] % 2 == 0 && long long(a[j] / 2) > i ||
            a[j] % 2 == 1 && long long(a[j] / 2) + 1 > i) {
          ans++;
        } else {
          f = 1;
        }
        j++;
      } else {
        j++;
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
