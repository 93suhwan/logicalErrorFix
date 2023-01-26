#include <bits/stdc++.h>
using namespace std;
const int LEN = 2e5 + 50;
int T, n, m, cnt, cl;
struct Node {
  int index, val, colour;
} a[LEN];
inline int read() {
  char ch = getchar();
  int x = 0, f = 1;
  for (; !isdigit(ch); ch = getchar())
    if (ch == '-') f = -1;
  for (; isdigit(ch); ch = getchar()) x = x * 10 + (ch ^ 48);
  return x * f;
}
inline bool cmp_val(Node x, Node y) { return x.val < y.val; }
inline bool cmp_index(Node x, Node y) { return x.index < y.index; }
int main() {
  T = read();
  while (T--) {
    n = read();
    m = read();
    for (int i = 1; i <= n; i++) {
      a[i].val = read();
      a[i].index = i;
    }
    sort(a + 1, a + n + 1, cmp_val);
    cnt = 1;
    a[1].colour = cl = 1;
    for (int i = 2; i <= n; i++) {
      if (a[i].val != a[i - 1].val)
        cnt = 1;
      else
        cnt++;
      if (cnt > m) {
        a[i].colour = 0;
        continue;
      }
      if (cl == m) cl = 0;
      a[i].colour = ++cl;
    }
    if (cl == m) cl = 0;
    for (int i = n; cl; i--) {
      if (!a[i].colour) continue;
      a[i].colour = 0;
      --cl;
    }
    sort(a + 1, a + n + 1, cmp_index);
    for (int i = 1; i < n; i++) printf("%d ", a[i].colour);
    printf("%d\n", a[n].colour);
  }
  return 0;
}
