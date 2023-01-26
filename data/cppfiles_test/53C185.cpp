#include <bits/stdc++.h>
using namespace std;
const long long N = 1e5 + 5;
const long long Inf = 1e18;
long long n, m, a[N], b[N];
inline long long read() {
  long long x = 0;
  char ch = getchar();
  bool f = 0;
  while (ch > '9' || ch < '0') {
    if (ch == '-') f = 1;
    ch = getchar();
  }
  while (ch >= '0' && ch <= '9') {
    x = (x << 1) + (x << 3) + ch - '0';
    ch = getchar();
  }
  return f ? -x : x;
}
int main() {
  long long t = read();
  a[0] = b[0] = -1;
  while (t--) {
    n = read(), m = read();
    for (long long i = 1; i <= n; ++i) a[i] = b[i] = read();
    sort(b + 1, b + 1 + n);
    map<long long, long long> h;
    for (long long i = 1; i <= n; ++i) h[b[i]] = i;
    for (long long i = 1; i <= n; ++i) a[i] = h[a[i]];
    long long cnt = 0;
    for (long long i = 1; i <= n; ++i) {
      if (a[i] == a[i - 1] + 1) continue;
      ++cnt;
    }
    if (m >= cnt) {
      puts("Yes");
    } else {
      puts("No");
    }
  }
  return 0;
}
