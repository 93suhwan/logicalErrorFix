#include <bits/stdc++.h>
using namespace std;
struct node {
  int st, ed, c;
} A[100005];
bool mark[100005];
vector<int> edge[100005];
int n, m, t;
bool cmp(node a, node b) { return a.st < b.st; }
int fa[100005];
int getfa(int v) {
  if (fa[v] == v)
    return fa[v];
  else
    return fa[v] = getfa(fa[v]);
}
int main() {
  scanf("%d", &t);
  while (t--) {
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++) edge[i].clear();
    for (int i = 1; i <= n; i++) mark[i] = 0;
    for (int i = 1; i <= n; i++) fa[i] = i;
    for (int i = 1; i <= m; i++) {
      int a, b, c;
      scanf("%d%d%d", &a, &b, &c);
      if (a > b) swap(a, b);
      A[i] = (node){a, b, c};
    }
    sort(A + 1, A + m + 1, cmp);
    for (int i = 1; i <= m; i++) {
      int a = A[i].st, b = A[i].ed, c = A[i].c;
      if (!mark[b]) {
        int fab = getfa(b);
        fa[fab] = getfa(a);
        mark[b] = 1;
        edge[a].push_back(b);
      }
      if (!mark[c]) {
        int fac = getfa(c);
        fa[fac] = getfa(a);
        mark[c] = 1;
        edge[a].push_back(c);
      }
    }
    int st1 = 1;
    for (int i = 1; i <= n; i++) {
      int k = getfa(i);
      if (fa[k] == i) {
        st1 = k;
        break;
      }
    }
    for (int i = 1; i <= n; i++) {
      if (!mark[i] && i != st1)
        printf("%d %d\n", st1, i);
      else {
        for (int j = 0; j < edge[i].size(); j++) {
          printf("%d %d\n", i, edge[i][j]);
        }
      }
    }
  }
  return 0;
}
