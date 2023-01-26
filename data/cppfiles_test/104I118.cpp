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
void solve() {
  n = read();
  tot = 0;
  flag = 1;
  for (int i = 1; i <= n; i++) a[i] = read();
  int i;
  if (a[1] == 0) {
    i = 2;
  } else {
    int j = 1;
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
    if (flag == 0) {
      cout << -1 << endl;
      return;
    } else {
      for (int k = j; k >= 1; k -= 2) c[++tot] = k;
      for (int k = 1; k <= j; k += 2)
        if (a[k] == 0) c[++tot] = k;
    }
    i = j + 3;
  }
  while (i <= n) {
    if (a[i] == 1) {
      if (i == n - 1) {
        if (a[n] == 1) {
          c[++tot] = i - 1;
          break;
        } else {
          flag = 0;
          break;
        }
      }
      if (i == n) {
        flag = 0;
        break;
      }
      if (a[i + 1] + a[i + 2] == 1) {
        c[++tot] = i;
        i += 3;
      } else if (a[i + 1] == 1) {
        c[++tot] = i - 1;
        i += 2;
      } else {
        c[++tot] = i;
        c[++tot] = i - 1;
        a[i + 2] = 1;
        i += 2;
      }
    } else {
      i++;
    }
  }
  if (flag == 0) {
    cout << -1 << endl;
    return;
  } else {
    cout << "YES" << endl;
    cout << tot << endl;
    for (int i = 1; i <= tot; i++) cout << c[i] << " ";
    cout << endl;
  }
}
int main() {
  t = read();
  while (t--) {
    solve();
  }
  return 0;
}
