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
const int N = 2004, MOD = 1e9 + 7;
char source[N], target[N];
i64 p[N][N << 1], s[N][N << 1];
int eq[N], lt[N], gt[N];
void solve(int case_t) {
  int n;
  read_int(n);
  gets(source);
  gets(target);
  for (int i = 0; i < n; i += 2) {
    if (source[i] != '?') source[i] = source[i] == '0' ? '1' : '0';
    if (target[i] != '?') target[i] = target[i] == '0' ? '1' : '0';
  }
  for (int i = 0; i <= n - 1; ++i) {
    eq[i] = lt[i] = gt[i] = 0;
    if (source[i] == '?' && target[i] == '?') {
      eq[i] = 2;
    } else if (source[i] == '?' || target[i] == '?' || source[i] == target[i]) {
      eq[i] = 1;
    }
    if (source[i] != '1' && target[i] != '0') {
      lt[i] = 1;
    }
    if (source[i] != '0' && target[i] != '1') {
      gt[i] = 1;
    }
  }
  memset(p[0], 0, (n * 2 + 3) * sizeof *p[0]);
  memset(s[n], 0, (n * 2 + 3) * sizeof *s[n]);
  p[0][n] = 1;
  s[n][n] = 1;
  for (int i = 1; i <= n; ++i) {
    memset(p[i], 0, (n * 2 + 3) * sizeof *p[i]);
    memset(s[n - i], 0, (n * 2 + 3) * sizeof *s[n - i]);
    for (int j = -i + n; j <= i + n; ++j) {
      p[i][j] = eq[i - 1] * p[i - 1][j] + lt[i - 1] * p[i - 1][j + 1] +
                gt[i - 1] * p[i - 1][j - 1];
      p[i][j] %= MOD;
      s[n - i][j] = eq[n - i] * s[n - i + 1][j] +
                    lt[n - i] * s[n - i + 1][j + 1] +
                    gt[n - i] * s[n - i + 1][j - 1];
      s[n - i][j] %= MOD;
    }
  }
  i64 ans = 0;
  for (int i = 1; i <= n - 1; ++i) {
    for (int j = -i; j <= i; ++j) {
      ans = (ans + abs(j) * (p[i][j + n] * s[i][n - j] % MOD)) % MOD;
    }
  }
  printf("%lld\n", ans);
}
int main() {
  int t = 1;
  read_int(t);
  for (int i = 1; i <= t; ++i) {
    solve(i);
  }
  return 0;
}
