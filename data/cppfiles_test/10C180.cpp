#include <bits/stdc++.h>
using namespace std;
int max(int a, int b) { return a > b ? a : b; }
int min(int a, int b) { return a < b ? a : b; }
inline int read() {
  char ch = getchar();
  int x = 0, r = 1;
  while (ch < '0' || ch > '9') {
    if (ch == '-') r = 0;
    ch = getchar();
  }
  while (ch >= '0' && ch <= '9')
    x = (x << 3) + (x << 1) + ch - '0', ch = getchar();
  return r ? x : -x;
}
int t, n, k, a[200100], b[200100], ans[200100], cnt[200100], l1, l2, top;
struct node {
  int k, no;
  bool operator<(const node b) const { return k < b.k; }
} q[200100];
int main() {
  t = read();
  while (t--) {
    n = read();
    k = read();
    for (int i = 1; i <= n; ++i) {
      a[i] = read();
      b[a[i]]++;
    }
    l1 = l2 = top = 0;
    for (int i = 1; i <= n; ++i) {
      if (b[a[i]] >= k)
        ans[i] = ++cnt[a[i]];
      else
        l1++, ans[i] = 0, q[++top].no = i, q[top].k = a[i];
    }
    l1 = (l1 / k) * k;
    sort(q + 1, q + top + 1);
    for (int i = 1; i <= top; ++i) {
      if (l2 >= l1) break;
      l2++;
      ans[q[i].no] = (l2 - 1) % k + 1;
    }
    for (int i = 1; i <= n; ++i) {
      if (ans[i] != 0 && ans[i] <= k)
        printf("%d ", ans[i]);
      else
        printf("0 ");
    }
    for (int i = 1; i <= n; ++i) a[i] = b[i] = ans[i] = cnt[i] = 0;
    puts("");
  }
  return 0;
}
