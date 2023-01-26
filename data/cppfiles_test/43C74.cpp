#include <bits/stdc++.h>
using namespace std;
inline int read() {
  int x = 0;
  char c = getchar();
  while (!isdigit(c)) c = getchar();
  while (isdigit(c)) x = x * 10 + (c ^ '0'), c = getchar();
  return x;
}
const int maxn = 3e5 + 10;
const int maxq = 5e5 + 10;
struct Node {
  int s[2], p, siz, v1, sum, v2, _s, tag1, tag2;
} tr[maxn * 2];
int n, q, tot, stk[maxn * 2];
inline void pushup(int x) {
  tr[x].siz = tr[tr[x].s[0]].siz + tr[tr[x].s[1]].siz + (x > n);
  tr[x].sum = tr[tr[x].s[0]].sum ^ tr[tr[x].s[1]].sum ^ tr[x].v1;
  tr[x]._s = tr[tr[x].s[0]]._s | tr[tr[x].s[1]]._s | (x > n && tr[x].v2 > 0);
}
inline void pushrev(int x) {
  swap(tr[x].s[0], tr[x].s[1]);
  tr[x].tag1 ^= 1;
}
inline void pushadd(int x) {
  tr[x]._s = tr[x].siz;
  if (x > n) tr[x].v2 = 1;
  tr[x].tag2 = 1;
}
inline void pushdown(int x) {
  if (tr[x].tag1) {
    pushrev(tr[x].s[0]), pushrev(tr[x].s[1]);
    tr[x].tag1 = 0;
  }
  if (tr[x].tag2) {
    pushadd(tr[x].s[0]), pushadd(tr[x].s[1]);
    tr[x].tag2 = 0;
  }
}
inline bool isroot(int x) {
  return tr[tr[x].p].s[0] != x && tr[tr[x].p].s[1] != x;
}
inline void rotate(int x) {
  int y = tr[x].p, z = tr[y].p, k = tr[y].s[1] == x;
  if (!isroot(y)) tr[z].s[tr[z].s[1] == y] = x;
  tr[x].p = z;
  tr[y].s[k] = tr[x].s[k ^ 1], tr[tr[x].s[k ^ 1]].p = y;
  tr[x].s[k ^ 1] = y, tr[y].p = x;
  pushup(y), pushup(x);
}
void splay(int x) {
  int top = 0, r = x;
  stk[++top] = r;
  while (!isroot(r)) stk[++top] = r = tr[r].p;
  while (top) pushdown(stk[top--]);
  while (!isroot(x)) {
    int y = tr[x].p, z = tr[y].p;
    if (!isroot(y)) rotate(tr[y].s[1] == x ^ tr[z].s[1] == y ? x : y);
    rotate(x);
  }
}
void access(int x) {
  int z = x;
  for (int y = 0; x; y = x, x = tr[x].p) {
    splay(x);
    tr[x].s[1] = y, pushup(x);
  }
  splay(z);
}
void makeroot(int x) { access(x), pushrev(x); }
int findroot(int x) {
  access(x);
  while (tr[x].s[0]) pushdown(x), x = tr[x].s[0];
  splay(x);
  return x;
}
void split(int x, int y) { makeroot(x), access(y); }
void link(int x, int y) {
  makeroot(x);
  if (findroot(y) != x) tr[x].p = y;
}
int main() {
  n = read(), q = read();
  tot = n;
  for (int i = 1; i <= n; i++) tr[i].siz = 1;
  for (int i = 1; i <= q; i++) {
    int u = read(), v = read(), w = read();
    makeroot(u);
    if (findroot(v) != u) {
      tot++, tr[tot].v1 = tr[tot].sum = w, tr[tot].siz = 1;
      link(u, tot), link(tot, v);
      puts("YES");
    } else {
      split(u, v);
      if (tr[v]._s > 0 || (tr[v].sum ^ w) != 1)
        puts("NO");
      else {
        pushadd(v);
        puts("YES");
      }
    }
  }
  return 0;
}
