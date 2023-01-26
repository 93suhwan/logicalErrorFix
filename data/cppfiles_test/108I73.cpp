#include <bits/stdc++.h>
using namespace std;
const int INF = 0x3f3f3f3f;
const int N = 100005;
struct lwy {
  int a;
  int b;
  int idx;
} w[N];
int n;
bool st[N];
bool cmp1(struct lwy q, struct lwy w) { return q.a > w.a; }
bool cmp2(struct lwy q, struct lwy w) { return q.b > w.b; }
int main() {
  int T;
  scanf("%d", &T);
  while (T--) {
    memset(st, false, sizeof st);
    scanf("%d", &n);
    int ma1 = 0, mb1 = 0;
    int ma2 = 0, mb2 = 0;
    for (int i = 1; i <= n; i++) scanf("%d", &w[i].a);
    for (int i = 1; i <= n; i++) {
      scanf("%d", &w[i].b);
      w[i].idx = i;
    }
    for (int i = 1; i <= n; i++) {
      if (w[i].a > ma1) {
        ma1 = w[i].a;
        mb1 = w[i].b;
      }
      if (w[i].b > mb2) {
        mb2 = w[i].b;
        ma2 = w[i].a;
      }
      w[i].idx = i;
    }
    sort(w + 1, w + 1 + n, cmp1);
    st[w[1].idx] = true;
    for (int i = 1; i <= n; i++) {
      if (w[i].a > ma2 || w[i].b > mb2) {
        st[w[i].idx] = true;
        mb2 = min(mb2, w[i].b);
        ma2 = min(ma2, w[i].a);
      }
    }
    sort(w + 1, w + 1 + n, cmp2);
    st[w[1].idx] = true;
    for (int i = 1; i <= n; i++) {
      if (w[i].a > ma1 || w[i].b > mb1) {
        st[w[i].idx] = true;
        mb1 = min(mb1, w[i].b);
        ma1 = min(ma1, w[i].a);
      }
    }
    for (int i = 1; i <= n; i++) printf("%d", st[i]);
    puts("");
  }
}
