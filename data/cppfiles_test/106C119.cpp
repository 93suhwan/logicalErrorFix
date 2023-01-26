#include <bits/stdc++.h>
namespace Templates {
namespace InputOutput {
template <typename Tp>
inline void input(Tp &x) {
  static bool k;
  static char ch;
  for (k = 0, ch = getchar(); ch < '0' || '9' < ch; ch = getchar())
    if (ch == '-') k = 1;
  for (x = 0; '0' <= ch && ch <= '9'; ch = getchar())
    x = (x << 1) + (x << 3) + ch - '0';
  if (k) x = -x;
}
char Flof[97], emptyc = '\n';
int Fcnto;
template <typename Tp>
inline void output(Tp x, const char &ch = emptyc) {
  Fcnto = 0;
  if (!x) return (void)(putchar('0'), putchar(ch));
  if (x < 0) x = -x, putchar('-');
  while (x) Flof[Fcnto++] = x % 10 + '0', x /= 10;
  while (Fcnto) putchar(Flof[--Fcnto]);
  putchar(ch);
}
}  // namespace InputOutput
using namespace InputOutput;
namespace Containers {
template <typename Tp, const int SZ, typename comp = std::less<Tp> >
struct Priority_Queue {
  Tp q[SZ];
  int tail;
  Priority_Queue() { tail = 0; }
  void clear() { tail = 0; }
  inline bool empty() { return tail < 1; }
  inline int size() { return tail; }
  inline void push(const Tp &x) {
    q[tail++] = x, std::push_heap(q, q + tail, comp());
  }
  inline void pop() { std::pop_heap(q, q + tail, comp()), tail--; }
  inline Tp top() { return q[0]; }
};
template <typename Tp, const int SZ>
struct Queue {
  Tp q[SZ];
  int head, tail;
  Queue() { head = 1, tail = 0; }
  void clear() { head = 1, tail = 0; }
  inline bool empty() { return head > tail; }
  inline int size() { return tail - head + 1; }
  inline void push(const Tp &x) { q[++tail] = x; }
  inline void pop() { head++; }
  inline Tp front() { return q[head]; }
};
template <typename Tp, const int SZ>
struct Deque {
  Tp q[SZ << 1];
  int head, tail;
  Deque() { head = SZ + 1, tail = SZ; }
  void clear() { head = SZ + 1, tail = SZ; }
  inline bool empty() { return head > tail; }
  inline int size() { return tail - head + 1; }
  inline void push_front(const Tp &x) { q[--head] = x; }
  inline void push_back(const Tp &x) { q[++tail] = x; }
  inline void pop_front() { head++; }
  inline void pop_back() { tail--; }
  inline Tp front() { return q[head]; }
  inline Tp back() { return q[tail]; }
};
template <typename Tp, const int SZ>
struct Stack {
  Tp q[SZ];
  int tail;
  Stack() { tail = 0; }
  void clear() { tail = 0; }
  inline bool empty() { return tail <= 0; }
  inline int size() { return tail; }
  inline void push(const Tp &x) { q[++tail] = x; }
  inline void pop() { tail--; }
  inline Tp top() { return q[tail]; }
};
template <typename Tp, const int SZ>
struct BIT {
  int n;
  Tp c[SZ];
  BIT(const int sz = SZ - 1) { n = sz, memset(c, 0, sizeof c); }
  void clear(const int sz = SZ - 1) { n = sz, memset(c, 0, sizeof c); }
  inline void add(int x, const Tp &val) {
    while (x <= n) c[x] += val, x += x & -x;
  }
  inline Tp sum(int x) {
    Tp s = 0;
    while (x) s += c[x], x -= x & -x;
    return s;
  }
  inline Tp sum(const int x, const int y) { return sum(y) - sum(x - 1); }
};
}  // namespace Containers
using namespace Containers;
using std::bitset;
using std::get;
using std::lower_bound;
using std::max;
using std::min;
using std::pair;
using std::sort;
using std::swap;
using std::tuple;
using std::upper_bound;
using std::vector;
template <typename Tp>
Tp gcd(Tp a, Tp b) {
  Tp t;
  while (b) t = a, a = b, b = t % b;
  return a;
}
template <typename Tp>
Tp lcm(const Tp a, const Tp b) {
  return a / gcd(a, b) * b;
}
template <typename Tp>
void tomax(Tp &x, const Tp y) {
  x = std::max(x, y);
}
}  // namespace Templates
using namespace Templates;
int n;
void solve() {
  input(n);
  for (int i = 1; i <= n; i++) output(i + 1, i == n ? '\n' : ' ');
}
int main() {
  int caseCount;
  input(caseCount);
  while (caseCount--) solve();
  return 0;
}
