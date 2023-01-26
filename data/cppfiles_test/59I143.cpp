#include <bits/stdc++.h>
using namespace std;
template <class T>
void read(T &s) {
  s = 0;
  T f = 1;
  char ch = getchar();
  while (ch < '0' || ch > '9') {
    if (ch == '-') f = -1;
    ch = getchar();
  }
  while (ch >= '0' && ch <= '9') {
    s = s * 10 + ch - '0';
    ch = getchar();
  }
  s *= f;
}
template <class T>
void put(T s) {
  if (s < 0) putchar(s % 10 + '0'), s = -s;
  if (s > 9) put(s / 10);
  putchar(s % 10 + '0');
}
const int N = 1e3 + 10;
int a[10][10];
int b[10];
int tmp[10];
int main() {
  int T;
  read(T);
  while (T--) {
    memset(a, 0, sizeof(a));
    memset(b, 0, sizeof(b));
    int n;
    read(n);
    for (int i = 1; i <= n; ++i) {
      for (int j = 1; j <= 5; ++j) {
        read(tmp[j]);
        if (tmp[j]) b[j]++;
      }
      for (int j = 1; j < 5; ++j) {
        if (!tmp[j]) continue;
        for (int k = j + 1; k <= 5; ++k)
          if (tmp[k]) a[j][k]++;
      }
    }
    bool flag = 0;
    for (int i = 1; i < 5; ++i) {
      if (b[i] < n / 2 || flag) continue;
      for (int j = i + 1; j <= 5; ++j) {
        if (b[j] < n / 2 || flag) continue;
        if (b[j] - a[i][j] < n / 2) continue;
        flag = 1;
      }
    }
    if (flag)
      puts("YES");
    else
      puts("NO");
  }
  return 0;
}
