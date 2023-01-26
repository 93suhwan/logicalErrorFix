#include <bits/stdc++.h>
const int inf = 0x3f3f3f3f;
using namespace std;
int n, m, k;
int ans = 0;
int fa1[1005], fa2[1005];
struct node {
  int x, y;
} q[1005];
void init() {
  for (int i = 1; i <= n; i++) fa1[i] = i, fa2[i] = i;
}
int find1(int x) {
  if (fa1[x] == x) return x;
  return fa1[x] = find1(fa1[x]);
}
int find2(int x) {
  if (fa2[x] == x) return x;
  return fa2[x] = find2(fa2[x]);
}
int main() {
  scanf("%d%d%d", &n, &m, &k);
  init();
  for (int i = 1; i <= m; i++) {
    int x, y;
    scanf("%d%d", &x, &y);
    int fx = find1(x);
    int fy = find1(y);
    if (fx != fy) fa1[fx] = fy;
  }
  for (int i = 1; i <= k; i++) {
    int x, y;
    scanf("%d%d", &x, &y);
    int fx = find2(x);
    int fy = find2(y);
    if (fx != fy) fa2[fx] = fy;
  }
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= n; j++) {
      int x1 = find1(i);
      int y1 = find1(j);
      int x2 = find2(i);
      int y2 = find2(j);
      if (x1 != y1 && x2 != y2) {
        ans++;
        q[ans].x = i;
        q[ans].y = j;
        fa1[x1] = y1;
        fa2[x2] = y2;
      }
    }
  cout << ans << endl;
  for (int i = 1; i <= ans; i++) {
    cout << q[i].x << " " << q[i].y << endl;
  }
}
