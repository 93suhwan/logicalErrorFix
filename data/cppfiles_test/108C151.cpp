#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
struct Node {
  int pos;
  int x, y;
} a[N];
int vis[N];
bool cmp(const Node &x, const Node &y) {
  if (x.x != y.x) {
    return x.x > y.x;
  } else {
    return x.y > y.y;
  }
}
bool cmp2(const Node &x, const Node &y) { return x.pos < y.pos; }
int main() {
  int t;
  int n;
  int mi;
  cin >> t;
  while (t--) {
    memset(vis, 0, sizeof(vis));
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
      scanf("%d", &a[i].x);
      a[i].pos = i;
    }
    for (int i = 1; i <= n; i++) {
      scanf("%d", &a[i].y);
    }
    sort(a + 1, a + 1 + n, cmp);
    mi = a[1].y;
    vis[a[1].pos] = 1;
    int flag;
    flag = 1;
    for (int i = 2; i <= n; i++) {
      if (a[i].y > mi) {
        for (int j = flag + 1; j <= i; j++) {
          mi = min(mi, a[j].y);
          vis[a[j].pos] = 1;
        }
        flag = i;
      }
    }
    sort(a + 1, a + 1 + n, cmp2);
    for (int i = 1; i <= n; i++) {
      if (vis[i] == 1) {
        printf("1");
      } else {
        printf("0");
      }
    }
    cout << endl;
  }
  return 0;
}
