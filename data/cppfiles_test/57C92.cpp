#include <bits/stdc++.h>
using namespace std;
long long read() {
  long long res = 0;
  long long f = 1;
  char ch = getchar();
  while (ch < '0' || ch > '9') {
    if (ch == '-') f = -1;
    ch = getchar();
  }
  while (ch >= '0' && ch <= '9') {
    res = res * 10 + ch - '0';
    ch = getchar();
  }
  return res * f;
}
long long s, n, k;
long long t;
signed main() {
  t = read();
  while (t--) {
    s = read(), n = read(), k = read();
    if (s < k) {
      printf("No\n");
      continue;
    }
    if (s == k) {
      printf("Yes\n");
      continue;
    }
    long long k2 = k * 2;
    long long tmp = min(s % k2, k - 1);
    if (s / k2 * k + tmp < n)
      printf("Yes\n");
    else
      printf("No\n");
  }
  return 0;
}
