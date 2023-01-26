#include <bits/stdc++.h>
using namespace std;
template <typename T>
inline void cmin(T &x, T y) {
  x = (x < y ? x : y);
}
template <typename T>
inline void cmax(T &x, T y) {
  x = (x > y ? x : y);
}
char buf[100000], *p1(buf), *p2(buf);
inline long long read() {
  long long x = 0, f = 1;
  char ch =
      (p1 == p2 && (p2 = (p1 = buf) + fread(buf, 1, 100000, stdin), p1 == p2)
           ? EOF
           : *p1++);
  while (!isdigit(ch)) {
    if (ch == '-') f = 0;
    ch = (p1 == p2 && (p2 = (p1 = buf) + fread(buf, 1, 100000, stdin), p1 == p2)
              ? EOF
              : *p1++);
  }
  while (isdigit(ch)) {
    x = (x << 1) + (x << 3) + (ch ^ 48);
    ch = (p1 == p2 && (p2 = (p1 = buf) + fread(buf, 1, 100000, stdin), p1 == p2)
              ? EOF
              : *p1++);
  }
  return f ? x : -x;
}
const long long N = 2e5 + 1;
const long long INF = 1e9 + 7;
long long n, a[N];
inline void input() {
  n = read();
  for (long long i = 1; i <= n; i++) a[i] = read();
  return;
}
inline void work() {
  long long lef = 1, rig = n;
  while (a[lef] < a[lef + 1] && lef < n) lef++;
  while (a[rig] < a[rig - 1] && rig > 1) rig--;
  if (a[1] >= a[n] && (lef & 1)) return puts("Alice"), void();
  if (a[n] >= a[1] && ((n - rig + 1) & 1)) return puts("Alice"), void();
  puts("Bob");
  return;
}
inline void solve() {
  input();
  work();
  return;
}
int main() {
  solve();
  return 0;
}
