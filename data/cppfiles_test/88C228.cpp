#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
struct node {
  int x, y;
} b[90005];
bool cmp1(node a, node b) {
  if (a.x == b.x) return a.y < b.y;
  return a.x < b.x;
}
bool cmp2(node a, node b) {
  if (a.x == b.x) return a.y > b.y;
  return a.x < b.x;
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int t;
  cin >> t;
  while (t--) {
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < n * m; i++) {
      cin >> b[i].x;
      b[i].y = i + 1;
    }
    sort(b, b + n * m, cmp1);
    int ans = 0;
    for (int i = 0; i < n; i++) {
      int st = i * m, ed = i * m + m;
      sort(b + st, b + ed, cmp2);
      for (int j = st; j < ed; j++)
        for (int k = st; k < j; k++)
          if (b[k].y < b[j].y) ans++;
    }
    cout << ans << endl;
  }
  return 0;
}
