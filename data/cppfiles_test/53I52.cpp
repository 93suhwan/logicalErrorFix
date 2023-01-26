#include <bits/stdc++.h>
using namespace std;
const int maxl = 100005;
int read() {
  int s = 0, w = 1;
  char ch = getchar();
  while (ch < '0' || ch > '9') {
    if (ch == '-') w = -w;
    ch = getchar();
  }
  while (ch >= '0' && ch <= '9') {
    s = s * 10 + (ch ^ '0');
    ch = getchar();
  }
  return s * w;
}
int t, n, k, flag;
int a[maxl];
struct node {
  int rt, num;
} b[maxl];
bool cmp(node tmpx, node tmpy) { return tmpx.num < tmpy.num; }
signed main() {
  t = read();
  while (t--) {
    n = read(), k = read() - 1;
    flag = 1;
    for (int i = 1; i <= n; i++) {
      a[i] = read();
      b[i].rt = i, b[i].num = a[i];
    }
    sort(b + 1, b + n + 1, cmp);
    for (int i = 1; i <= n; i++) a[i] = b[i].rt;
    for (int i = 1; i < n; i++) {
      if (a[i] > a[i + 1]) k--;
      if (k < 0) {
        flag = 0;
        break;
      }
    }
    if (flag == 0)
      puts("NO");
    else
      puts("YES");
  }
  return 0;
}
