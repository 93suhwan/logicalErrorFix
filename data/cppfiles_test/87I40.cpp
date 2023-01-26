#include <bits/stdc++.h>
using namespace std;
const int N = 1e3 + 10;
struct node {
  int x;
  int id;
  int rank;
} a[N];
int cnt[N];
bool cmp1(node a, node b) { return a.x < b.x; }
bool cmp2(node a, node b) { return a.id < b.id; }
int vis[N];
int main() {
  int T;
  scanf("%d", &T);
  while (T--) {
    int n, m;
    memset(a, 0, sizeof(a));
    memset(vis, 0, sizeof(vis));
    memset(cnt, 0, sizeof(cnt));
    scanf("%d%d", &n, &m);
    a[0].x = 0;
    for (int i = 1; i <= m; i++) {
      scanf("%d", &a[i].x);
      a[i].id = i;
    }
    sort(a + 1, a + m + 1, cmp1);
    int id = 1;
    for (int i = 1; i <= m; i++) {
      if (a[i].x == a[i - 1].x) {
        id -= 1;
        a[i].rank = id;
      }
      a[i].rank = id++;
    }
    for (int i = 1; i <= m; i++) {
      cnt[a[i].rank]++;
    }
    sort(a + 1, a + m + 1, cmp2);
    int res = 0;
    for (int i = 1; i <= m; i++) {
      if (cnt[a[i].rank] > 1) {
        vis[a[i].rank + cnt[a[i].rank] - 1] = 1;
        cnt[a[i].rank]--;
        for (int j = 1; j < a[i].rank + cnt[a[i].rank]; j++) {
          if (vis[j]) res++;
        }
      } else {
        vis[a[i].rank] = 1;
        cnt[a[i].rank]--;
        for (int j = 1; j < a[i].rank; j++) {
          if (vis[j] >= 1) res++;
        }
      }
    }
    cout << res << endl;
  }
}
