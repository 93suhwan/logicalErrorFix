#include <bits/stdc++.h>
using namespace std;
struct dat {
  long long a = 0, b = 0, c = 0, d = 0, e = 0;
};
struct dx {
  long long cc = 0, cccl = 0;
};
long long t, n;
dat p[200005];
string s;
bool checka(dat x, dat y) {
  if (x.a - x.b - x.c - x.d - x.e > y.a - y.b - y.c - y.d - y.e) return true;
  return false;
}
bool checkb(dat x, dat y) {
  if (x.b - x.a - x.c - x.d - x.e > y.b - y.a - y.c - y.d - y.e) return true;
  return false;
}
bool checkc(dat x, dat y) {
  if (x.c - x.b - x.a - x.d - x.e > y.c - y.b - y.a - y.d - y.e) return true;
  return false;
}
bool checkd(dat x, dat y) {
  if (x.d - x.b - x.c - x.a - x.e > y.d - y.b - y.c - y.a - y.e) return true;
  return false;
}
bool checke(dat x, dat y) {
  if (x.e - x.b - x.c - x.d - x.a > y.e - y.b - y.c - y.d - y.a) return true;
  return false;
}
int main() {
  cin >> t;
  while (t--) {
    scanf("%lld", &n);
    for (int i = 1; i <= n; i++) {
      cin >> s;
      for (int j = 0; j <= s.length() - 1; j++) {
        if (s[j] == 'a') p[i].a++;
        if (s[j] == 'b') p[i].b++;
        if (s[j] == 'c') p[i].c++;
        if (s[j] == 'd') p[i].d++;
        if (s[j] == 'e') p[i].e++;
      }
    }
    sort(p + 1, p + 1 + n, checka);
    int pa = 0, resa = 0;
    for (int i = 1; i <= n; i++) {
      dat x = p[i];
      if (resa + x.a - x.b - x.c - x.d - x.e > 0) {
        pa++;
        resa += x.a - x.b - x.c - x.d - x.e;
      } else
        break;
    }
    sort(p + 1, p + 1 + n, checkb);
    int pb = 0, resb = 0;
    for (int i = 1; i <= n; i++) {
      dat x = p[i];
      if (resb + x.b - x.a - x.c - x.d - x.e > 0) {
        pb++;
        resb += x.b - x.a - x.c - x.d - x.e;
      } else
        break;
    }
    sort(p + 1, p + 1 + n, checkc);
    int pc = 0, resc = 0;
    for (int i = 1; i <= n; i++) {
      dat x = p[i];
      if (resc + x.c - x.b - x.a - x.d - x.e > 0) {
        pc++;
        resc += x.c - x.b - x.a - x.d - x.e;
      } else
        break;
    }
    sort(p + 1, p + 1 + n, checkd);
    int pd = 0, resd = 0;
    for (int i = 1; i <= n; i++) {
      dat x = p[i];
      if (resd + x.d - x.b - x.c - x.a - x.e > 0) {
        pd++;
        resd += x.d - x.b - x.c - x.a - x.e;
      } else
        break;
    }
    sort(p + 1, p + 1 + n, checke);
    int pe = 0, rese = 0;
    for (int i = 1; i <= n; i++) {
      dat x = p[i];
      if (rese + x.e - x.b - x.c - x.d - x.a > 0) {
        pe++;
        rese += x.e - x.b - x.c - x.a - x.d;
      } else
        break;
    }
    cout << max(max(pa, pb), max(max(pc, pd), pe)) << endl;
    for (int i = 1; i <= n; i++) {
      p[i].a = 0;
      p[i].b = 0;
      p[i].c = 0;
      p[i].d = 0;
      p[i].e = 0;
    }
  }
}
