#include <bits/stdc++.h>
using namespace std;
int n, q;
long long a[100100], b[100100];
long long res[100100];
long long pref[100100];
struct Sparse {
  long long n;
  long long* tq;
  long long** st;
  long long LOG;
  bool ty;
  long long op(long long a, long long b) {
    if (ty == 1) return max(a, b);
    return min(a, b);
  }
  void build(long long _n, long long* arr, bool _ty) {
    n = _n;
    ty = _ty;
    LOG = 1;
    while ((1 << LOG) <= n) LOG++;
    LOG += 2;
    tq = new long long[_n + 1];
    st = new long long*[LOG];
    for (int i = 0; i < LOG; i++) st[i] = new long long[n];
    buildtq();
    buildst(arr);
  }
  void destroy() {
    for (int i = 0; i < LOG; i++) delete[] st[i];
    delete[] st;
    delete[] tq;
  }
  void buildtq() {
    tq[1] = 0;
    for (int i = 2; i <= n; i++) {
      tq[i] = tq[i - 1];
      if ((1 << (tq[i - 1] + 1)) < i) tq[i]++;
    }
  }
  void buildst(long long* arr) {
    for (int i = 0; i < n; i++) st[0][i] = arr[i];
    for (int i = 1; i < LOG; i++) {
      for (int j = 0; j < n; j++) {
        st[i][j] = st[i - 1][j];
        if (j + (1 << (i - 1)) < n) {
          st[i][j] = op(st[i][j], st[i - 1][j + (1 << (i - 1))]);
        }
      }
    }
  }
  long long query(long long lo, long long hi) {
    long long dif = hi - lo + 1;
    long long co = tq[dif];
    long long res = op(st[co][lo], st[co][hi - (1 << co) + 1]);
    return res;
  }
} minh, maxh;
int main() {
  scanf("%d%d", &n, &q);
  for (int i = 1; i <= n; i++) scanf("%lld", &a[i]);
  for (int i = 1; i <= n; i++) scanf("%lld", &b[i]);
  pref[0] = 0;
  for (int i = 1; i <= n; i++) {
    res[i] = b[i] - a[i];
    pref[i] = pref[i - 1] + res[i];
  }
  minh.build(n + 1, pref, 0);
  maxh.build(n + 1, pref, 1);
  while (q--) {
    int l, r;
    scanf("%d%d", &l, &r);
    long long cnt = pref[r] - pref[l - 1];
    if (cnt) {
      printf("-1\n");
      continue;
    }
    long long cv = minh.query(l, r) - pref[l - 1];
    if (cv < 0) {
      printf("-1\n");
      continue;
    }
    cv = maxh.query(l, r) - pref[l - 1];
    printf("%lld\n", cv);
  }
}
