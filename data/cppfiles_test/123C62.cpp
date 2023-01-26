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
u32 def_cnt = 0;
template <class T>
void memset(int val, T &fir) {
  memset(fir, val, sizeof fir);
}
template <class T, class... args>
void memset(int val, T &fir, args &...arg) {
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
inline void read(T &x) {
  x = read<T>();
}
template <class T, class... Args>
inline void read(T &fir, Args &...args) {
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
inline void pre_work() { ; }
inline void solv() {
  int n = read<int>(), k = read<int>();
  ve<ve<int>> e(n);
  for (int i = 1; i < n; ++i) {
    int u, v;
    read(u, v);
    --u, --v;
    e[u].push_back(v), e[v].push_back(u);
  }
  ve<int> del;
  fun<int(int, int)> dfs = [&](int x, int fax) {
    int now = 0;
    for (const auto &y : e[x]) {
      if (y != fax) {
        int ret = dfs(y, x);
        if (ret > now) std::swap(ret, now);
        del.push_back(ret);
      }
    }
    return now + 1;
  };
  del.push_back(dfs(0, -1));
  std::sort(del.begin(), del.end(), std::greater<int>());
  del.resize(k, 0);
  i64 ret = i64(-1e18);
  for (int i = 0, rest = n; i <= k; ++i) {
    if (i > 0) {
      rest -= del[i - 1];
    }
    int axis = std::min(n / 2, rest);
    ret = std::max(ret, (1ll * n - i - axis) * (i - axis));
  }
  write(ret);
}
signed main() {
  pre_work();
  int cza = 1;
  while (cza--) solv();
}
