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
bool dfs(const long long op, long long lef, long long rig, long long x,
         long long y) {
  if (lef == rig) return op;
  if (a[lef] >= a[rig] && (x & 1)) return op;
  if (a[rig] >= a[lef] && (y & 1)) return op;
  if (a[lef] < a[rig]) return dfs(op ^ 1, lef + 1, rig, x - 1, y);
  if (a[rig] < a[lef]) return dfs(op ^ 1, lef, rig - 1, x, y - 1);
  if (a[lef] == a[rig]) return op ^ 1;
}
inline void work() {
  long long lef = 1, rig = n, lt = 1, rt = 1;
  while (a[lef] < a[lef + 1] && lef < n) lt++, lef++;
  while (a[rig] < a[rig - 1] && rig > 1) rt++, rig--;
  puts(dfs(0, 1, n, lt, rt) ? "Bob" : "Alice");
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
