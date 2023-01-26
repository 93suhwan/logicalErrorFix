#include <bits/stdc++.h>
using namespace std;
const long long INF = 0x7f7f7f7f;
const long long P = 1e9 + 9;
const long long maxn = 100;
const double eps = 1e-9;
const long long mod = 1e9 + 7;
double pi = acos(-1);
const long long N = 2e6 + 5, M = 1e6 + 4;
template <class T = long long>
T read() {
  T res = 0;
  T fg = 1;
  char ch = getchar();
  while (!isdigit(ch)) {
    if (ch == '-') fg = -1;
    ch = getchar();
  }
  while (isdigit(ch)) res = (res << 1) + (res << 3) + (ch ^ 48), ch = getchar();
  return res * fg;
}
long long flag[maxn], pri[maxn], cont = 0;
void oushai() {
  long long i, j;
  flag[1] = 1;
  for (i = 2; i <= maxn; i++) {
    if (!flag[i]) {
      pri[++cont] = i;
    }
    for (j = 1; j <= cont && pri[j] * i <= maxn; j++) {
      flag[i * pri[j]] = 1;
      if (i % pri[j] == 0) {
        break;
      }
    }
  }
}
long long p[maxn], c[maxn];
long long qpow(long long bsc, long long second) {
  long long ret = 1;
  while (second) {
    if (second & 1) ret = ret * bsc % mod;
    bsc = bsc * bsc % mod;
    second >>= 1;
  }
  return ret;
}
long long fac[maxn + 10], inv[maxn + 10];
void init() {
  fac[0] = 1;
  for (long long i = 1; i <= maxn; i++)
    fac[i] = (long long)fac[i - 1] * i % mod;
  inv[maxn] = qpow(fac[maxn], mod - 2);
  for (long long i = maxn - 1; i >= 0; i--)
    inv[i] = (long long)inv[i + 1] * (i + 1) % mod;
}
long long C(long long n, long long m) {
  if (m > n) return 0;
  return (long long)fac[n] * inv[m] % mod * inv[n - m] % mod;
}
long long a[maxn], b[maxn];
signed main() {
  ios::sync_with_stdio(false), cin.tie(0);
  cout.tie(0);
  long long t;
  t = read();
  while (t--) {
    long long n;
    n = read();
    string s;
    cin >> s;
    long long cnt = 0;
    for (long long i = 0; i < n; i++) {
      if (s[i] == '?') {
        cnt++;
      }
      if (s[i] == 'B') {
        if (cnt) {
          bool flag = true;
          for (long long j = i - 1; j >= i - cnt; j--) {
            if (flag)
              s[j] = 'R', flag = !flag;
            else
              s[j] = 'B', flag = !flag;
          }
          cnt = 0;
        }
        if (s[i + 1] == '?' && i + 1 < n) s[i + 1] = 'R';
        if (s[i - 1] == '?' && i - 1 >= 0) s[i - 1] = 'R';
      } else if (s[i] == 'R') {
        if (cnt) {
          bool flag = true;
          for (long long j = i - 1; j >= i - cnt; j--) {
            if (flag)
              s[j] = 'B', flag = !flag;
            else
              s[j] = 'R', flag = !flag;
          }
          cnt = 0;
        }
        if (s[i + 1] == '?' && i + 1 < n) s[i + 1] = 'B';
        if (s[i - 1] == '?' && i - 1 >= 0) s[i - 1] = 'B';
      }
    }
    if (cnt == n) {
      bool flag = true;
      for (long long i = 0; i < n; i++) {
        if (flag)
          s[i] = 'B';
        else
          s[i] = 'R';
        flag != flag;
      }
    }
    cout << s << endl;
  }
  return 0;
}
