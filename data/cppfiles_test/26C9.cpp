#include <bits/stdc++.h>
using namespace std;
namespace chino {
const int maxn = 0x3f3f3f3f;
const int inf = 0x7fffffff;
}  // namespace chino
template <typename T = int>
inline T read() {
  char ch;
  T f = 1, x = 0;
  do {
    ch = getchar();
    if (ch == '-') f = -1;
  } while (!isdigit(ch));
  do {
    x = x * 10 + ch - '0';
    ch = getchar();
  } while (isdigit(ch));
  return f * x;
}
template <typename T>
inline void print(T x) {
  if (x < 0) {
    putchar('-');
    x = -x;
  }
  if (x > 9) print(x / 10);
  putchar(x % 10 + '0');
}
const int mod = 1e9 + 7;
int main() {
  int t;
  cin >> t;
  while (t--) {
    string s;
    cin >> s;
    int len = s.length();
    int ans = chino::maxn;
    string t = s;
    for (int i = 0; i < len; i++) {
      if (s[i] == '?') {
        if (i % 2 == 0)
          s[i] = '1';
        else
          s[i] = '0';
      }
    }
    for (int i = 0; i < len; i++) {
      if (t[i] == '?') {
        if (i % 2 == 0)
          t[i] = '0';
        else
          t[i] = '1';
      }
    }
    int a = 0, b = 0;
    for (int i = 0; i < len; i++) {
      if (s[i] == '1') {
        if (i & 1)
          b++;
        else
          a++;
      }
      if (i & 1) {
        if (a - b > (10 - i) / 2 || b - a > (10 - i) / 2) {
          ans = min(ans, i + 1);
          break;
        }
      } else {
        if (a - b > (10 - i) / 2 || b - a > (10 - i) / 2 - 1) {
          ans = min(ans, i + 1);
          break;
        }
      }
      if (i == len - 1) {
        ans = min(ans, 10);
      }
    }
    a = 0, b = 0;
    for (int i = 0; i < len; i++) {
      if (t[i] == '1') {
        if (i & 1)
          b++;
        else
          a++;
      }
      if (i & 1) {
        if (a - b > (10 - i) / 2 || b - a > (10 - i) / 2) {
          ans = min(ans, i + 1);
          break;
        }
      } else {
        if (a - b > (10 - i) / 2 || b - a > (10 - i) / 2 - 1) {
          ans = min(ans, i + 1);
          break;
        }
      }
      if (i == len - 1) {
        ans = min(ans, 10);
      }
    }
    cout << ans << endl;
  }
}
