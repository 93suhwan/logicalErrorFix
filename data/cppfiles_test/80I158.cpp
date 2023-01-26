#include <bits/stdc++.h>
using namespace std;
const long double pai = 3.1415926536;
const int inf = 0x3f3f3f3f;
const long long INF = 0x3f3f3f3f3f3f3f3f;
const unsigned long long bas = 2333;
const int MAXN = 2e5 + 10;
const int N = 1e5 + 10;
const long long mod = 998244353;
int dx[] = {-1, 0, 1, -1, 1, -1, 0, 1};
int dy[] = {-1, -1, -1, 0, 0, 1, 1, 1};
template <typename T>
void rd(T &x) {
  char ch = getchar();
  x = 0;
  int f = 1;
  while (ch < '0' || ch > '9') {
    if (ch == '-') f = -1;
    ch = getchar();
  }
  while (ch >= '0' && ch <= '9') {
    x = x * 10 + ch - '0';
    ch = getchar();
  }
  x *= f;
}
template <typename T>
inline void wt(T a) {
  if (a < 0) putchar('-'), a = -a;
  if (a >= 10) wt(a / 10);
  putchar(a % 10 + 48);
}
long long qpow(long long a, long long p) {
  long long ans = 1;
  while (p) {
    if (p & 1) ans = ans * a % mod;
    a = a * a % mod;
    p >>= 1;
  }
  return ans;
}
char s[MAXN];
int main() {
  ios::sync_with_stdio(false);
  int T = 1;
  cin >> T;
  int v[12] = {0, 1, 0, 0, 1, 0, 1, 0, 1, 1};
  while (T--) {
    int n;
    cin >> n >> s + 1;
    int k = n / 2, p = 0;
    for (int i = n - k + 1; i <= n; ++i) {
      if (s[i] == '0') {
        p = i;
        break;
      }
    }
    if (p) {
      cout << 1 << ' ' << p << ' ' << 1 << ' ' << p - 1 << '\n';
    } else if (s[n - k - 1] == '0') {
      cout << n - k - 1 << ' ' << n << ' ' << n - k << ' ' << n << '\n';
    } else {
      cout << n - k - 1 << ' ' << n - 1 << ' ' << n - k << ' ' << n << '\n';
    }
  }
}
