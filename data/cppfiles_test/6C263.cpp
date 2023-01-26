#include <bits/stdc++.h>
using namespace std;
const long long MAXN = 1e6 + 10;
const long long INF2 = 1e9;
const long long MOD = 998244353;
const long double eps = 1e-9;
const long double inf = 1e20;
const long double pi = acos(-1);
inline long long read() {
  long long s = 0, w = 1;
  char ch = getchar();
  while (ch < '0' || ch > '9') {
    if (ch == '-') w = -1;
    ch = getchar();
  }
  while (ch >= '0' && ch <= '9') s = s * 10 + ch - '0', ch = getchar();
  return s * w;
}
void write(long long x) {
  if (x < 0) putchar('-'), x = -x;
  if (x > 9) write(x / 10);
  putchar(x % 10 + '0');
}
long long num[MAXN];
long long temp[MAXN];
void solve() {
  long long n, m;
  cin >> n >> m;
  for (long long i = 0; i < m; i++) {
    long long a, b;
    a = read();
    b = read();
    if (a > b)
      num[b]++;
    else
      num[a]++;
  }
  long long q;
  cin >> q;
  long long cnt = 0;
  for (long long i = 1; i <= n; i++) {
    temp[i] = num[i];
    if (temp[i] == 0) cnt++;
  }
  for (long long i = 0; i < q; i++) {
    long long x;
    x = read();
    if (x == 1) {
      long long a, b;
      a = read();
      b = read();
      if (a > b) {
        if (temp[b] == 0) cnt--;
        temp[b]++;
      } else {
        if (temp[a] == 0) cnt--;
        temp[a]++;
      }
    } else if (x == 2) {
      long long a, b;
      a = read();
      b = read();
      if (a > b) {
        temp[b]--;
        if (temp[b] == 0) cnt++;
      } else {
        temp[a]--;
        if (temp[a] == 0) cnt++;
      }
    } else if (x == 3) {
      cout << cnt << '\n';
    }
  }
}
signed main() {
  long long t = 1;
  while (t--) {
    solve();
  }
  return 0;
}
