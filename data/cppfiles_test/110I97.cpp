#include <bits/stdc++.h>
template <class t>
inline void read(t &s) {
  s = 0;
  signed f = 1;
  char c = getchar();
  while (!isdigit(c)) {
    if (c == '-') f = -1;
    c = getchar();
  }
  while (isdigit(c)) s = (s << 3) + (s << 1) + (c ^ 48), c = getchar();
  ;
  s *= f;
}
template <class t, class... A>
inline void read(t &x, A &...a) {
  read(x);
  read(a...);
}
template <class t>
inline void write(t x) {
  if (x < 0) putchar('-'), x = -x;
  static int buf[50], top = 0;
  while (x) buf[++top] = x % 10, x /= 10;
  if (!top) buf[++top] = 0;
  while (top) putchar(buf[top--] ^ '0');
}
inline void setIn(std::string s) {
  freopen(s.c_str(), "r", stdin);
  return;
}
inline void setOut(std::string s) {
  freopen(s.c_str(), "w", stdout);
  return;
}
inline void setIO(std::string s = "") {
  setIn(s + ".in");
  setOut(s + ".out");
  return;
}
template <class t>
inline bool ckmin(t &x, t y) {
  if (x > y) {
    x = y;
    return 1;
  }
  return 0;
}
template <class t>
inline bool ckmax(t &x, t y) {
  if (x < y) {
    x = y;
    return 1;
  }
  return 0;
}
inline int lowbit(int x) { return x & (-x); }
const int MaxN = 1e5 + 50;
struct Node {
  int x, y, c, bc;
} a[MaxN];
int n, m, K;
int s1[MaxN], s2[MaxN];
inline bool go() {
  std::memset(s1, 0, sizeof(int) * (m + 2));
  for (int i = (1); i <= (n); ++i) s1[a[i].x] += (a[i].c == 1);
  int pos = 0, ct = 0;
  while (ct < K) ct += s1[++pos];
  for (int _ = (0); _ <= (0); ++_) {
    std::memset(s2, 0, sizeof(int) * (m + 2));
    for (int i = (1); i <= (n); ++i) s2[a[i].x] += (a[i].c == 2);
    int p = pos - 1, c = 0;
    while (p < m && c < K) c += s2[++p];
    if (c < K) break;
    int cnt = 0;
    for (int i = (1); i <= (n); ++i) cnt += (a[i].c == 3 && a[i].x >= p);
    if (cnt >= K) return true;
  }
  std::memset(s2, 0, sizeof(int) * (m + 2));
  for (int i = (1); i <= (n); ++i)
    if (a[i].x >= pos) s2[a[i].y] += (a[i].c == 2);
  int p = 0, c = 0;
  while (p < m && c < K) c += s2[++p];
  if (c < K) return false;
  int cnt = 0;
  for (int i = (1); i <= (n); ++i)
    cnt += (a[i].c == 3 && a[i].x >= pos && a[i].y >= p);
  return cnt >= K;
}
inline void rotate() {
  for (int i = (1); i <= (n); ++i)
    std::swap(a[i].x, a[i].y), a[i].y = m - a[i].y + 1;
}
inline bool check(int k) {
  K = k;
  std::vector<int> p({1, 2, 3});
  do {
    for (int i = (1); i <= (n); ++i) a[i].c = p[a[i].bc - 1];
    for (int i = (0); i <= (4); ++i) {
      rotate();
      if (go()) return true;
    }
  } while (std::next_permutation((p).begin(), (p).end()));
  return false;
}
signed main(void) {
  read(n);
  for (int i = (1); i <= (n); ++i) read(a[i].x, a[i].y, a[i].bc);
  std::vector<int> dr;
  for (int i = (1); i <= (n); ++i) dr.push_back(a[i].x);
  std::sort((dr).begin(), (dr).end()),
      dr.erase(std::unique((dr).begin(), (dr).end()), dr.end());
  ckmax(m, (int)dr.size());
  for (int i = (1); i <= (n); ++i)
    a[i].x =
        std::lower_bound((dr).begin(), (dr).end(), a[i].x) - dr.begin() + 1;
  dr.clear();
  for (int i = (1); i <= (n); ++i) dr.push_back(a[i].y);
  std::sort((dr).begin(), (dr).end()),
      dr.erase(std::unique((dr).begin(), (dr).end()), dr.end());
  ckmax(m, (int)dr.size());
  for (int i = (1); i <= (n); ++i)
    a[i].y =
        std::lower_bound((dr).begin(), (dr).end(), a[i].y) - dr.begin() + 1;
  int l = 1, r = n / 3, mid, ans = 1;
  while (l <= r) {
    mid = (l + r) >> 1;
    if (check(mid))
      ans = mid, l = mid + 1;
    else
      r = mid - 1;
  }
  write(ans * 3), putchar('\n');
  return 0;
}
