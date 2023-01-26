#include <bits/stdc++.h>
using namespace std;
const int N = 1e6 + 10;
inline long long read() {
  long long X = 0;
  bool flag = 1;
  char ch = getchar();
  while (ch < '0' || ch > '9') {
    if (ch == '-') flag = 0;
    ch = getchar();
  }
  while (ch >= '0' && ch <= '9') {
    X = (X << 1) + (X << 3) + ch - '0';
    ch = getchar();
  }
  if (flag) return X;
  return ~(X - 1);
}
inline void write(long long x) {
  if (x < 0) x = ~x + 1, putchar('-');
  if (x > 9) write(x / 10);
  putchar(x % 10 + '0');
}
signed main() {
  long long t = read();
  while (t--) {
    long long n = read();
    if (n <= 6) {
      cout << 15 << endl;
    } else if (n > 6 && n <= 8) {
      cout << 20 << endl;
    } else if (n > 8 && n <= 10) {
      cout << 25 << endl;
    } else if (n > 10) {
      n -= 10;
      long long t = n % 6;
      long long now = ceil((n + 10) * 1.0 / 6);
      if (t == 1 || t == 2) {
        cout << (long long)15 * now << endl;
      } else if (t == 3 || t == 4) {
        cout << (long long)15 * now + 20 << endl;
      } else if (t == 5 || t == 0) {
        cout << (long long)15 * now + 25 << endl;
      }
    }
  }
  return 0;
}
