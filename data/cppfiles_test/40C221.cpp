#include <bits/stdc++.h>
using namespace std;
inline int read() {
  int ans = 0;
  char last = ' ', ch = getchar();
  while (ch<'0' | ch> '9') last = ch, ch = getchar();
  while (ch >= '0' && ch <= '9') ans = ans * 10 + ch - '0', ch = getchar();
  if (last == '-') ans = -ans;
  return ans;
}
int buf[105];
inline void write(int i) {
  int p = 0;
  if (i == 0)
    p++;
  else
    while (i) {
      buf[p++] = i % 10;
      i /= 10;
    }
  for (int j = p - 1; j >= 0; j--) putchar('0' + buf[j]);
}
const int inf = 0x3f3f3f3f;
const double PI = acos(-1);
const int mod = 998244353;
int qmi(int m, int k, int p) {
  int res = 1 % p, t = m;
  while (k) {
    if (k & 1) res = (long long)res * t % p;
    t = (long long)t * t % p;
    k >>= 1;
  }
  return res;
}
int gcd(int a, int b) { return b ? gcd(b, a % b) : a; }
const int N = 101010;
long long a[N];
long long b[N];
long long x, ans1, ans2;
int main() {
  int t;
  scanf("%d", &t);
  int case1 = 1;
  while (t--) {
    int n;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
      scanf("%lld", &x);
      a[i] = a[i - 1] + x;
    }
    for (int i = 1; i <= n; i++) {
      scanf("%lld", &x);
      b[i] = b[i - 1] + x;
    }
    long long ans = LLONG_MAX;
    for (int i = 1; i <= n; i++) {
      ans1 = a[n] - a[i];
      ans2 = b[i - 1];
      ans = min(ans, max(ans1, ans2));
    }
    printf("%lld\n", ans);
  }
  return 0;
}
