#include <bits/stdc++.h>
using namespace std;
inline void read(int &x) {
  x = 0;
  int f = 1;
  char ch = getchar();
  while ((ch < '0' || ch > '9') && ch != '-') ch = getchar();
  if (ch == '-') {
    f = -1;
    ch = getchar();
  }
  while (ch >= '0' && ch <= '9') {
    x = x * 10 + (ch - '0');
    ch = getchar();
  }
  x *= f;
}
template <typename _type>
void cmax(_type &a, _type b) {
  if (a < b) a = b;
}
template <typename _type>
void cmin(_type &a, _type b) {
  if (a > b) a = b;
}
const int N = 1e6 + 10;
int i, j, k, m, n, s, t;
vector<int> e[N];
int a[N], b[N], pd[N];
struct people {
  int a, b, rk;
} p[N];
bool cmp1(people a, people b) { return a.a < b.a; }
bool cmp2(people a, people b) { return a.b < b.b; }
queue<int> q;
void bfs() {
  while (!q.empty()) {
    int u = q.front();
    q.pop();
    for (int v : e[u]) {
      if (pd[v]) continue;
      pd[v] = 1;
      q.push(v);
    }
  }
}
signed main() {
  read(t);
  while (t--) {
    read(n);
    int maxna = 0, maxnb = 0;
    for (i = 1; i <= n; i++) pd[i] = 0, e[i].clear();
    for (i = 1; i <= n; i++)
      read(a[i]), cmax(maxna, a[i]), p[i].rk = i, p[i].a = a[i];
    for (i = 1; i <= n; i++) read(b[i]), cmax(maxnb, b[i]), p[i].b = b[i];
    sort(p + 1, p + n + 1, cmp1);
    pd[p[n].rk] = 1;
    q.push(p[n].rk);
    for (i = 1; i < n; i++) e[p[i].rk].push_back(p[i + 1].rk);
    sort(p + 1, p + n + 1, cmp2);
    pd[p[n].rk] = 1;
    q.push(p[n].rk);
    for (i = 1; i < n; i++) e[p[i].rk].push_back(p[i + 1].rk);
    bfs();
    for (i = 1; i <= n; i++) printf("%d", pd[i]);
    printf("\n");
  }
  return 0;
}
