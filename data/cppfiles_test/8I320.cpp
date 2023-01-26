#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  long long T, pozw, n1, x, k, n, mi, m, qqq, b, z, kot, t, w, g, h, sum, f,
      poz, kry, kol, ot, i, q, ma, kolv, p, l, r, y, za, zu, sum1, x1, y1, d,
      ost, ostv;
  string s;
  vector<long long> a, st(61);
  cin >> t;
  for (qqq = 0; qqq < t; qqq = qqq + 1) {
    a.clear();
    cin >> n;
    if (n % 3 == 0) {
      cout << n / 3 << " " << n / 3 << "\n";
    } else {
      cout << n / 3 + 1 << " " << n / 3 << "\n";
    }
  }
  return 0;
}
