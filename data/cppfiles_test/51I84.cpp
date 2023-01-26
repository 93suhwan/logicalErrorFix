#include <bits/stdc++.h>
using namespace std;
bool getBit(long long num, int idx) { return ((num >> idx) & 1); }
const long long M = 1000, mod = 998244353;
long long cn = 0, x;
const long long N = 2e6 + 20;
long long a[N];
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  long long t;
  cin >> t;
  while (t--) {
    long long a, c, b, n, nm2, nm1 = 1;
    cin >> n;
    a = 1;
    c = -2 * n;
    b = 1;
    nm2 = ceil((-b + sqrt(b - 4.0 * a * c)) / 2.0 * a);
    while ((((nm2 - nm1 + 1) * (nm1 + nm2)) / 2) > n) {
      nm1--;
    }
    if (nm1 == nm2) nm1 = 0;
    cout << nm1 << ' ' << nm2 << '\n';
  }
  return 0;
}
