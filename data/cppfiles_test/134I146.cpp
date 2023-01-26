#include <bits/stdc++.h>
using namespace std;
int main() {
  long long i, n, m, j, k, l, x, q, f;
  vector<long long> a, b;
  cin >> n;
  string s, s2;
  for (i = 0; i < n; i++) {
    cin >> x;
    for (j = 0; j < x; j++) {
      cin >> m;
      a.push_back(m);
    }
    for (j = 0; j < x; j++) {
      f = 0;
      for (q = 1; q < x; q++) {
        if ((a[q] % a[j] == 0 && a[q - 1] % a[j] == 0) ||
            (a[q] % a[j] != 0 && a[q - 1] % a[j] != 0)) {
          f = 1;
          break;
        }
        if (q == x - 1) {
          cout << a[j] << endl;
          break;
        }
      }
      if (q == x - 1 && f == 0) break;
      if (j == x - 1) cout << 0 << endl;
    }
    a = b;
  }
  return 0;
}
