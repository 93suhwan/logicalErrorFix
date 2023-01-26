#include <bits/stdc++.h>
using namespace std;
const int N = 100005;
int n;
bool st[N];
struct A {
  int a;
  int b;
  int idx;
} a[N];
struct B {
  int a;
  int b;
  int idx;
} b[N];
bool cmp_a(struct A q, struct A w) { return q.a > w.a; }
bool cmp_b(struct B q, struct B w) { return q.b > w.b; }
int main() {
  int T;
  scanf("%d", &T);
  while (T--) {
    memset(st, false, sizeof st);
    memset(a, 0, sizeof a);
    memset(b, 0, sizeof b);
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
      scanf("%d", &a[i].a);
      b[i].a = a[i].a;
      a[i].idx = i;
      b[i].idx = i;
    }
    for (int i = 1; i <= n; i++) {
      scanf("%d", &a[i].b);
      b[i].b = a[i].b;
    }
    sort(a + 1, a + 1 + n, cmp_a);
    sort(b + 1, b + 1 + n, cmp_b);
    st[a[1].idx] = true;
    st[b[1].idx] = true;
    int mb = a[1].b;
    int ma = b[1].a;
    for (int l = 2, r = 2;;) {
      if (a[l].b > mb || a[l].a > ma) {
        st[a[l].idx] = true;
        ma = min(ma, a[l].a);
        mb = min(mb, a[l].b);
        l++;
      }
      if (b[r].a > ma || b[r].b > mb) {
        st[b[r].idx] = true;
        mb = min(mb, b[r].b);
        ma = min(ma, b[r].a);
        r++;
      }
      if (a[l].b <= mb && b[r].a <= ma) break;
    }
    for (int i = 1; i <= n; i++) {
      if (st[i] == true)
        printf("1");
      else
        printf("0");
    }
    puts("");
  }
}
