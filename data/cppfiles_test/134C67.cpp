#include <bits/stdc++.h>
using namespace std;
mt19937_64 rnd(72947);
const long long INF = 1e18;
long long t, n;
vector<long long> a;
long long gcd(long long a, long long b) {
  long long c;
  while (b > 0) {
    c = a;
    a = b;
    b = c % b;
  }
  return a;
}
void IO() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
}
int main() {
  cin >> t;
  while (t--) {
    cin >> n;
    a.resize(n);
    for (int i = 0; i < n; i++) {
      cin >> a[i];
    }
    long long gcd1 = 0, gcd2 = 0;
    for (int i = 0; i < n; i += 2) {
      gcd1 = gcd(gcd1, a[i]);
    }
    for (int i = 1; i < n; i += 2) {
      gcd2 = gcd(gcd2, a[i]);
    }
    bool isok = true;
    for (int i = 0; i < n; i += 2) {
      if (a[i] % gcd2 == 0) {
        isok = false;
        break;
      }
    }
    if (isok) {
      cout << gcd2 << '\n';
      continue;
    }
    isok = true;
    for (int i = 1; i < n; i += 2) {
      if (a[i] % gcd1 == 0) {
        isok = false;
        break;
      }
    }
    if (isok) {
      cout << gcd1 << '\n';
    } else {
      cout << 0 << '\n';
    }
  }
  return 0;
}
