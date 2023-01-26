#include <bits/stdc++.h>
using namespace std;
long long gcd(long long a, long long b) {
  if (a % b == 0)
    return b;
  else
    return gcd(b, a % b);
}
long long a[200005];
int main() {
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
      cin >> a[i];
    }
    long long evenGCD = a[0];
    long long oddGCD = a[1];
    for (int i = 2; i < n; i++) {
      if (i % 2 == 0) {
        evenGCD = gcd(evenGCD, a[i]);
      } else {
        oddGCD = gcd(oddGCD, a[i]);
      }
    }
    long long ans = 0;
    bool ok = true;
    for (int i = 1; i < n; i += 2) {
      if (a[i] % evenGCD == 0) {
        ok = false;
        break;
      }
    }
    if (ok) ans = evenGCD;
    ok = true;
    for (int i = 0; i < n; i += 2) {
      if (a[i] % oddGCD == 0) {
        ok = false;
        break;
      }
    }
    if (ok) ans = oddGCD;
    cout << ans << endl;
  }
  return 0;
}
