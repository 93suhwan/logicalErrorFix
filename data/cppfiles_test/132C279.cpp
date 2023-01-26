#include <bits/stdc++.h>
using namespace std;
inline long long read() {
  long long x = 0, ff = 1;
  char c = getchar();
  while (c < '0' || c > '9') {
    if (c == '-') ff = -1;
    c = getchar();
  }
  while (c >= '0' && c <= '9') {
    x = (x << 1) + (x << 3) + (c ^ '0');
    c = getchar();
  }
  return x * ff;
}
long long t, a[10];
signed main() {
  t = read();
  while (t--) {
    long long s = 0;
    for (long long i = 1; i <= 7; i++) a[i] = read(), s += a[i];
    s /= 4;
    cout << a[1] << " " << a[2] << " " << s - a[1] - a[2] << endl;
  }
  return 0;
}
