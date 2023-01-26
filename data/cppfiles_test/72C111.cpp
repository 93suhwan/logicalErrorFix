#include <bits/stdc++.h>
using namespace std;
const int inf = 0x3f3f3f3f;
const int N = 26;
template <typename T>
inline bool scan_d(T& ret) {
  char c;
  int sgn;
  if (c = getchar(), c == EOF) return 0;
  while (c != '-' && (c < '0' || c > '9')) {
    if ((c = getchar()) == EOF) return 0;
  }
  sgn = (c == '-') ? -1 : 1;
  ret = (c == '-') ? 0 : (c - '0');
  while (c = getchar(), c >= '0' && c <= '9') ret = ret * 10 + (c - '0');
  ret *= sgn;
  return 1;
}
template <typename T>
void print(T x) {
  static char s[33], *s1;
  s1 = s;
  if (!x) *s1++ = '0';
  if (x < 0) putchar('-'), x = -x;
  while (x) *s1++ = (x % 10 + '0'), x /= 10;
  while (s1-- != s) putchar(*s1);
}
template <typename T>
void println(T x) {
  print(x);
  putchar('\n');
}
int n, k;
set<int> num2set(int val) {
  set<int> mset;
  while (val) {
    mset.insert(val % 10);
    val /= 10;
  }
  return mset;
}
int solve(int val) {
  while (true) {
    set<int> mset = num2set(val);
    if (mset.size() <= k) return val;
    if (val % 10 == 0) {
      int pre = val / 10;
      int spre = solve(pre);
      mset = num2set(spre);
      return spre * 10 + *mset.begin();
    }
    val++;
  }
  return 0;
}
int main() {
  int T;
  scan_d(T);
  for (int t = (0); t < (T); ++t) {
    scan_d(n), scan_d(k);
    println(solve(n));
  }
  return 0;
}
