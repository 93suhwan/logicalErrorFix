#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, m, t;
  double p, s;
  cin >> n >> p;
  t = n * (n - 1) * (n - 2) / 6;
  for (m = 0; m < n; m++) {
    s = m * (m - 1) * (m - 2) / 6 + m * (m - 1) * (n - m) / 2 +
        m * (n - m) * (n - m - 1) / 4;
    if (s >= p * t) {
      break;
    }
  }
  cout << m << endl;
  return 0;
}
