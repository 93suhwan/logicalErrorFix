#include <bits/stdc++.h>
using namespace std;
inline bool is_digit(int ch) { return ch >= '0' && ch <= '9'; }
inline bool is_int(int ch) { return is_digit(ch) || ch == '-' || ch == '+'; }
inline int next_int() {
  int ch, sign = 1;
  int val = 0;
  while (!is_int(ch = getchar()) && ch != (-1))
    ;
  if (is_digit(ch)) {
    val = (int)ch - '0';
  } else if (ch == '-') {
    sign = -1;
  }
  while (is_int(ch = getchar())) {
    val = val * 10 + ch - '0';
  }
  return sign * val;
}
inline void print_int(int n) {
  static char print_buffer[0x20];
  size_t front = 0, sign = 0;
  if (n < 0) {
    n = (~n) + 1;
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
inline void print_int_ln(int n) {
  print_int(n);
  putchar('\n');
}
void print_ints(int n) { print_int(n); }
template <typename... T>
void print_ints(int first, T... values) {
  print_int(first);
  putchar(' ');
  print_ints(values...);
}
void print_ints_ln(int n) { print_int_ln(n); }
template <typename... T>
void print_ints_ln(int first, T... values) {
  print_int(first);
  putchar(' ');
  print_ints_ln(values...);
}
void print_int_array(int* arr, size_t length) {
  for (size_t i = 0; i != length; ++i) {
    print_int(arr[i]);
    putchar(i != length - 1 ? ' ' : '\n');
  }
}
inline void receive_int_array(int* arr, size_t length) {
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
int n;
int arr[200010];
long long fac[200010] = {1};
int main() {
  int cases = next_int();
  for (int i = 1; i < 200010; ++i) {
    fac[i] = (fac[i - 1] * i) % 998244353;
  }
  while (cases--) {
    n = next_int();
    receive_int_array(arr, n);
    int maxi = 0, sec = 0;
    for (int i = 0; i < n; ++i) {
      if (arr[i] > maxi) {
        sec = maxi;
        maxi = arr[i];
      } else if (arr[i] < maxi && arr[i] > sec) {
        sec = arr[i];
      }
    }
    int countsM = 0, countsS = 0;
    for (int i = 0; i < n; ++i) {
      countsM += arr[i] == maxi;
      countsS += arr[i] == sec;
    }
    if (countsM == 1 && maxi - sec > 1) {
      printf("0\n");
    } else {
      if (countsM > 1) {
        printf("%d\n", (int)fac[n]);
      } else {
        int rud = n - countsM - countsS;
        long long result = fac[n], acc = 1;
        for (int i = 0; i <= rud; ++i) {
          result = (result - fac[n - i - 1] * acc) % 998244353;
          acc = (acc * ((long long)rud - i)) % 998244353;
        }
        long long mod = 998244353;
        while (result < 0) {
          result += mod;
          mod *= 2;
        }
        result = result % 998244353;
        printf("%d\n", (int)result);
      }
    }
  }
  return 0;
}
