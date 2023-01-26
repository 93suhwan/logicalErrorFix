#include <bits/stdc++.h>
using namespace std;
inline long long read() {
  long long x = 0, f = 1;
  char ch = getchar();
  while (ch < '0' || ch > '9') {
    if (ch == '-') f = -1;
    ch = getchar();
  }
  while (ch >= '0' && ch <= '9') {
    x = x * 10 + ch - '0';
    ch = getchar();
  }
  return x * f;
}
long long T, n, a[3000], x, y;
bool flag;
int main() {
  T = read();
  while (T--) {
    n = read();
    flag = true;
    for (int i = 1; i <= n; i++) {
      a[i] = read();
      if (a[i] % 2 != i % 2) flag = false;
    }
    if (!flag) {
      cout << -1 << endl;
      continue;
    }
    cout << (n - 1) * 5 / 2 << endl;
    for (int i = n / 2; i >= 1; i--) {
      for (int j = 1; j <= n; j++) {
        if (a[j] == i * 2 + 1) {
          x = j;
          break;
        }
      }
      for (int j = 1; j <= n; j++) {
        if (a[j] == i * 2) {
          y = j;
          break;
        }
      }
      cout << x << " ";
      if (y < x) y = x - y + 1;
      cout << y - 1 << " ";
      cout << y + 1 << " ";
      cout << 3 << " ";
      cout << i * 2 + 1 << " ";
    }
    cout << endl;
  }
  return 0;
}
