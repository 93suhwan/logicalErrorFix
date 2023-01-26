#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 10;
vector<int> edges[maxn];
int p[maxn];
bool st[maxn];
int find(int x) {
  if (p[x] != x) p[x] = find(p[x]);
  return p[x];
}
void unin(int x, int y) {
  x = find(x);
  y = find(y);
  if (x == y)
    return;
  else
    p[x] = y;
}
int n, m;
void check(int r) {
  for (int i = 1; i <= n; ++i) {
    if (!st[i]) {
      edges[r].push_back(i);
      edges[i].push_back(r);
      unin(r, i);
      st[i] = 1;
    }
  }
  int resource = find(1);
  for (int i = 2; i <= n; ++i) {
    if (find(i) != resource) {
      edges[i].push_back(1);
      edges[1].push_back(i);
      unin(i, 1);
    }
  }
}
void print() {
  queue<int> q;
  q.push(1);
  while (q.size()) {
    int t = q.front();
    q.pop();
    st[t] = 0;
    for (int i = 0; i < edges[t].size(); ++i) {
      if (st[edges[t][i]]) {
        q.push(edges[t][i]);
        printf("%d %d\n", t, edges[t][i]);
      }
    }
  }
}
int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    scanf("%d%d", &n, &m);
    for (int i = 0; i <= n; ++i) edges[i].clear();
    for (int i = 0; i <= n; ++i) p[i] = i;
    int record;
    while (m--) {
      int x, y, z;
      scanf("%d%d%d", &x, &y, &z);
      edges[x].push_back(z);
      edges[z].push_back(x);
      record = st[x] = st[z] = 1;
      unin(z, x);
    }
    check(record);
    print();
  }
  return 0;
}
