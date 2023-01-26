#include <bits/stdc++.h>
using namespace std;
int main() {
  long long t;
  cin >> t;
  for (int i = 1; i <= t; i++) {
    long long n, k;
    cin >> n >> k;
    n--;
    long long a = (sqrt(8 * n + 1) - 1) / 2;
    while (a * (a + 1) < 2 * n) {
      a++;
    }
    if (k >= a) {
      cout << a << "\n";
      continue;
    } else {
      long long ds = k;
      n -= k * (k + 1) / 2;
      if (n % k == 0)
        cout << k + n / k << "\n";
      else
        cout << k + n / k + 1 << "\n";
    }
  }
  return 0;
}
