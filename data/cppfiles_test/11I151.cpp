#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 5;
int n, f[N], tot = 0;
struct node {
  int x, y;
} a[N];
bool cmp(node xx, node yy) {
  if (xx.x != yy.x)
    return xx.x < yy.x;
  else
    return xx.y < yy.y;
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  cin >> n;
  for (int i = 1; i <= n; ++i) {
    cin >> a[i].x;
    a[i].y = i - a[i].x;
  }
  sort(a + 1, a + n + 1, cmp);
  for (int i = 1; i <= n; ++i) {
    if (a[i].y < 0) continue;
    if (a[i].y >= f[tot])
      f[++tot] = a[i].y;
    else {
      int p = lower_bound(f + 1, f + tot + 1, a[i].y) - f;
      f[p] = a[i].y;
    }
  }
  cout << tot << endl;
  return 0;
}
