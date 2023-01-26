#include <bits/stdc++.h>
using namespace std;
clock_t startTime, endTime;
const long long INF_ll = 1e18;
const int INF_int = 0x3f3f3f3f;
void read(){};
template <typename _Tp, typename... _Tps>
void read(_Tp &x, _Tps &...Ar) {
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
const int maxn = 3e5 + 9;
struct node {
  int x, y, s;
} a[maxn];
bool cmp(node a, node b) { return a.x < b.x; }
const int mod = 998244353;
int sum[maxn];
int q[maxn];
int x[maxn];
int y[maxn];
int s[maxn];
int main() {
  int n;
  cin >> n;
  int maxx = 0;
  for (int i = 1; i <= n; i++) {
    read(x[i], y[i], s[i]);
    int pos = lower_bound(x + 1, x + 1 + i, y[i]) - x;
    q[i] = (x[i] - y[i] + sum[i - 1] - sum[pos - 1]) % mod;
    sum[i] = (sum[i - 1] + q[i]) % mod;
  }
  int ans = (x[n] + 1);
  for (int i = 1; i <= n; i++) {
    if (s[i]) ans = (ans + q[i] + mod) % mod;
  }
  printf("%d", (ans % mod + mod) % mod);
  return 0;
}
