#include <bits/stdc++.h>
using namespace std;
int main() {
  int t, m, n, k;
  cin >> t;
  for (int(_) = (0); (_) < (t); ++(_)) {
    cin >> n >> m >> k;
    int sh = n / m;
    int lo = sh + 1;
    int lc = n % m;
    int sc = m - lc;
    int cur = 1;
    if (lc == 0) {
      for (int(i) = (0); (i) < (k); ++(i)) {
        cout << sh << ' ';
        for (int(j) = (0); (j) < (sh); ++(j)) {
          cout << cur << ' ';
          cur++;
          if (cur == n + 1) {
            cur = 1;
          }
        }
        cout << endl;
      }
    } else {
      cur = 0;
      vector<int> a(n);
      iota(a.begin(), a.end(), 1);
      for (int(i) = (0); (i) < (k); ++(i)) {
        cout << lo << ' ';
        for (int(j) = (0); (j) < (lo); ++(j)) {
          cout << a[cur] << ' ';
          cur++;
          if (cur == n) {
            cur = 1;
          }
        }
        cout << endl;
        cout << sh << ' ';
        for (int(j) = (0); (j) < (sh); ++(j)) {
          cout << a[cur] << ' ';
          cur++;
          if (cur == n) {
            cur = 1;
          }
        }
        rotate(a.begin(), a.begin() + lc * lo, a.end());
        cout << endl;
      }
    }
    cout << endl;
  }
  return 0;
}
