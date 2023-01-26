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
inline void pre_work() { ; }
inline void solv() {
  int n, m;
  read(n, m);
  ve<int> x(n);
  for (int i = 0; i < n; ++i) {
    x[i] = read<int>();
  }
  ve<std::string> s(n);
  for (int i = 0; i < n; ++i) {
    std::cin >> s[i];
  }
  ve<int> perm;
  int ret = -1;
  for (int mask = 0; mask < (1 << n); ++mask) {
    ve<int> c(m);
    int sum = 0;
    for (int i = 0; i < n; ++i) {
      if ((mask >> i) & 1) {
        sum += x[i];
        for (int j = 0; j < m; ++j) {
          if (s[i][j] == '1') --c[j];
        }
      } else {
        sum -= x[i];
        for (int j = 0; j < m; ++j) {
          if (s[i][j] == '1') ++c[j];
        }
      }
    }
    ve<int> ord(m);
    std::iota(ord.begin(), ord.end(), 0);
    std::sort(ord.begin(), ord.end(),
              [&](int x, int y) { return c[x] > c[y]; });
    ve<int> nper(m);
    for (int i = 0; i < m; ++i) {
      sum += (m - i) * c[ord[i]];
      nper[ord[i]] = m - i;
    }
    if (sum > ret) ret = sum, perm = nper;
  }
  for (auto it : perm) write(it, ' ');
  puts("");
}
signed main() {
  pre_work();
  int cza = read<int>();
  while (cza--) solv();
}
