#include <bits/stdc++.h>
using namespace std;
int read() {
  char c = getchar();
  int ans = 0, f = 1;
  while (c < '0' || c > '9') {
    if (c == '-') f = -1;
    c = getchar();
  }
  while (c >= '0' && c <= '9') {
    ans = ans * 10 + c - '0';
    c = getchar();
  }
  return ans * f;
}
int t, n;
struct node {
  int a, b;
  int id;
} p[100010];
struct nod {
  int val;
  friend bool operator<(nod a, nod b) { return a.val < b.val; }
};
set<nod> s;
int ans[100010];
int cmp(node a, node b) { return a.a > b.a; }
void printset() {
  set<nod>::iterator x = s.begin();
  printf("siz=%d\n", (int)s.size());
  for (; x != s.end(); x++) {
    printf("%d ", x->val);
  }
  printf("\n");
}
int main() {
  scanf("%d", &t);
  while (t--) {
    s.clear();
    memset(ans, 0, sizeof(ans));
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
      scanf("%d", &p[i].a);
      p[i].id = i;
    }
    for (int i = 1; i <= n; i++) scanf("%d", &p[i].b);
    sort(p + 1, p + 1 + n, cmp);
    for (int i = 1; i <= n; i++) s.insert((nod){p[i].b});
    int maxx = 0;
    for (int i = 1; i <= n; i++) {
      set<nod>::iterator x = s.lower_bound((nod){maxx});
      if (maxx > p[i].b && x == s.end())
        ans[p[i].id] = 0;
      else
        ans[p[i].id] = 1;
      s.erase((nod){p[i].b});
      maxx = max(maxx, p[i].b);
    }
    for (int i = 1; i <= n; i++) printf("%d", ans[i]);
    printf("\n");
  }
  return 0;
}
