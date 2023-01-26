#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e6 + 10, maxq = 100 + 2, mad = 1e9 + 7;
int main() {
  int t;
  cin >> t;
  while (t--) {
    long long n;
    cin >> n;
    long double s = 10.0, u = 8.0, y = 6.00;
    long long f = ceil(n / s) * 25, ss = ceil(n / y) * 15, h = ceil(n / u) * 20;
    cout << min(f, min(ss, h)) << "\n";
  }
}
