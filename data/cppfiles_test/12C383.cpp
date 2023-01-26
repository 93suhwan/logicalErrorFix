#include <bits/stdc++.h>
#pragma GCC optimize(2)
using namespace std;
const int maxn = 1e7 + 10;
const int maxm = 1e4 + 10;
int t, n, m, k;
inline int read() {
  int x = 0, k = 1;
  char ch = getchar();
  for (; !isdigit(ch); ch = getchar())
    if (ch == '-') k = -1;
  for (; isdigit(ch); ch = getchar()) x = x * 10 + ch - '0';
  return x * k;
}
int main() {
  t = read();
  while (t--) {
    n = read();
    m = read();
    k = read();
    int sum = n * m / 2;
    if (n % 2 == 1) {
      sum -= m / 2;
      k -= m / 2;
    }
    if (m % 2 == 1) sum -= n / 2;
    if (k < 0 || k % 2 == 1 || k > sum)
      printf("NO\n");
    else
      printf("YES\n");
  }
  return 0;
}
