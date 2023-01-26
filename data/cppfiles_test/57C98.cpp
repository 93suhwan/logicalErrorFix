#include <bits/stdc++.h>
using namespace std;
inline long long read() {
  long long x = 0, f = 1;
  char ch = getchar();
  while (!isdigit(ch)) {
    if (ch == '-') f = -1;
    ch = getchar();
  }
  while (isdigit(ch)) {
    x = (x << 1) + (x << 3) + (ch ^ 48);
    ch = getchar();
  }
  return x * f;
}
signed main() {
  long long T = read();
  while (T--) {
    long long s = read(), n = read(), k = read();
    if (s == k)
      puts("Yes");
    else if (k == 1 && s >= (k + 1) * n)
      puts("No");
    else if (n / k * k * 2 + n % k <= s)
      puts("No");
    else
      puts("Yes");
  }
  return 0;
}
