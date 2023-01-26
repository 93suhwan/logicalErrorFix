#include <bits/stdc++.h>
using namespace std;
template <typename T>
void read(T &res) {
  bool flag = false;
  char ch;
  while (!isdigit(ch = getchar())) (ch == '-') && (flag = true);
  for (res = ch - 48; isdigit(ch = getchar());
       res = (res << 1) + (res << 3) + ch - 48)
    ;
  flag && (res = -res);
}
const int N = 1e5 + 700;
int a[N];
int check(int x, int y, int pos) {
  a[pos] = x & y;
  a[pos + 1] = x & y;
  return x & y;
}
int prime[100000], minprime[100000];
void euler(int n) {
  int c = 0, i, j;
  for (i = 2; i <= n; i++) {
    if (!minprime[i]) prime[++c] = i, minprime[i] = i;
    for (j = 1; j <= c && i * prime[j] <= n; j++) {
      minprime[i * prime[j]] = prime[j];
      if (i % prime[j] == 0) break;
    }
  }
}
map<pair<int, int>, int> vis;
map<pair<int, int>, int> fuck;
void pre(int n) {
  vis.clear();
  for (int i = 1; i <= n - 1; i++) {
    vis[make_pair(i, i + 1)] = 1;
    fuck[make_pair(i + 1, i)] = 1;
  }
}
int n, m1, m2;
int fa1[N], fa2[N];
inline void init() {
  for (int i = 1; i <= n; i++) {
    fa1[i] = fa2[i] = i;
  }
}
int find1(int x) {
  if (x == fa1[x])
    return x;
  else
    return find1(fa1[x]);
}
int find2(int x) {
  if (x == fa2[x])
    return x;
  else
    return find2(fa2[x]);
}
inline int get(int *fa, int x) {
  return fa[x] == x ? x : fa[x] = get(fa, fa[x]);
}
inline void merge(int *fa, int x, int y) { fa[get(fa, x)] = get(fa, y); }
signed main() {
  read(n);
  read(m1);
  read(m2);
  init();
  pre(n);
  for (int i = 1; i <= m1; i++) {
    int u, v;
    read(u);
    read(v);
    int ff = find1(u);
    int vv = find1(v);
    merge(fa1, u, v);
  }
  for (int i = 1; i <= m2; i++) {
    int u, v;
    read(u);
    read(v);
    merge(fa2, u, v);
    int ff = find2(u);
    int vv = find2(v);
  }
  int fkk = min(n - m1 - 1, n - m2 - 1);
  printf("%d\n", fkk);
  if (fkk == 0) return 0;
  for (int i = 1; i <= n; i++) {
    for (int j = i + 1; j <= n; j++) {
      if (find1(i) != find1(j) && find2(i) != find2(j)) {
        printf("%d %d\n", j, i);
        fkk--;
        if (fkk == 0) return 0;
        merge(fa1, i, j), merge(fa2, i, j);
      }
    }
  }
  return 0;
}
