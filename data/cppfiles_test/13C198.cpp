#include <bits/stdc++.h>
const long long mod = 2147483647LL;
long long read() {
  long long r = 0;
  char c = getchar();
  while (c < '0' || c > '9') c = getchar();
  while (c >= '0' && c <= '9') {
    r = 10LL * r + (long long)c - '0';
    c = getchar();
  }
  return r;
}
long long fast(long long a, long long b) {
  long long r = 1LL;
  while (b) {
    if (b & 1) r = (r * a) % mod;
    b >>= 1;
    a = (a * a) % mod;
  }
  return r;
}
std::string str;
int a, b, c, T;
signed main() {
  T = read();
  while (T--) {
    std::cin >> str;
    a = 0;
    b = 0;
    c = 0;
    for (int i = 0; i < str.size(); ++i) {
      if (str[i] == 'A') ++a;
      if (str[i] == 'B') ++b;
      if (str[i] == 'C') ++c;
    }
    if (b == a + c)
      puts("YES");
    else
      puts("NO");
  }
  return 0;
}
