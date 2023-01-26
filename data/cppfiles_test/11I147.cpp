#include <bits/stdc++.h>
using namespace std;
int q[10000000];
int p[10000000];
struct node {
  int num;
  int c;
} a[10000000];
bool cmp(node x1, node x2) {
  if (x1.num < x2.num) {
    return 1;
  } else {
    return 0;
  }
}
int main() {
  int n;
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> a[i].num;
    a[i].c = a[i].num - i;
  }
  int ans = 1;
  sort(a + 1, a + n + 1, cmp);
  q[1] = 0;
  for (int i = 1; i <= n; i++) {
    if (a[i].c <= q[ans] && p[ans] != a[i].num) {
      ans++;
      q[ans] = a[i].c;
      p[ans] = a[i].num;
    } else {
      int tem = lower_bound(q + 2, q + ans + 1, a[i].c, greater<int>()) - q;
      if (tem != 1 && p[tem - 1] != a[i].num) {
        q[tem] = a[i].c;
        p[tem] = a[i].num;
      }
    }
  }
  cout << ans - 1;
  return 0;
}
