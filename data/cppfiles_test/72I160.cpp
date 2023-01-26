#include <bits/stdc++.h>
#pragma GCC optimize(3)
#pragma GCC optimize("Ofast")
using namespace std;
const double pi = acos(-1.0);
const int inf = 0x3f3f3f3f;
const long long INF = 0x3f3f3f3f3f3f3f3fll;
int dir[4][2] = {{1, 0}, {0, -1}, {-1, 0}, {0, 1}};
long long read() {
  long long x = 0, f = 1;
  char c = getchar();
  while (c < '0' || c > '9') {
    if (c == '-') f = -1;
    c = getchar();
  }
  while (c >= '0' && c <= '9') x = x * 10 + c - '0', c = getchar();
  return x * f;
}
void wri(long long x) {
  if (x < 0) putchar('-'), x = -x;
  if (x > 9) wri(x / 10);
  putchar(x % 10 + '0');
}
void write(long long x) {
  wri(x);
  puts("");
}
long long ksc(long long a, long long b, long long mod) {
  return ((a * b -
           (long long)((long long)((long double)a / mod * b + 1e-3) * mod)) %
              mod +
          mod) %
         mod;
}
long long ksm1(long long a, long long n, long long mod) {
  long long t = 1;
  for (; n; n >>= 1, (a *= a) %= mod)
    if (n & 1) (t *= a) %= mod;
  return t;
}
long long ksm2(long long a, long long b, long long mod) {
  long long res = 1;
  while (b) {
    if (b & 1) res = ksc(res, a, mod);
    b >>= 1, a = ksc(a, a, mod);
  }
  return res % mod;
}
int is2pow(long long x) { return x > 0 ? (x & (x - 1)) == 0 : 0; }
long long myrand(long long l, long long r) {
  long long num = ((long long)rand() << 30) | ((long long)rand());
  return num % (r + 1 - l) + l;
}
const long long N = 15;
long long cnt[N];
string solve(long long n) {
  string str = "";
  while (n) {
    str += n % 10 + '0';
    n /= 10;
  }
  reverse(str.begin(), str.end());
  return str;
}
signed main() {
  long long t;
  cin >> t;
  while (t--) {
    long long n, k;
    cin >> n >> k;
    memset(cnt, 0, sizeof(cnt));
    long long geshu = 0;
    string tmp = solve(n);
    string res = "";
    long long mark = 0;
    char minn = '9';
    for (long long i = 0; i < tmp.size(); i++) {
      if (geshu < k) {
        if (cnt[tmp[i] - '0'] == 0) {
          cnt[tmp[i] - '0'] = i + 1;
          geshu++;
          res += tmp[i];
          minn = ((minn < tmp[i]) ? minn : tmp[i]);
        } else
          res += tmp[i], minn = ((minn < tmp[i]) ? minn : tmp[i]);
      } else if (geshu == k) {
        if (mark == 0 && cnt[tmp[i] - '0'] == 0) {
          for (long long j = 0; j <= 9; j++) {
            if (cnt[j] && j >= tmp[i] - '0') {
              res += j + '0';
              mark = 1;
              break;
            }
          }
          if (mark == 0) {
            mark = 1;
            long long maxn = 0;
            char ch = '0';
            for (long long j = 0; j <= 9; j++) {
              if (cnt[j] > maxn) {
                maxn = cnt[j];
                ch = j + '0';
              }
            }
            maxn--;
            if (minn == ch) minn++;
            res[maxn] = ch + 1;
            for (long long j = maxn + 1; j < i; j++) res[j] = minn;
            res += minn;
          }
        } else if (mark == 1)
          res += minn;
        else
          res += tmp[i];
      }
    }
    cout << res << endl;
  }
  return 0;
}
