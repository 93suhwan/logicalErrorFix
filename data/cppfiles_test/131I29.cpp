#include <bits/stdc++.h>
using namespace std;
int abc;
mt19937 rnd((unsigned long long)(new char));
int rd(int l, int r) {
  uniform_int_distribution<> ee(l, r);
  return ee(rnd);
}
void NC(unsigned long long k) { cout << (k >> 20) << endl; }
const int mxn = 2e5 + 3, mxm = mxn * 20;
map<int, int> tr[mxm];
int n, b[mxn], m, nn, xl[mxn], mx[mxm], ed[mxm], po[mxm];
int r1, r2, ans;
int H(int x) {
  if (!x) return 0;
  return 32 - __builtin_clz(x);
}
int gv(int x) {
  if (!x) return 1;
  int k = 1 << H(x - 1);
  return k - x;
}
void upd(int x, int y, int z) {
  if (x <= 0 || y <= 0 || x == y || z <= ans) return;
  ans = z, r1 = x, r2 = y;
}
int main() {
  cin >> n;
  for (int i = 1; i <= n; ++i) abc = scanf("%d", b + i);
  r1 = 1, r2 = 2;
  for (int t = 1; t <= n; ++t) {
    int x = b[t];
    m = 0;
    for (; x; x = gv(x)) xl[++m] = x;
    int d = 0;
    for (int i = m; ~i; --i) {
      int c = xl[i];
      if (!tr[d][c]) tr[d][c] = ++nn;
      d = tr[d][c];
      if (i >= mx[d]) mx[d] = i, po[d] = t;
    }
  }
  for (int i = 0; i <= m; ++i) {
    int v1 = -1, v2 = -1, p1 = 0, p2 = 0;
    for (pair<int, int> k : tr[i]) {
      int x = k.second;
      if (mx[x] > v1)
        v2 = v1, p2 = p1, p1 = po[x], v1 = mx[x];
      else if (mx[x] > v2)
        v2 = mx[x], p2 = po[x];
    }
    upd(p1, p2, v1 + v2);
  }
  printf("%d %d %d\n", r1, r2, ans);
  return 0;
}
