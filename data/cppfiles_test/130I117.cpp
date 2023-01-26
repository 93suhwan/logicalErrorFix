#include <bits/stdc++.h>
using namespace std;
int qry(int a, int b, int c) {
  cout << "! " << a << " " << b << " " << c << "\n";
  fflush(stdout);
  int q;
  cin >> q;
  return q;
}
int main() {
  int test;
  cin >> test;
  while (test--) {
    int n;
    cin >> n;
    vector<int> inf(n / 3);
    int imp, cr;
    for (int i = 1; i <= n; i += 3) {
      int q = qry(i, i + 1, i + 2);
      inf[(i - 1) / 3] = q;
      if (q == 0) {
        imp = i;
      } else {
        cr = i;
      }
    }
    int ci = 0, cc = 0;
    for (int j = 1; j <= 2; j++) {
      if (qry(imp, cr, imp + j) == 0)
        ci++;
      else
        cc++;
      if (qry(imp, cr, cr + j) == 0)
        ci++;
      else
        cc++;
    }
    if (ci == 4) {
      cr++;
    }
    if (cc == 4) {
      imp++;
    }
    if (qry(imp, cr, imp + 1) == 0) {
      imp = imp + 1;
    }
    if (qry(cr, imp, cr + 1) == 1) {
      cr = cr + 1;
    }
    vector<int> res(n + 1, -1);
    res[imp] = 0;
    res[cr] = 1;
    for (int i = 1; i <= n; i += 3) {
      if (inf[(i - 1) / 3] == 0) {
        if (qry(i, i + 1, cr) == 0) {
          res[i] = 0;
          res[i + 1] = 0;
          if (qry(cr, i, i + 2) == 0) {
            res[i + 2] = 0;
          } else {
            res[i + 2] = 1;
          }
        } else {
          res[i + 2] = 0;
          if (qry(i + 2, cr, i) == 0) {
            res[i] = 0;
            res[i + 1] = 1;
          } else {
            res[i] = 1;
            res[i + 1] = 0;
          }
        }
      } else {
        if (qry(i, i + 1, imp) == 1) {
          res[i] = 1;
          res[i + 1] = 1;
          if (qry(imp, i, i + 2) == 1) {
            res[i + 2] = 1;
          } else {
            res[i + 2] = 0;
          }
        } else {
          res[i + 2] = 1;
          if (qry(i + 2, imp, i) == 1) {
            res[i] = 1;
            res[i + 1] = 0;
          } else {
            res[i] = 0;
            res[i + 1] = 1;
          }
        }
      }
    }
    int k = 0;
    for (int i = 1; i <= n; i++) {
      if (res[i] == 0) k++;
    }
    cout << "! " << k;
    for (int i = 1; i <= n; i++) {
      if (res[i] == 0) cout << " " << i;
    }
    cout << "\n";
    fflush(stdout);
  }
}
