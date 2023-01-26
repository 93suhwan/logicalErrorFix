#include <bits/stdc++.h>
using namespace std;
int abs(int a) { return a < 0 ? -a : a; }
int maxn(int a, int b) { return a > b ? a : b; }
int minn(int a, int b) { return a < b ? a : b; }
int qr() {
  char ch = getchar();
  int x = 1, s = 0;
  while (ch < '0' || ch > '9') {
    if (ch == '-') x = -1;
    ch = getchar();
  }
  while (ch >= '0' && ch <= '9') {
    s = s * 10 + ch - '0';
    ch = getchar();
  }
  return x * s;
}
int T, n, ans;
int main() {
  T = qr();
  while (T--) {
    n = qr();
    for (int i = 1; i <= n; i++) {
      for (int j = 0; j < i; j++) printf("(");
      for (int j = 0; j < i; j++) printf(")");
      for (int j = 0; j < n - i; j++) printf("(");
      for (int j = 0; j < n - i; j++) printf(")");
      printf("\n");
    }
  }
  return 0;
}
