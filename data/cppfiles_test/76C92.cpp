#include <bits/stdc++.h>
using namespace std;
inline bool is_digit(int ch) { return ch >= '0' && ch <= '9'; }
inline bool is_int(int ch) { return is_digit(ch) || ch == '-' || ch == '+'; }
inline long long next_int() {
  int ch, sign = 1;
  long long val = 0;
  while (!is_int(ch = getchar()) && ch != (-1))
    ;
  if (is_digit(ch)) {
    val = (long long)ch - '0';
  } else if (ch == '-') {
    sign = -1;
  }
  while (is_int(ch = getchar())) {
    val = val * 10 + ch - '0';
  }
  return sign * val;
}
inline void print_int(long long n) {
  static char print_buffer[0x20];
  size_t front = 0, sign = 0;
  if (n < 0) {
    n = -n;
    sign = !sign;
  }
  do {
    print_buffer[front++] = (n % 10) + '0';
    n /= 10;
  } while (n);
  if (sign) {
    print_buffer[front++] = '-';
  }
  while (front--) {
    putchar(print_buffer[front]);
  }
}
inline void print_int_ln(long long n) {
  print_int(n);
  putchar('\n');
}
void print_ints(long long n) { print_int(n); }
template <typename... T>
void print_ints(long long first, T... values) {
  print_int(first);
  putchar(' ');
  print_ints(values...);
}
void print_ints_ln(long long n) { print_int_ln(n); }
template <typename... T>
void print_ints_ln(long long first, T... values) {
  print_int(first);
  putchar(' ');
  print_ints_ln(values...);
}
void print_int_array(long long* arr, size_t length) {
  for (size_t i = 0; i != length; ++i) {
    print_int(arr[i]);
    putchar(i != length - 1 ? ' ' : '\n');
  }
}
inline void receive_int_array(long long* arr, size_t length) {
  for (size_t i = 0; i != length; ++i) {
    arr[i] = next_int();
  }
}
inline size_t receive_line(char* str) {
  size_t length;
  int ch;
  for (length = 0; (ch = getchar()) != '\n' && ch != (-1); ++length) {
    str[length] = ch;
  }
  str[length] = 0;
  return length;
}
int n, mod;
long long res[200010] = {0, 1}, presum_res[200010];
int main() {
  int cases = 1;
  while (cases--) {
    n = next_int();
    mod = next_int();
    for (int i = 1; i <= n; ++i) {
      if (i > 1) {
        res[i] = presum_res[i - 1];
        int j;
        for (j = 2; (j + 1) * (j + 1) <= i; ++j) {
          res[i] = (res[i] + res[i / j]) % mod;
        }
        for (j = i / j; j >= 1; --j) {
          res[i] = (res[i] + res[j] * max(0, i / j - i / (j + 1))) % mod;
        }
      }
      presum_res[i] = (res[i] + presum_res[i - 1]) % mod;
    }
    print_int_ln(res[n]);
  }
  return 0;
}
