#include <bits/stdc++.h>
using namespace std;
const long long N = 60;
long long timer, cc1, cc;
void boost() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
}
bool check(long long x, long long y) {
  string s, s1;
  s = "";
  s1 = "";
  long long z, l, r, l1, r1, c = 0, d = 0;
  l = 0;
  r = 0;
  l1 = 0;
  r1 = 0;
  z = x;
  while (z != 0) {
    if (z & 1)
      s += '1';
    else
      s += '0';
    z = z / 2;
  }
  z = y;
  while (z != 0) {
    if (z & 1)
      s1 += '1';
    else
      s1 += '0';
    z = z / 2;
  }
  while (1) {
    if (s.back() == '1') {
      s.pop_back();
      l++;
    } else
      break;
  }
  reverse(s.begin(), s.end());
  while (1) {
    if (s.back() == '1') {
      s.pop_back();
      r++;
    } else
      break;
  }
  while (1) {
    if (s1.back() == '1') {
      s1.pop_back();
      l1++;
    } else
      break;
  }
  reverse(s1.begin(), s1.end());
  while (1) {
    if (s1.back() == '1') {
      s1.pop_back();
      r1++;
    } else
      break;
  }
  if (s == s1) {
    d++;
  }
  reverse(s.begin(), s.end());
  if (s == s1) {
    d++;
  }
  if (r > l) swap(l, r);
  if (r1 > l1) swap(l1, r1);
  if (l1 >= l && r1 >= r) {
    c++;
  }
  if (c > 0 && d > 0)
    return true;
  else
    return false;
}
int main() {
  boost();
  long long i, t, q, l, r, ans, mid, c = 0, j, z, tc, n, k;
  long long h, m, u, mm, w, x, y, l1, r1, d = 0, mask, v, mx;
  long double f, f1;
  cin >> x >> y;
  if (x == y)
    cout << "YES" << '\n';
  else if (x > y) {
    while ((x % 2) == 0) {
      x = x / 2;
    }
    if (check(x, y))
      cout << "YES" << '\n';
    else
      cout << "NO" << '\n';
  } else {
    z = x;
    string s = "";
    while (z != 0) {
      if (z & 1) {
        s += '1';
      } else
        s += '0';
      z = z / 2;
    }
    reverse(s.begin(), s.end());
    if (s.back() == '0') {
      s += '1';
      reverse(s.begin(), s.end());
      c = 0;
      l = 1;
      d = 0;
      for (i = 0; i < ((long long)s.size()); i++) {
        r = s[i] - '0';
        c += (l * r);
        l *= 2;
      }
      x = c;
      if (check(x, y)) d++;
      reverse(s.begin(), s.end());
      s.pop_back();
    }
    while (s.back() == '0') {
      s.pop_back();
    }
    reverse(s.begin(), s.end());
    c = 0;
    l = 1;
    for (i = 0; i < ((long long)s.size()); i++) {
      r = s[i] - '0';
      c += (l * r);
      l *= 2;
    }
    x = c;
    if (check(x, y)) d++;
    if (d > 0)
      cout << "YES" << '\n';
    else
      cout << "NO" << '\n';
  }
  return 0;
}
