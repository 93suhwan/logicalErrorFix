#include <bits/stdc++.h>
using namespace std;
int main() {
  long long a, b, c, d, e, i, j, k, l, r, a1, a2, a3, b1, b2, b3, x1, y1, x, y,
      t, f, l1, r1;
  string s, s1, s2, s3, T;
  vector<long long> v, v1, v2, o;
  cin >> t;
  for (f = 0; f < t; f++) {
    long long o = 0;
    cin >> l >> r;
    v = {};
    for (i = 0; i < 20; i++) {
      v.push_back(r - l + 1);
    }
    j = 1;
    long long maxx = 0;
    l1 = l;
    r1 = r;
    int maxp = 0;
    for (i = 0; i < 20; i++) {
      l = l1;
      r = r1;
      long long o = 0;
      int maxp;
      if (((l / j) % 2) != 1) {
        l = (((l - 1) / j) + 1) * j;
      } else {
        o += min(((((l - 1) / j) + 1) * j) - l, r - l + 1);
        l = ((((l - 1) / j) + 1) * j);
      }
      if (l < (r + 1)) {
        if ((r / j) % 2 == 0) {
          r = ((r) / j) * j;
        } else {
          o += min(r - (((r) / j) * j), r - l);
          r = ((r) / j) * j;
        }
        if (l < (r + 1)) {
          if (((l / j) % 2) == 1) {
            if (l == r) {
              o++;
            } else {
              o += ((((r - l + 1) / (j)) + 1) / 2) * j;
            }
          } else {
            o += ((((r - l + 1) / (j))) / 2) * j;
          }
        }
      }
      j = j * 2;
      if (o > maxx) {
        maxx = o;
        maxp = j;
      }
    }
    cout << (r1 - l1 + 1) - maxx << "\n";
  }
}
