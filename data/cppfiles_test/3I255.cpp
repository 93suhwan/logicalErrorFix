#include <bits/stdc++.h>
char s[10], X;
int key;
inline long long power(long long a, long long b) {
  long long res = 1;
  while (b) {
    if (b & 1) res *= a;
    a *= a;
    b >>= 1;
  }
  return res;
}
int main() {
  scanf("%s", s);
  int len = strlen(s);
  if (len == 1) {
    puts(s[0] == '0' ? "1" : "0");
    return 0;
  }
  if (s[0] == '0') {
    puts("0");
    return 0;
  }
  if (!isdigit(s[len - 1])) {
    if (s[len - 1] == 'X') {
      if (s[len - 2] == 'X' || s[len - 2] == '0' || s[len - 2] == '5')
        X = '0';
      else if (s[len - 2] == '2' || s[len - 2] == '7')
        X = '5';
      else if (s[len - 2] == '_') {
        if (s[0] != 'X')
          key = len == 2 ? 3 : 4;
        else
          key = 2;
      } else {
        puts("0");
        return 0;
      }
    } else {
      if (s[len - 2] == '0' || s[len - 2] == '5' || s[len - 2] == '2' ||
          s[len - 2] == '7')
        key = 1;
      else if (s[len - 2] == 'X')
        X = '7';
      else if (s[len - 2] == '_')
        key = len == 2 ? 3 : 4;
      else {
        puts("0");
        return 0;
      }
    }
  } else if (s[len - 1] == '0') {
    if (s[len - 2] == 'X')
      X = '5';
    else if (s[len - 2] == '_')
      key = len == 2 ? 1 : 2;
    else if (s[len - 2] != '0' && s[len - 2] != '5') {
      puts("0");
      return 0;
    }
  } else if (s[len - 1] == '5') {
    if (s[len - 2] == 'X')
      X = '2';
    else if (s[len - 2] == '_')
      key = 2;
    else if (s[len - 2] != '2' && s[len - 2] != '7') {
      puts("0");
      return 0;
    }
  } else {
    puts("0");
    return 0;
  }
  if (X == '0' && s[0] == 'X') {
    puts("0");
    return 0;
  }
  if (!key) key = 1;
  int cnt = 0, cntx = 0;
  long long ans = 1;
  for (int i = 0; i < len; ++i) cntx += (s[i] == 'X');
  for (int i = len - 3; i >= 0; --i) cnt += (s[i] == '_');
  if (s[0] == '_')
    ans = 9 * power(10, cnt - 1);
  else
    ans = power(10, cnt);
  if (X == '2')
    ans *= 2;
  else if (X == '7')
    ans *= len == 2 ? 3 : 4;
  else if (cntx && !X)
    ans *= s[0] == 'X' ? 9 : 10;
  printf("%lld\n", ans);
  return 0;
}
