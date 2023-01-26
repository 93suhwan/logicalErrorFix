#include <bits/stdc++.h>
using namespace std;
int read() {
  int x = 0, f = 0;
  char ch = getchar();
  while (!isdigit(ch)) f |= ch == '-', ch = getchar();
  while (isdigit(ch)) x = 10 * x + ch - '0', ch = getchar();
  return f ? -x : x;
}
template <typename T>
void print(T x) {
  if (x < 0) putchar('-'), x = -x;
  if (x >= 10) print(x / 10);
  putchar(x % 10 + '0');
}
template <typename T>
void print(T x, char let) {
  print(x), putchar(let);
}
const int N = 2e5 + 5;
int t, n, a[N], c[N], tot, flag;
int main() {
  t = read();
  while (t--) {
    n = read();
    tot = 0;
    flag = 1;
    for (int i = 1; i <= n; i++) a[i] = read();
    int i = 1;
    while (i <= n) {
      if (a[i] == 0) {
        i++;
      } else {
        int j = i;
        if (j == n - 1) {
          if (a[n] == 1) {
            c[++tot] = j - 1;
            break;
          } else {
            flag = 0;
            break;
          }
        }
        if (j == n) {
          flag = 0;
          break;
        }
        while ((a[j] == 1 && (a[j] + a[j + 1] + a[j + 2]) % 2 == 1) ||
               (a[j] == 0 && (a[j] + a[j + 1] + a[j + 2]) % 2 == 0)) {
          j += 2;
          if (j == n - 1) {
            flag = 0;
            break;
          }
          if (j == n) {
            flag = 0;
            break;
          }
        }
        if (flag == 0)
          break;
        else {
          for (int k = j; k >= i; k -= 2) c[++tot] = k;
          for (int k = i; k <= j; k += 2)
            if (a[k] == 0) c[++tot] = k;
          i = j + 3;
        }
      }
    }
    if (flag == 0)
      cout << "NO" << endl;
    else {
      cout << "YES" << endl;
      cout << tot << endl;
      for (int i = 1; i <= tot; i++) cout << c[i] << " ";
      cout << endl;
    }
  }
  return 0;
}
