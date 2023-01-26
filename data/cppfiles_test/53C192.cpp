#include <bits/stdc++.h>
using namespace std;
long long read() {
  long long p = 0, f = 1;
  char c = getchar();
  while (c < 48 || c > 57) {
    if (c == '-') f = -1;
    c = getchar();
  }
  while (c >= 48 && c <= 57) p = (p << 1) + (p << 3) + (c ^ 48), c = getchar();
  return p * f;
}
struct node {
  int val, id;
} a[300010];
bool cmp(node x, node y) { return x.val < y.val; }
int main() {
  int t = read();
  while (t--) {
    int cnt = 1;
    int n = read(), k = read();
    for (int i = 1; i <= n; i++) {
      a[i].val = read();
      a[i].id = i;
    }
    sort(a + 1, a + 1 + n, cmp);
    for (int i = 2; i <= n; i++) {
      if (a[i].id != a[i - 1].id + 1) cnt++;
    }
    if (cnt > k)
      puts("No");
    else
      puts("Yes");
  }
  return 0;
}
