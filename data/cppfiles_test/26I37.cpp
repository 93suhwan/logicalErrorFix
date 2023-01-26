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
long long ans[100010];
int main() {
  t = read();
  long long x = 1;
  for (int i = 3; i <= 200010; ++i) {
    x = (x * i) % mod;
    if (i % 2 == 0) ans[i / 2] = x;
  }
  while (t--) {
    long long n = read();
    printf("%d\n", ans[n]);
  }
  return 0;
}
