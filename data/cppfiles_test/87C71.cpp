#include <bits/stdc++.h>
using namespace std;
int n, m;
struct Node {
  int pos, val, sit;
} a[305];
bool cmp(Node x, Node y) {
  if (x.val == y.val) {
    return x.pos > y.pos;
  }
  return x.val < y.val;
}
bool cmp2(Node x, Node y) { return x.pos < y.pos; }
int main() {
  int T;
  std::cin >> T;
  while (T--) {
    cin >> n >> m;
    for (int i = 1; i <= m; i++) {
      scanf("%d", &a[i].val);
      a[i].pos = i;
    }
    sort(a + 1, a + 1 + m, cmp);
    for (int i = 1; i <= m; i++) {
      a[i].sit = i;
    }
    sort(a + 1, a + 1 + m, cmp2);
    int ans = 0;
    for (int i = 2; i <= m; i++) {
      for (int j = i - 1; j >= 1; j--) {
        if (a[j].sit < a[i].sit) ans++;
      }
    }
    printf("%d\n", ans);
  }
  return 0;
}
