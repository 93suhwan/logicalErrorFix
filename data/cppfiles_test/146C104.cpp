#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
using i32 = int;
const int INF = 0x3f3f3f3f;
const double tol = 1e-8;
const int P = 998244353;
int pop_count(i64 x) { return __builtin_popcountll(x); }
int pop_count(int x) { return __builtin_popcount(x); }
template <typename S, typename T>
bool check_and_save_min_in_lhs(S& lhs, const T& rhs) {
  return lhs < rhs ? 1 : lhs = rhs, 0;
}
template <typename S, typename T>
bool check_and_save_max_in_lhs(S& lhs, const T& rhs) {
  return lhs > rhs ? 1 : lhs = rhs, 0;
}
template <typename T>
T min_all(T ele) {
  return ele;
}
template <typename T, typename... Args>
T min_all(T fst_el, Args... others) {
  return min_all(fst_el, mins(others...));
}
template <typename T>
T maxs(T ele) {
  return ele;
}
template <typename T, typename... Args>
T maxs(T fst_el, Args... others) {
  return max(fst_el, maxs(others...));
}
template <typename T>
void read_int(T& num) {
  bool positive = true;
  char ch;
  num = 0;
  while (isspace(ch = getchar()))
    ;
  if (ch == '-')
    positive = false;
  else
    num = ch - '0';
  while ((ch = getchar()) >= '0' && ch <= '9') num = num * 10 + ch - '0';
  if (!positive) num = -num;
}
void read_ints(){};
template <typename T, typename... Args>
void read_ints(T& fst_el, Args&... others) {
  read_int(fst_el);
  read_ints(others...);
}
template <typename T>
void int_out(T num) {
  if (num < 0) {
    putchar('-');
    num = -num;
  }
  if (num > 9) int_out(num / 10);
  putchar(num % 10 + '0');
}
void int_outs() { puts(""); }
template <typename T, typename... Args>
void int_outs(T fst_ele, Args... others) {
  int_out(fst_ele);
  putchar(' ');
  int_outs(others...);
}
const int N = 100005, SQ = sqrt(N);
int p[N], pinv[N], pa[N], nx[N];
void solve(int case_t) {
  int n, q;
  read_ints(n, q);
  for (int i = 1; i <= n; ++i) {
    read_int(p[i]);
    pinv[p[i]] = i;
  }
  for (int i = 1; i <= n; ++i) {
    int a = i;
    for (int j = 1; j <= SQ; ++j) a = p[a];
    nx[i] = a;
  }
  while (q--) {
    int t, x, y, i, k;
    read_int(t);
    if (t == 1) {
      read_ints(x, y);
      swap(p[x], p[y]);
      pinv[p[x]] = x;
      pinv[p[y]] = y;
      int a = x;
      for (int j = 1; j <= SQ; ++j) a = p[a];
      nx[x] = a;
      for (int i = 1; i <= SQ; ++i) {
        x = pinv[x];
        a = pinv[a];
        nx[x] = a;
      }
      a = y;
      for (int i = 1; i <= SQ; ++i) a = p[a];
      nx[y] = a;
      for (int i = 1; i <= SQ; ++i) {
        y = pinv[y];
        a = pinv[a];
        nx[y] = a;
      }
    } else {
      read_ints(i, k);
      while (k >= SQ) {
        i = nx[i];
        k -= SQ;
      }
      while (k--) {
        i = p[i];
      }
      printf("%d\n", i);
    }
  }
}
int main() {
  int t = 1;
  for (int i = 1; i <= t; ++i) {
    solve(i);
  }
  return 0;
}
