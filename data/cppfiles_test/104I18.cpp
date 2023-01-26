#include <bits/stdc++.h>
template <class T>
inline T read() {
  T r = 0, f = 0;
  char c;
  while (!isdigit(c = getchar())) f |= (c == '-');
  while (isdigit(c)) r = (r << 1) + (r << 3) + (c ^ 48), c = getchar();
  return f ? -r : r;
}
template <class T>
inline T min(T a, T b) {
  return a < b ? a : b;
}
template <class T>
inline T max(T a, T b) {
  return a > b ? a : b;
}
template <class T>
inline void swap(T &a, T &b) {
  T c = a;
  a = b;
  b = c;
}
inline long long gcd(long long a, long long b) { return b ? gcd(b, a % b) : a; }
inline long long qpow(long long a, int b) {
  long long ans = 1;
  for (; b; b >>= 1) {
    if (b & 1) (ans *= a) %= 1000000007;
    (a *= a) %= 1000000007;
  }
  return ans;
}
struct Z {
  int x;
  inline int val() const { return x; }
  inline int inv() const { return qpow(x, 1000000007 - 2); }
  Z(int x = 0) : x(x) {}
  Z operator-() const {
    return Z((1000000007 - x >= 1000000007 ? 1000000007 - x - 1000000007
                                           : 1000000007 - x));
  }
  Z &operator+=(const Z &z) {
    x = (x + z.x >= 1000000007 ? x + z.x - 1000000007 : x + z.x);
    return *this;
  }
  Z &operator-=(const Z &z) {
    x = (x - z.x < 0 ? x - z.x + 1000000007 : x - z.x);
    return *this;
  }
  Z &operator*=(const Z &z) {
    x = 1ll * x * z.x % 1000000007;
    return *this;
  }
  Z &operator/=(const Z &z) {
    x = 1ll * x * z.inv() % 1000000007;
    return *this;
  }
  Z operator+(const Z &z) const {
    return Z((x + z.x >= 1000000007 ? x + z.x - 1000000007 : x + z.x));
  }
  Z operator-(const Z &z) const {
    return Z((x - z.x < 0 ? x - z.x + 1000000007 : x - z.x));
  }
  Z operator*(const Z &z) const { return Z(1ll * x * z.x % 1000000007); }
  Z operator/(const Z &z) const { return Z(1ll * x * z.inv() % 1000000007); }
};
int n, a[202202];
int s_ans, ans[202202];
void solve(int add, int n) {
  for (int i = 1; i <= n - 2; i += 2) ans[++s_ans] = i;
  for (int i = n - 4; i > 0; i -= 2) ans[++s_ans] = i;
}
inline void out() {
  printf("YES\n%d\n", s_ans);
  for (int i = 1; i <= s_ans; i++) printf("%d ", ans[i]);
  puts("");
}
inline void work() {
  n = read<int>();
  int X = 0;
  bool ok = 0;
  for (int i = 1; i <= n; i++) X ^= a[i] = read<int>();
  if (X) return (void)puts("NO");
  s_ans = 0;
  if (n & 1) {
    solve(0, n);
    return out();
  }
  for (int i = 1, x = 0; i <= n; i++) {
    x ^= a[i];
    if ((i & 1) && !x) {
      solve(0, i);
      solve(i, n - i);
      return out();
    }
  }
  puts("NO");
}
int main() {
  int t = read<int>();
  while (t--) work();
  return 0;
}
