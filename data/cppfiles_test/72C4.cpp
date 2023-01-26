#include <bits/stdc++.h>
using namespace std;
inline int get() {
  int a;
  cin >> a;
  if (a == -1)
    exit(0);
  else
    return a;
}
inline void print(int a, int b) {
  cout << "? " << a << " " << b << endl;
  cout.flush();
}
inline void print(int a, int b, int c, int d) {
  cout << "! " << a << " " << b << " " << c << " " << d << endl;
  cout.flush();
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int a, b, c, d, ym, xm;
  print(1, 1);
  a = get();
  print(1, 1e9);
  c = get();
  ym = 1e9 + 1 + a - c;
  print(1e9, 1);
  b = get();
  xm = 1e9 + 1 + a - b;
  int s, t, m, n;
  print(1, ym >> 1);
  s = get() + 1;
  print(xm >> 1, 1);
  t = get() + 1;
  print(1e9, ym >> 1);
  m = 1e9 - get();
  print(xm >> 1, 1e9);
  n = 1e9 - get();
  print(s, t, m, n);
  return 0;
}
