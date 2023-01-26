#include <bits/stdc++.h>
using namespace std;
const double pi = 2 * acos(0.0);
long long Abs(long long x) {
  if (x < 0) return x * -1;
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int test;
  cin >> test;
  for (int tc = 1; tc <= test; tc++) {
    long long n;
    cin >> n;
    long long low = 0, high = n;
    long long c1 = 0, c2 = 0;
    long long x = 0, y = n, dif = 9223372036854775806;
    while (low <= high) {
      c2 = (low + high) / 2;
      c1 = n - 2 * c2;
      if (Abs(dif) > Abs(c1 - c2)) {
        dif = Abs(c1 - c2);
        x = c1;
        y = c2;
      }
      if (c1 < c2) {
        high = c2 - 1;
      } else if (c1 > c2) {
        low = c2 + 1;
      } else {
        break;
      }
    }
    cout << x << " " << y << "\n";
  }
  return 0;
}
