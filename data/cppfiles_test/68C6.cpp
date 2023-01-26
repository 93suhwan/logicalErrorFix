#include <bits/stdc++.h>
using namespace std;
int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  long long t;
  cin >> t;
  while (t--) {
    long long k;
    cin >> k;
    long long mal = 0;
    for (long long i = 1; i < 100000; i++) {
      if (i * i + 1 > k) {
        mal = i;
        break;
      }
    }
    long long r = 1, c = mal;
    long long z = (mal - 1) * (mal - 1) + 1;
    while (r < mal) {
      if (z == k) {
        break;
      } else {
        z++;
        r++;
      }
    }
    while (z != k) {
      z++;
      c--;
    }
    cout << r << " " << c << "\n";
  }
  return 0;
}
