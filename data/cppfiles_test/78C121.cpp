#include <bits/stdc++.h>
using namespace std;
template <typename T>
void read(T &x) {
  x = 0;
  int f = 1;
  char c = getchar();
  for (; !isdigit(c); c = getchar())
    if (c == '-') f = -1;
  for (; isdigit(c); c = getchar()) x = x * 10 + c - '0';
  x = x * f;
}
int T, l, r, d[200020];
int a, b, mid;
signed main() {
  read(T);
  while (T) {
    T--;
    read(l), read(r);
    if (l == r) {
      cout << 0 << endl;
      continue;
    }
    if (l == 1 and r == 2) {
      cout << 0 << endl;
      continue;
    }
    if (l * 2 >= r) {
      if (r != l * 2)
        cout << r - l << endl;
      else
        cout << l - 1 << endl;
    } else {
      if (r % 2 == 0) r--;
      cout << r % ((r + 1) / 2) << endl;
    }
  }
  return 0;
}
