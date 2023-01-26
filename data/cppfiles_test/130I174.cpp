#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e4 + 7, inf = 2e9 + 9, mod = 1e9 + 7;
int n, m[maxn];
bool f(int x, int y, int z) {
  printf("? %d %d %d\n", x, y, z);
  int res;
  scanf("%d", &res);
  if (res == -1) exit(0);
  return res;
}
int m0, m1, a, b, c, x, y, z;
bool p(int i) {
  return (i == a or i == b or i == c or i == x or i == y or i == z);
}
void solve() {
  scanf("%d", &n);
  bool _0 = false, _1 = false;
  for (int i = 1; i < n + 1; i += 3) {
    if (f(i, i + 1, i + 2)) {
      if (!_1) {
        a = i;
        b = i + 1;
        c = i + 2;
        _1 = true;
      }
    } else {
      if (!_0) {
        x = i;
        y = i + 1;
        z = i + 2;
        _0 = true;
      }
    }
    if (_1 and _0) break;
  }
  if (f(a, b, x)) {
    if (f(a, b, y)) {
      m[a] = m[b] = 1;
      m1 = a;
      if (f(x, y, a)) {
        m[z] = 0;
        m0 = z;
        m[c] = f(c, a, z);
        m[x] = f(x, a, z);
        m[y] = f(y, a, z);
      } else {
        m[x] = m[y] = 0;
        m0 = x;
        m[c] = f(c, a, x);
        m[z] = f(z, a, x);
      }
    } else {
      m1 = x;
      m0 = y;
      m[c] = 1;
      m[x] = 1;
      m[y] = m[z] = 0;
      m[a] = f(a, x, y);
      m[b] = !m[a];
    }
  } else {
    m0 = x;
    m1 = c;
    m[x] = 0;
    m[c] = 1;
    m[a] = f(a, x, c);
    m[b] = !m[a];
    m[y] = f(y, x, c);
    m[z] = f(z, x, c);
  }
  for (int i = 1; i < n + 1; ++i) {
    if (p(i)) continue;
    m[i] = f(i, m0, m1);
  }
  vector<int> v;
  for (int i = 1; i < n + 1; ++i) {
    if (!m[i]) v.push_back(i);
  }
  int sz = v.size();
  printf("! %d ", sz);
  for (int i = 0; i < sz; ++i) printf("%d%c", v[i], " \n"[i == sz - 1]);
}
int main() {
  setbuf(stdout, NULL);
  int test;
  scanf("%d", &test);
  while (test--) solve();
  return 0;
}
