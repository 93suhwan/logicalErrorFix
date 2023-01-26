#include <bits/stdc++.h>
using namespace std;
const long long maxn = 255, maxv = 3e7, mod = 1e9 + 7;
inline long long read() {
  char c = getchar();
  long long ans = 0, f = 0;
  for (; c < '0' || c > '9'; c = getchar()) f |= (c == '-');
  for (; c >= '0' && c <= '9'; c = getchar()) ((ans *= 10) += c - '0');
  return f ? -ans : ans;
}
void chkmax(long long &x, long long y) { x = x > y ? x : y; }
void work() {
  long long n = read(), tot = 0;
  for (long long(i) = (1); (i) <= (n); (i)++) {
    long long a = read();
    if (a > i + tot) tot = a - i;
  }
  printf("%lld\n", tot);
}
int main() {
  for (long long t = read(); t; t--) work();
  return 0;
}
