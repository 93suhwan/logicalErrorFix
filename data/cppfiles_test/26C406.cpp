#include <bits/stdc++.h>
using namespace std;
int read() {
  int res = 0, p = 1;
  char ch = getchar();
  while (!isdigit(ch)) {
    if (ch == '-') p = -1;
    ch = getchar();
  }
  while (isdigit(ch)) res = res * 10 + ch - '0', ch = getchar();
  return res * p;
}
const int mod = 1e9 + 7;
int t;
int main() {
  t = read();
  while (t--) {
    long long n = read() * 2;
    long long x = 1;
    for (int i = 3; i <= n; ++i) {
      x = (x * i) % mod;
    }
    printf("%d\n", x);
  }
  return 0;
}
