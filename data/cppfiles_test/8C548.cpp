#include <bits/stdc++.h>
using namespace std;
const long long N = 2e5;
const long long mod = 1e9 + 7;
int32_t main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  ;
  long long t;
  cin >> t;
  while (t--) {
    long long n;
    cin >> n;
    long long a = n / 3;
    long long b = (n - n / 3) / 2;
    if (n - a - b * 2 == 1) {
      cout << a + 1 << " " << b << "\n";
    } else if (n - a - b * 2 == 2) {
      cout << a << " " << b + 1 << "\n";
    } else {
      cout << a << " " << b << "\n";
    }
  }
  return 0;
}
