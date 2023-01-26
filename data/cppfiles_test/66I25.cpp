#include <bits/stdc++.h>
using namespace std;
inline long long F(long long n, long long x) {
  if (x == 1) return 0;
  if (x == n - 1) return 1;
  return F(n - 1, n - x - 1);
}
inline void Uniform(long long &n, long long &a, long long &b, char &sa,
                    char &sb) {
  if (a == 0 && sa == 'L') sa = 'R';
  if (b == 0 && sb == 'L') sb = 'R';
  if (a == n - 1 && sa == 'R') sa = 'L';
  if (b == n - 1 && sb == 'R') sb = 'L';
}
inline long long Solve(long long n, long long a, long long b, char sa,
                       char sb) {
  Uniform(n, a, b, sa, sb);
  if (a == b) {
    if (sa == sb) {
      if (a == n - 1)
        return 0;
      else if (a == 0)
        return n - 1;
      else
        return (sa == 'L') ? n - 1 : 0;
    } else {
      return F(n - 1, a) ? n - 1 : 0;
    }
  }
  if (sa == sb) {
    if (sa == 'L') {
      a = n - 1 - a, b = n - 1 - b, sa = sb = 'R';
      return n - 1 - Solve(n, a, b, sa, sb);
    }
    if (a > b) {
      ++a;
      swap(a, b);
      return Solve(n, a, b, sa, sb);
    }
    long long stp = n - 1 - b;
    a += stp;
    b += stp;
  }
  Uniform(n, a, b, sa, sb);
  if (a > b) return Solve(n, b, a + 1, sb, sa);
  if (sa == 'L') {
    long long m = (a + b) >> 1;
    if ((b - a) & 1) {
      return F(n, n - 1 - m) ? 0 : n - 1;
    } else {
      return F(n, m) ? n - 1 : 0;
    }
  } else {
    long long m = (a + b) >> 1;
    if ((b - a) & 1) {
      return F(n - 1, (n - 1) - 1 - m) ? 0 : n - 1;
    } else {
      return F(n - 1, m) ? n - 1 : 0;
    }
  }
}
long long Case;
long long n, a, b;
char sa[10], sb[10];
signed main() {
  scanf("%lld", &Case);
  while (Case--) {
    scanf("%lld%lld%lld%s%s", &n, &a, &b, sa, sb);
    printf("%lld\n", Solve(n, a, b, sa[0], sb[0]));
  }
  return 0;
}
