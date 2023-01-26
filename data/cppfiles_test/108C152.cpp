#include <bits/stdc++.h>
using namespace std;
const int N = 100010;
int ans[N];
int Min1[N], Min2[N];
int l1, r1, l2, r2;
struct node {
  int x, y, id;
} a[N], b[N];
bool cmpx(node x, node y) { return x.x < y.x; }
bool cmpy(node x, node y) { return x.y < y.y; }
int main() {
  int T;
  scanf("%d", &T);
  while (T--) {
    int n;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
      scanf("%d", &a[i].x);
      a[i].id = i;
      ans[i] = 0;
    }
    for (int i = 1; i <= n; i++) {
      scanf("%d", &a[i].y);
      b[i] = a[i];
    }
    sort(a + 1, a + n + 1, cmpx);
    sort(b + 1, b + n + 1, cmpy);
    Min1[n] = a[n].y;
    Min2[n] = b[n].x;
    for (int i = n - 1; i; i--) {
      Min1[i] = min(Min1[i + 1], a[i].y);
      Min2[i] = min(Min2[i + 1], b[i].x);
    }
    ans[a[n].id] = 1;
    int Ty = 0, p1 = n, p2 = n;
    l1 = l2 = 1;
    r1 = n - 1;
    r2 = n;
    while (1) {
      if (Ty == 0) {
        int L = l2, R = r2, pos;
        while (L <= R) {
          int mid = (L + R) >> 1;
          if (b[mid].y < Min1[p1]) {
            L = mid + 1;
          } else {
            R = mid - 1;
            pos = mid;
          }
        }
        if (R == r2) {
          break;
        }
        for (int i = pos; i <= p2; i++) {
          ans[b[i].id] = 1;
        }
        p2 = pos;
        r2 = pos - 1;
        Ty ^= 1;
      } else {
        int L = l1, R = r1, pos;
        while (L <= R) {
          int mid = (L + R) >> 1;
          if (a[mid].x < Min2[p2]) {
            L = mid + 1;
          } else {
            R = mid - 1;
            pos = mid;
          }
        }
        if (R == r2) {
          break;
        }
        for (int i = pos; i <= p1; i++) {
          ans[a[i].id] = 1;
        }
        p1 = pos;
        r1 = pos - 1;
        Ty ^= 1;
      }
    }
    for (int i = 1; i <= n; i++) {
      printf("%d", ans[i]);
    }
    puts("");
  }
  return 0;
}
