#include <bits/stdc++.h>
using namespace std;
inline long long read() {
  long long a = 0, po = 1;
  char ch = getchar();
  while (!isdigit(ch) && ch != '-') ch = getchar();
  if (ch == '-') po = -1, ch = getchar();
  while (isdigit(ch)) a = (a << 1) + (a << 3) + ch - '0', ch = getchar();
  return a * po;
}
long long a[10];
long long b[] = {1,      10,      100,      1000,      10000,
                 100000, 1000000, 10000000, 100000000, 1000000000};
signed main() {
  long long t = read();
  while (t--) {
    long long s = read();
    long long n = read();
    long long c = s;
    long long temp = 0;
    memset(a, 0, sizeof(a));
    if (n == 1)
      cout << s << "\n";
    else {
      for (long long i = 9; i >= 0; i--) {
        a[i] = c / b[i];
        c = c - a[i] * b[i];
      }
      for (long long i = 9; i >= 0; i--) {
        if (a[i] != 0) {
          temp = i;
          break;
        }
      }
      for (long long i = temp; i >= 0; i--) {
        if (a[i] >= n) {
          for (long long j = 1; j < n; j++) {
            cout << b[i] << " ";
          }
          cout << (s - (n - 1) * b[i]);
          if (t) cout << " ";
          cout << "\n";
          break;
        } else {
          if ((s - a[i] * b[i]) >= (n - a[i])) {
            for (long long j = 1; j <= a[i]; j++) {
              cout << b[i] << " ";
            }
            s -= a[i] * b[i];
            n -= a[i];
          } else {
            for (long long j = 1; s - b[i] >= n - 1; j++) {
              cout << b[i] << " ";
              n--;
              a[i]--;
              s -= b[i];
            }
            a[i - 1] += a[i] * 10;
          }
        }
      }
    }
  }
  return 0;
}
