#include <bits/stdc++.h>
using namespace std;
struct node {
  int t;
  int k;
} a[200005];
bool cmp(struct node n, struct node m) {
  if (n.t == m.t) return n.k < m.k;
  return n.t < m.t;
}
int main() {
  int n;
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) {
    scanf("%d", &a[i].t);
    a[i].k = i;
  }
  sort(a + 1, a + n + 1, cmp);
  int l = 1, r = n, p = 1, q = -1;
  for (int i = 1; i <= n; i++) {
    if (a[i].k == l && a[i].t > q) {
      q = a[i].t;
      l++;
      p++;
    } else if (a[i].k == r && a[i].t > q) {
      q = a[i].t;
      r--;
      p++;
    }
  }
  if (p % 2 == 0)
    cout << "Alice" << endl;
  else
    cout << "Bob" << endl;
  return 0;
}
