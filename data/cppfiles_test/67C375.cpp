#include <bits/stdc++.h>
using namespace std;
int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  long long int t;
  cin >> t;
  while (t--) {
    long long int a, b, c;
    cin >> a >> b >> c;
    long long int n = 2 * abs(a - b);
    if (a > n or b > n or c > n)
      cout << -1 << "\n";
    else {
      long long int d = n / 2 + c;
      while (d > n) d = d - n;
      cout << d << "\n";
    }
  }
  return 0;
}
