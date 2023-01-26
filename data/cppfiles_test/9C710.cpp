#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  long long T, pozw, n1, x, k, n, mi, m, qqq, b, z, kot, t, w, g, h, sum, f,
      poz, kry, kol, ot, i, q, ma, kolv, p, l, r, y, za, zu, sum1, x1, y1, d,
      ost, ostv;
  string s;
  vector<long long> a, st(61), vt(26);
  cin >> t;
  for (qqq = 0; qqq < t; qqq = qqq + 1) {
    a.clear();
    cin >> s;
    y = s.size();
    for (i = 0; i < 26; i = i + 1) {
      vt[i] = 0;
    }
    for (i = 0; i < y; i = i + 1) {
      x = s[i] - 'a';
      vt[x] = vt[x] + 1;
    }
    kol = 0;
    kolv = 0;
    for (i = 0; i < 26; i = i + 1) {
      if (vt[i] >= 2) {
        kol = kol + 1;
      } else {
        if (vt[i] == 1) {
          kolv = kolv + 1;
        }
      }
    }
    cout << kol + kolv / 2 << "\n";
  }
  return 0;
}
