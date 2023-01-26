#include <bits/stdc++.h>
using namespace std;
int main() {
  long long t;
  cin >> t;
  while (t--) {
    long long n, i, j, k, count = 0, sum = 1, f = 0;
    cin >> n >> j >> k;
    count = (n * 1) + (j * 2) + (k * 3);
    if (count % 2 == 0) {
      cout << 0 << "\n";
    } else {
      cout << 1 << "\n";
    }
  }
  return 0;
}
