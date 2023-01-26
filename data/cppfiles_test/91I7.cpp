#include <bits/stdc++.h>
using namespace std;
inline long long read() {
  long long x = 0, f = 1;
  char ch = getchar();
  while (ch < '0' || ch > '9') {
    if (ch == '-') f = -1;
    ch = getchar();
  }
  while (ch >= '0' && ch <= '9') {
    x = x * 10 + ch - '0';
    ch = getchar();
  }
  return x * f;
}
const long long maxn = 100000 + 10;
const long long mod = 998244353;
long long a[maxn];
long long s[maxn];
int main() {
  long long T = read();
  while (T--) {
    long long n = read();
    for (long long i = 1; i <= n; i++) a[i] = read(), s[i] = s[i - 1] + a[i];
    long long ans = 0;
    for (long long i = n; i >= 1; i--) {
      long long f = a[i], sum = 0;
      for (long long j = i - 1; j >= 1; j--) {
        if (f == 1) {
          ans += s[j] - j + sum * j;
          break;
        }
        sum += (a[j] + f - 1) / f - 1;
        ans += sum;
        f = a[j] / ((a[j] + f - 1) / f);
      }
      ans %= mod;
    }
    cout << ans << endl;
  }
  return 0;
}
