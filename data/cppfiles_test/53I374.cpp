#include <bits/stdc++.h>
using namespace std;
const long long N = 1e5 + 5;
const long long Inf = 1e18;
long long n, m, a[N];
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
  while (t--) {
    n = read(), m = read();
    for (long long i = 1; i <= n; ++i) a[i] = read();
    stack<long long> s;
    long long cnt = 0;
    for (long long i = 1; i <= n; ++i) {
      if (s.empty() || s.top() < a[i]) {
        s.push(a[i]);
        continue;
      }
      ++cnt;
      while (s.size() && s.top() > a[i]) s.pop();
      s.push(a[i]);
    }
    if (cnt + 1 == m)
      puts("Yes");
    else
      puts("No");
  }
  return 0;
}
