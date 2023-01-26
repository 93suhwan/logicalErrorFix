#include <bits/stdc++.h>
using namespace std;
const long long maxn = 1e5 + 5;
const long long INF = 0x3f3f3f3f;
const long long mod = 1e9 + 7;
void init() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
}
inline long long read() {
  long long x = 0, f = 1;
  char ch = getchar();
  while (ch < '0' || ch > '9') {
    if (ch == '-') f = -1;
    ch = getchar();
  }
  while (ch >= '0' && ch <= '9') {
    x = (x << 1) + (x << 3) + (ch ^ 48);
    ch = getchar();
  }
  return x * f;
}
void write(long long x) {
  if (x < 0) putchar('-'), x = -x;
  if (x > 9) write(x / 10);
  putchar(x % 10 + '0');
  return;
}
signed main() {
  init();
  long long t;
  cin >> t;
  long long a, b;
  while (t--) {
    cin >> a >> b;
    if (b & 1) {
      cout << (a > b / 2 ? b % a : b / 2) << '\n';
    } else {
      cout << (a > b / 2 ? b % a : b / 2 - 1) << '\n';
    }
  }
}
