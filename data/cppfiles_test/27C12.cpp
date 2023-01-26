#include <bits/stdc++.h>
using namespace std;
const long double pai = 3.1415926536;
const int inf = 0x3f3f3f3f;
const long long INF = 0x3f3f3f3f3f3f3f3f;
const unsigned long long bas = 2333;
const int MAXN = 3e5 + 10;
const int N = 1e5 + 10;
const long long mod = 998244353;
const long long MOD = 1e9 + 7;
int dx[] = {-1, 0, 1, -1, 1, -1, 0, 1};
int dy[] = {-1, -1, -1, 0, 0, 1, 1, 1};
template <typename T>
void rd(T& x) {
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
int main() {
  ios::sync_with_stdio(false);
  int T = 1;
  cin >> T;
  while (T--) {
    long long n, m, k;
    cin >> n >> m >> k;
    k -= 2;
    if (m < n - 1 || m > n * (n - 1) / 2 || k < 0)
      cout << "NO\n";
    else if (!k)
      cout << ((n == 1) ? "YES" : "NO") << '\n';
    else if (k == 1) {
      if (m == n * (n - 1) / 2)
        cout << "YES\n";
      else
        cout << "NO\n";
    } else
      cout << "YES\n";
  }
}
