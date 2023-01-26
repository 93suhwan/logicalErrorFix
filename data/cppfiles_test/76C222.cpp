#include <bits/stdc++.h>
using namespace std;
clock_t startTime, endTime;
const long long INF_ll = 1e18;
const int INF_int = 0x3f3f3f3f;
void read(){};
template <typename _Tp, typename... _Tps>
void read(_Tp& x, _Tps&... Ar) {
  x = 0;
  char c = getchar();
  bool flag = 0;
  while (c < '0' || c > '9') flag |= (c == '-'), c = getchar();
  while (c >= '0' && c <= '9')
    x = (x << 3) + (x << 1) + (c ^ 48), c = getchar();
  if (flag) x = -x;
  read(Ar...);
}
template <typename T>
inline void write(T x) {
  if (x < 0) {
    x = ~(x - 1);
    putchar('-');
  }
  if (x > 9) write(x / 10);
  putchar(x % 10 + '0');
}
void rd_test() {}
void Time_test() {}
const int maxn = 5e6 + 9;
long long a[maxn];
long long f[maxn];
int n;
long long mod;
long long lowbits(long long x) { return x & (-x); }
void update(int pos, long long val) {
  for (int i = pos; i < maxn; i += lowbits(i)) {
    a[i] = (a[i] + val) % mod;
  }
}
long long query(int pos) {
  long long val = 0;
  for (int i = pos; i; i -= lowbits(i)) {
    val = (val + a[i]) % mod;
  }
  return val;
}
long long sum[maxn];
int main() {
  cin >> n >> mod;
  f[n] = 1ll;
  sum[n] = 1ll;
  for (int i = n - 1; i >= 1; i--) {
    f[i] = sum[i + 1];
    for (int j = 2; j * i <= n; j++) {
      long long l = i * j;
      long long r = min(1ll * j * i + j, 1ll * n + 1);
      f[i] = (f[i] + sum[l] - sum[r]) % mod;
    }
    sum[i] = (sum[i + 1] + f[i]) % mod;
  }
  printf("%lld\n", f[1] % mod);
  return 0;
}
