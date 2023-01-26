#include <bits/stdc++.h>
using namespace std;
template <class T>
void _R(T &x) {
  cin >> x;
}
void _R(int &x) { scanf("%d", &x); }
void _R(long long &x) { scanf("%lld", &x); }
void _R(double &x) { scanf("%lf", &x); }
void _R(char &x) { scanf("%c", &x); }
void _R(char *x) { scanf("%s", x); }
template <class T, class U>
void _R(pair<T, U> &x) {
  _R(x.first);
  _R(x.second);
}
void R() {}
template <class T, class... U>
void R(T &head, U &...tail) {
  _R(head);
  R(tail...);
}
template <class T>
void _W(const T &x) {
  cout << x;
}
void _W(const unsigned int &x) { printf("%u", x); }
void _W(const int &x) { printf("%d", x); }
void _W(const long long &x) { printf("%lld", x); }
void _W(const double &x) { printf("%.12f", x); }
void _W(const char &x) { putchar(x); }
void _W(const char *x) { printf("%s", x); }
template <class T, class U>
void _W(const pair<T, U> &x) {
  _W(x.first);
  putchar(' ');
  _W(x.second);
}
template <class T>
void _W(const vector<T> &x) {
  for (auto i = x.begin(); i != x.end(); _W(*i++))
    if (i != x.cbegin()) putchar(' ');
}
void W() {}
template <class T, class... U>
void W(const T &head, const U &...tail) {
  _W(head);
  putchar(sizeof...(tail) ? ' ' : '\n');
  W(tail...);
}
void _E() {}
template <class T, class... U>
void _E(const T &head, const U &...tail) {
  _W(head);
  printf(sizeof...(tail) ? " " : " <<-\n");
  _E(tail...);
}
void E() {}
template <class T, class... U>
void E(const T &head, const U &...tail) {
  printf(">> ");
  _W(head);
  printf(sizeof...(tail) ? " " : " <<-\n");
  _E(tail...);
}
const int MAXN = 1000006;
int mn[MAXN << 2];
int tag[MAXN << 2];
void build(int i, int l, int r) {
  mn[i] = tag[i] = 0;
  if (l == r) return;
  int m = l + r >> 1;
  build(i << 1, l, m);
  build(i << 1 | 1, m + 1, r);
}
void pushdown(int i) {
  if (tag[i]) {
    mn[i << 1] += tag[i];
    mn[i << 1 | 1] += tag[i];
    tag[i << 1] += tag[i];
    tag[i << 1 | 1] += tag[i];
    tag[i] = 0;
  }
}
void update(int i, int l, int r, int L, int R, long long v) {
  if (L <= l && r <= R) {
    mn[i] += v;
    tag[i] += v;
    return;
  }
  pushdown(i);
  int m = l + r >> 1;
  if (L <= m) update(i << 1, l, m, L, R, v);
  if (m < R) update(i << 1 | 1, m + 1, r, L, R, v);
  mn[i] = min(mn[i << 1], mn[i << 1 | 1]);
}
long long query(int i, int l, int r, int p) {
  if (l == r) return mn[i];
  pushdown(i);
  int m = l + r >> 1;
  if (p <= m)
    return query(i << 1, l, m, p);
  else
    return query(i << 1 | 1, m + 1, r, p);
}
int n, m;
struct node {
  int l, r, w;
  bool operator<(const node &p) const { return w < p.w; }
};
node q[300005];
int main() {
  R(n, m);
  for (int i = 1; i <= n; ++i) {
    R(q[i].l, q[i].r, q[i].w);
  }
  sort(q + 1, q + n + 1);
  build(1, 1, m - 1);
  int ans = 0x3f3f3f3f;
  for (int l = 1, r = 0; l <= n; ++l) {
    while (mn[1] == 0 && r < n) {
      ++r;
      update(1, 1, m - 1, q[r].l, q[r].r - 1, 1);
    }
    if (mn[1]) ans = min(ans, q[r].w - q[l].w);
    update(1, 1, m - 1, q[l].l, q[l].r - 1, -1);
  }
  W(ans);
  return 0;
}
