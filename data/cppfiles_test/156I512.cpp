#include <bits/stdc++.h>
char ibuf[1 << 15], *p1, *p2;
struct FastIO {
  inline int rint() {
    register char c, f = 0;
    while ((c = (p1 == p2 && (p2 = (p1 = ibuf) + fread(ibuf, 1, 1 << 15, stdin),
                              p1 == p2)
                     ? EOF
                     : *p1++)) < 48 ||
           c > 57)
      f |= c == '-';
    register int unsigned a = c & 15;
    while ((c = (p1 == p2 && (p2 = (p1 = ibuf) + fread(ibuf, 1, 1 << 15, stdin),
                              p1 == p2)
                     ? EOF
                     : *p1++)) >= 48 &&
           c <= 57)
      a = a * 10 + (c & 15);
    return f ? ~a + 1 : a;
  }
  inline long long rll() {
    register char c, f = 0;
    while ((c = (p1 == p2 && (p2 = (p1 = ibuf) + fread(ibuf, 1, 1 << 15, stdin),
                              p1 == p2)
                     ? EOF
                     : *p1++)) < 48 ||
           c > 57)
      f |= c == '-';
    register unsigned long long a = c & 15;
    while ((c = (p1 == p2 && (p2 = (p1 = ibuf) + fread(ibuf, 1, 1 << 15, stdin),
                              p1 == p2)
                     ? EOF
                     : *p1++)) >= 48 &&
           c <= 57)
      a = a * 10 + (c & 15);
    return f ? ~a + 1 : a;
  }
  inline operator int() { return rint(); }
  inline char rchar() {
    register char c;
    while (!isgraph(
        c = (p1 == p2 && (p2 = (p1 = ibuf) + fread(ibuf, 1, 1 << 15, stdin),
                          p1 == p2)
                 ? EOF
                 : *p1++)))
      ;
    return c;
  }
} g90;
std::mt19937 rng(
    std::chrono::high_resolution_clock::now().time_since_epoch().count());
inline int rnd(const int& a, const int& b) {
  return std::uniform_int_distribution<int>(a, b)(rng);
}
inline long double rnd(const long double& a, const long double& b) {
  return std::uniform_real_distribution<long double>(a, b)(rng);
}
namespace MY_STD {
template <typename T>
inline T abs(const T& a) {
  return a < 0 ? -a : a;
}
}  // namespace MY_STD
const int N = 233333;
int a[N];
long long s[N];
signed main() {
  for (int T = g90; T--;) {
    int n = g90;
    long long k = g90.rll();
    for (int i = 1; i <= n; ++i) {
      a[i] = g90;
    }
    std::sort(a + 1, a + n + 1);
    for (int i = 1; i <= n; ++i) s[i] = s[i - 1] + a[i];
    if (s[n] <= k) {
      puts("0");
      continue;
    }
    long long ans = 1e18;
    for (int i = 1; i <= n; ++i) {
      long long l = n - i, r = 2e15, mid;
      for (; mid = (l + r) / 2, l < r;) {
        long long cnt = mid - (n - i);
        long long tmp = a[1] - cnt;
        if ((n - i + 1) * tmp + (s[i] - a[1]) <= k)
          r = mid;
        else
          l = mid + 1;
      }
      ans = std::min(ans, mid);
    }
    printf("%lld\n", ans);
  }
}
