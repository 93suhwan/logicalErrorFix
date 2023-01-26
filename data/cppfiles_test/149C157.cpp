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
const int N = 2002;
char s[N];
int main() {
  int t;
  read_int(t);
  while (t--) {
    int n, k;
    i64 x;
    read_ints(n, k);
    read_int(x);
    gets(s);
    int len = 0, cur = 0;
    char ch[3] = "a*";
    vector<int> r[2];
    for (int i = 0, len; i < n; i += len) {
      len = 0;
      while (i + len < n && s[i + len] == ch[cur]) {
        ++len;
      }
      r[cur].push_back(len);
      cur ^= 1;
    }
    if (r[0].size() != r[1].size()) r[1].push_back(0);
    vector<i64> acc(r[1].size(), 0);
    int idx;
    i64 cnt = 1;
    for (idx = r[1].size() - 1; idx >= 0; --idx) {
      acc[idx] = cnt;
      if ((i64(k) * r[1][idx] + 1) > x / cnt) {
        break;
      } else {
        cnt = cnt * (1 + (i64)k * r[1][idx]);
      }
    }
    for (int i = 0; i < r[0].size(); ++i) {
      while (r[0][i]--) {
        putchar('a');
      }
      if (i >= idx && x > 0) {
        cnt = (x - 1) / acc[i];
        x -= cnt * acc[i];
        for (int j = 0; j < cnt; ++j) {
          putchar('b');
        }
      }
    }
    puts("");
  }
  return 0;
}
