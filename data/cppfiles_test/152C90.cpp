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
const int N = 1000005;
int p[N], dp[N][2][2], pre[N][2][2][2];
int main() {
  int t;
  read_int(t);
  while (t--) {
    int n;
    read_int(n);
    for (int i = 1; i <= n; ++i) {
      read_int(p[i]);
    }
    memset(dp, 0x3f, (n + 2) * sizeof(dp[0]));
    dp[1][0][0] = -n - 1;
    dp[1][0][1] = -n - 1;
    for (int i = 1; i <= n - 1; ++i) {
      for (int cur_pos = 0; cur_pos <= 1; ++cur_pos) {
        for (int cur_sign = 0; cur_sign <= 1; ++cur_sign) {
          if (dp[i][cur_pos][cur_sign] > n) continue;
          int x = p[i] * (cur_sign * 2 - 1);
          int y = dp[i][cur_pos][cur_sign];
          if (cur_pos) swap(x, y);
          for (int next_sign = 0; next_sign <= 1; ++next_sign) {
            int z = next_sign == 0 ? -p[i + 1] : p[i + 1];
            if (z > x) {
              if (y < dp[i + 1][0][next_sign]) {
                pre[i + 1][0][next_sign][0] = cur_pos;
                pre[i + 1][0][next_sign][1] = cur_sign;
                dp[i + 1][0][next_sign] = y;
              }
            } else if (z > y) {
              if (x < dp[i + 1][1][next_sign]) {
                pre[i + 1][1][next_sign][0] = cur_pos;
                pre[i + 1][1][next_sign][1] = cur_sign;
                dp[i + 1][1][next_sign] = x;
              }
            }
          }
        }
      }
    }
    int cur_pos = -1, cur_sign = -1;
    for (int i = 0; i <= 1; ++i) {
      for (int j = 0; j <= 1; ++j) {
        if (dp[n][i][j] <= n) {
          cur_pos = i;
          cur_sign = j;
          break;
        }
      }
    }
    if (cur_pos == -1) {
      puts("NO");
      continue;
    }
    puts("YES");
    for (int i = n; i >= 1; --i) {
      if (cur_sign == 0) p[i] = -p[i];
      int tpos = cur_pos;
      cur_pos = pre[i][tpos][cur_sign][0];
      cur_sign = pre[i][tpos][cur_sign][1];
    }
    for (int i = 1; i <= n; ++i) {
      printf("%d ", p[i]);
    }
    puts("");
  }
  return 0;
}
