#include <bits/stdc++.h>
using ll = long long;
using namespace std;
int t;
struct TestCase {
  int mimi(int l, int r, int ro) {
    if (ro == 0) {
      if (l == 0 && r == 0) return 1;
      if (l == 1 && r == 0)
        return 0;
      else
        return 2;
    }
    if (r == (1 << (ro + 1)) - 1) return r + 1;
    if (l < (1 << ro) && r >= (1 << ro))
      return (1 << ro) + mimi(l, r - (1 << ro), ro - 1);
    else if (l >= (1 << ro) && r >= (1 << ro))
      return mimi(l - (1 << ro), r - (1 << ro), ro - 1);
    else if (l >= (1 << ro) && r < (1 << ro))
      return 0;
    else if (l < (1 << ro) && r < (1 << ro))
      return mimi(l, r, ro - 1);
  }
  int n, m;
  int ans = 0;
  void solve() {
    scanf("%d %d", &n, &m);
    int ro = (int)(log2(m));
    if (n > m)
      ans = 0;
    else if (m == (1 << (ro + 1)) - 1)
      ans = (1 << (ro + 1));
    else
      ans = mimi(n, m, ro);
    printf("%d \n", ans);
  }
};
int main() {
  scanf("%d", &t);
  while (t--) {
    TestCase nt;
    nt.solve();
  }
  return 0;
}
