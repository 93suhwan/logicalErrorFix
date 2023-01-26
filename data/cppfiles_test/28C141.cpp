#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    int a, b, c;
    cin >> a >> b >> c;
    long long s = a + b * 2 + c * 3;
    long long k = s / 2;
    long long w = 0;
    if (c > k / 3) {
      w += 3 * (k / 3);
      k %= 3;
    } else {
      w += c * 3;
      k -= c * 3;
    }
    if (b > k / 2) {
      w += 2 * (k / 2);
      k %= 2;
    } else {
      w += b * 2;
      k -= b * 2;
    }
    if (a > k) {
      w += k;
    } else {
      w += a;
    }
    cout << abs(s - 2 * w) << endl;
  }
  return 0;
}
