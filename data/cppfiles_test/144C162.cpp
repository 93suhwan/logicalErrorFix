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
    vector<int> a(n);
    iota(a.begin(), a.end(), 1);
    for (int(i) = (0); (i) < (k); ++(i)) {
      int cur = 0;
      for (int(q) = (0); (q) < (lc); ++(q)) {
        cout << lo << ' ';
        for (int(j) = (0); (j) < (lo); ++(j)) {
          cout << a[cur] << ' ';
          cur++;
        }
        cout << endl;
      }
      for (int(q) = (0); (q) < (sc); ++(q)) {
        cout << sh << ' ';
        for (int(j) = (0); (j) < (sh); ++(j)) {
          cout << a[cur] << ' ';
          cur++;
        }
      }
      rotate(a.begin(), a.begin() + lc * lo, a.end());
      cout << endl;
    }
    cout << endl;
  }
  return 0;
}
