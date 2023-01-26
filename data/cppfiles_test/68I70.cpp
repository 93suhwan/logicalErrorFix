#include <bits/stdc++.h>
using namespace std;
int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  long long t = 1;
  cin >> t;
  while (t--) {
    long long n;
    cin >> n;
    if (sqrt(n) * sqrt(n) == n) {
      cout << (long long)sqrt(n) << " " << 1 << "\n";
      continue;
    }
    long long x1 = ((long long)sqrt(n)), y1 = ((long long)sqrt(n) + 1);
    long long x = x1 * x1;
    long long y = y1 * y1;
    long long middle = x + (y - x) / 2 + 1;
    if (n == middle) {
      cout << y1 << " " << y1 << "\n";
    } else if (n > middle) {
      cout << y1 << " " << y - n + 1 << "\n";
    } else {
      cout << n - x << " " << y1 << "\n";
    }
  }
  return 0;
}
