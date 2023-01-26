#include <bits/stdc++.h>
using namespace std;
long long n, m, T, cnt;
long long ans;
string s;
vector<long long> v;
long long f1[1000010], f2[1000010];
const long long M = 998244353;
inline long long read() {
  char ch = getchar();
  long long ret = 0;
  while (!isdigit(ch)) ch = getchar();
  while (isdigit(ch)) ret = (ret << 3) + (ret << 1) + (ch ^ 48), ch = getchar();
  return ret;
}
signed main() {
  T = read();
  while (T--) {
    n = read();
    for (long long i = 0; i <= n; i++) f1[i] = f2[i] = 0;
    f1[0] = 1;
    for (long long i = 1; i <= n; i++) {
      long long x = read();
      f1[x + 1] = (f1[x + 1] + f1[x] + f1[x + 1]) % M;
      if (x > 0) {
        f2[x - 1] = (f2[x - 1] + f2[x - 1] + f1[x - 1]) % M;
      }
      f2[x + 1] = 2 * f2[x + 1] % M;
    }
    ans = 0;
    for (long long i = 0; i <= n; i++) {
      ans = (ans + f1[i] + f2[i]) % M;
    }
    printf("%lld\n", (ans - 1 + M) % M);
  }
  return 0;
}
