#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e4 + 7, inf = 2e9 + 9, mod = 1e9 + 7;
int n, m[maxn], m3[maxn];
int m0, m1, a, b, c, x, y, z;
bool f(int x, int y, int z) {
  printf("? %d %d %d\n", x, y, z);
  int res;
  scanf("%d", &res);
  if (res == -1) exit(0);
  return res;
}
bool p(int i) {
  return (i == a or i == b or i == c or i == x or i == y or i == z);
}
void solve() {
  vector<int> v;
  scanf("%d", &n);
  bool _0 = false, _1 = false;
  for (int i = n + 3; i >= 0; --i) {
    m3[i] = -1;
  }
  for (int i = 1; i < n + 1; i += 3) {
    if (f(i, i + 1, i + 2)) {
      m3[i] = 1;
      if (!_1) {
        a = i;
        b = i + 1;
        c = i + 2;
        _1 = true;
      }
    } else {
      m3[i] = 0;
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
  if (!m[a]) v.push_back(a);
  if (!m[b]) v.push_back(b);
  if (!m[c]) v.push_back(c);
  if (!m[x]) v.push_back(x);
  if (!m[y]) v.push_back(y);
  if (!m[z]) v.push_back(z);
  int rest = -1;
  for (int i = 1; i < n + 1; i += 3) {
    if (p(i)) {
      continue;
    }
    int rem = n - i + 1;
    if (i < a) rem -= 3;
    if (i < x) rem -= 3;
    if (v.size() == 2 * n / 3 - 1) {
      rest = 1;
    } else if (rem == n / 3 - v.size()) {
      rest = 0;
    }
    if (rest != -1) {
      m[i] = m[i + 1] = m[i + 2] = rest;
      for (int j = 0; j < 3; ++j) {
        if (!m[i + j]) v.push_back(i + j);
      }
      continue;
    }
    if (m3[i] == -1) {
      m[i] = f(i, m0, m1);
      m[i + 1] = f(i + 1, m0, m1);
      m[i + 2] = f(i + 2, m0, m1);
    } else {
      m[i] = f(i, m0, m1);
      if (m[i] != m3[i]) {
        m[i + 1] = m3[i];
        m[i + 2] = m3[i];
      } else {
        m[i + 1] = f(i + 1, m0, m1);
        if (m[i + 1] != m3[i])
          m[i + 2] = m3[i];
        else
          m[i + 2] = f(i + 2, m0, m1);
      }
    }
    for (int j = 0; j < 3; ++j) {
      if (!m[i + j]) v.push_back(i + j);
    }
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
