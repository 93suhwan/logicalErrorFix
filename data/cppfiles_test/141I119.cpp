#include <bits/stdc++.h>
using namespace std;
long long s, b, a, p, ss;
int t, i;
int main() {
  cin >> t;
  for (; t--;) {
    long long aa, bb;
    int na[20] = {0}, nb[20] = {0}, ns[20] = {0};
    cin >> a >> s;
    b = 0;
    aa = a;
    ss = s;
    p = 1;
    while (1) {
      int ka = aa, ks = ss;
      aa /= 10;
      ss /= 10;
      if (ka == 0 && ks == 0) {
        break;
      }
      na[p] = ka - 10 * aa;
      ns[p] = ks - 10 * ss;
      p++;
    }
    int qa = 1, qs = 1, qb = 1, q = 0;
    for (; qs <= p;) {
      if (ns[qs] >= na[qa]) {
        nb[qb] = ns[qs] - na[qa];
        qs++;
        qa++;
        qb++;
      } else if (ns[qs] < na[qa]) {
        nb[qb] = ns[qs] + ns[qs + 1] * 10 - na[qa];
        qs += 2;
        qa++;
        qb++;
        if (nb[qb - 1] >= 10) {
          q = 1;
          cout << -1 << endl;
          break;
        }
      }
    }
    if (q == 0) {
      for (i = qb - 1; i >= 1; i--) {
        b *= 10;
        b += nb[i];
      }
      if (b < 0)
        cout << -1 << endl;
      else
        cout << b << endl;
    }
  }
  return 0;
}
