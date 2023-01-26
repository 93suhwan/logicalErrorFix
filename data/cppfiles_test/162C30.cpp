#include <bits/stdc++.h>
using i64 = long long;
using u64 = unsigned long long;
using u16 = unsigned short;
using i16 = short;
using u32 = unsigned int;
using pii = std::pair<int, int>;
using f64 = double;
using f80 = long double;
template <class T>
using ve = std::vector<T>;
template <class T>
using fun = std::function<T>;
template <class T1, class T2>
using pr = std::pair<T1, T2>;
template <class T>
using pq = std::priority_queue<T>;
template <class T>
using lpq = std::priority_queue<T, std::vector<T>, std::greater<T>>;
template <class T>
using gpq = std::priority_queue<T, std::vector<T>, std::less<T>>;
std::mt19937_64 seed(
    std::chrono::steady_clock::now().time_since_epoch().count());
u32 def_cnt = 0;
template <class T>
void memset(int val, T& fir) {
  memset(fir, val, sizeof fir);
}
template <class T, class... args>
void memset(int val, T& fir, args&... arg) {
  memset(fir, val, sizeof fir), memset(val, arg...);
}
template <class T>
inline T read() {
  T x = 0;
  int f = 1;
  char ch = getchar();
  for (; !isdigit(ch); ch = getchar())
    if (ch == '-') f = -1;
  for (; isdigit(ch); ch = getchar()) x = x * 10 + ch - 48;
  return x * f;
}
template <class T>
inline void read(T& x) {
  x = read<T>();
}
template <class T, class... Args>
inline void read(T& fir, Args&... args) {
  read(fir), read(args...);
}
template <class T>
inline void write(T x, char ch = '\n') {
  static int stk[32];
  if (x < 0) putchar('-'), x = -x;
  int top = 0;
  do stk[++top] = x % 10, x /= 10;
  while (x);
  while (top) putchar(stk[top--] + 48);
  putchar(ch);
}
template <class T, class... Args>
inline void write(T fir, Args... args) {
  write(fir, ' '), write(args...);
}
const int N = 2e5 + 5;
i64 h[N], p[N];
inline void solv() {
  int n = read<int>();
  for (int i = 1; i <= n; ++i) h[i] = read<i64>();
  i64 l = 0, r = i64(2e9), ret = -1;
  auto check = [&](i64 x) {
    for (int i = 1; i <= n; ++i) p[i] = h[i];
    for (int i = n; i >= 3; --i) {
      if (p[i] < x) return false;
      i64 d = std::min(h[i] / 3, (p[i] - x) / 3);
      p[i - 1] += d, p[i - 2] += d * 2;
    }
    if (p[1] < x || p[2] < x) return false;
    return true;
  };
  while (l <= r) {
    i64 mid = (l + r) >> 1;
    if (check(mid)) {
      ret = mid;
      l = mid + 1;
    } else
      r = mid - 1;
  }
  write(ret);
}
signed main() {
  int cza = read<int>();
  while (cza--) solv();
}
