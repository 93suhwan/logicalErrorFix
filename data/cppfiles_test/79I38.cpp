#include <bits/stdc++.h>
char ibuf[1 << 15], *p1, *p2;
struct {
  inline int rint() {
    register char c, f = 0;
    while ((c = (p1 == p2 && (p2 = (p1 = ibuf) + fread(ibuf, 1, 1 << 15, stdin),
                              p1 == p2)
                     ? EOF
                     : *p1++)) < 48 ||
           c > 57)
      f |= c == '-';
    register int unsigned a = c & 15;
    while ((c = (p1 == p2 && (p2 = (p1 = ibuf) + fread(ibuf, 1, 1 << 15, stdin),
                              p1 == p2)
                     ? EOF
                     : *p1++)) >= 48 &&
           c <= 57)
      a = a * 10 + (c & 15);
    return f ? ~a + 1 : a;
  }
  inline long long rll() {
    register char c, f = 0;
    while ((c = (p1 == p2 && (p2 = (p1 = ibuf) + fread(ibuf, 1, 1 << 15, stdin),
                              p1 == p2)
                     ? EOF
                     : *p1++)) < 48 ||
           c > 57)
      f |= c == '-';
    register uint64_t a = c & 15;
    while ((c = (p1 == p2 && (p2 = (p1 = ibuf) + fread(ibuf, 1, 1 << 15, stdin),
                              p1 == p2)
                     ? EOF
                     : *p1++)) >= 48 &&
           c <= 57)
      a = a * 10 + (c & 15);
    return f ? ~a + 1 : a;
  }
  inline operator int() { return rint(); }
  inline operator long long() { return rll(); }
} g90;
const int N = 333333;
int a[N], fa[N];
std::vector<std::pair<int, int> > e[N << 3];
int n;
inline int ID(const int& i) { return i + 4 * n; }
inline int ID2(const int& i) { return i + 5 * n; }
namespace SegTree {
const int NODE = N << 2;
void build(const int& id = 1, const int& l = 1, const int& r = n) {
  if (l == r) {
    e[id].emplace_back(ID(l), 0);
    return;
  }
  int mid = (l + r) / 2;
  build((id << 1), l, mid);
  build((id << 1 | 1), (mid) + 1, r);
  e[id].emplace_back((id << 1), 0), e[id].emplace_back((id << 1 | 1), 0);
}
void add(const int& ql, const int& qr, const int& v, const int& id = 1,
         const int& l = 1, const int& r = n) {
  if (ql > qr) return;
  if (qr < l || r < ql) return;
  if (ql <= l && r <= qr) return e[ID2(v)].emplace_back(id, 1);
  int mid = (l + r) / 2;
  add(ql, qr, v, (id << 1), l, mid);
  add(ql, qr, v, (id << 1 | 1), (mid) + 1, r);
}
}  // namespace SegTree
signed main() {
  n = g90;
  SegTree::build();
  for (int i = 1; i <= n; ++i) {
    a[i] = g90;
  }
  for (int i = 1; i <= n; ++i) {
    int b = g90;
    fa[i] = i + b;
    e[ID(i)].emplace_back(ID2(fa[i]), 0);
  }
  for (int i = 1; i <= n; ++i) {
    if (a[i] == i) e[ID2(i)].emplace_back(0, 1), a[i]--;
    SegTree::add(i - a[i], i, i);
  }
  std::deque<int> q(1, ID2(n));
  static int vis[N << 3], dis[N << 3], frm[N << 3];
  while (!q.empty()) {
    int u = q.front();
    q.pop_front();
    vis[u] = 1;
    for (auto tmp : e[u]) {
      int v = tmp.first, w = tmp.second;
      if (!vis[v]) {
        dis[v] = dis[u] + w;
        frm[v] = u;
        if (v == 0) {
          printf("%d\n", dis[0]);
          int cur = 0;
          std::stack<int> st;
          while (cur != ID2(n)) {
            st.push(cur);
            cur = frm[cur];
          }
          while (!st.empty()) {
            if (st.top() > 4 * n && st.top() <= 5 * n)
              printf("%d ", st.top() - 4 * n);
            st.pop();
          }
          printf("%d\n", 0);
          return 0;
        }
        if (w)
          q.push_back(v);
        else
          q.push_front(v);
      }
    }
  }
  puts("-1");
}
