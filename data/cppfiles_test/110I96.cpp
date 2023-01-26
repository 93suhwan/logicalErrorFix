#include <bits/stdc++.h>
using namespace std;
struct node {
  int x, y, c;
  bool operator<(const node &t) const { return x < t.x; }
};
node st[100000 + 1];
bool cmp(node a, node b) { return a.y < b.y; }
int n, ans, k1[100000 + 1], k2[100000 + 1], length1, length2;
struct bit {
  int c[100000 + 1];
  void clear() {
    for (int i = 1; i <= n; ++i) c[i] = 0;
    return;
  }
  int lowbit(int x) { return x & (-x); }
  void add(int x, int d) {
    for (; x <= n; x += lowbit(x)) c[x] += d;
    return;
  }
  int Sum(int x) {
    int res = 0;
    for (; x >= 1; x -= lowbit(x)) res += c[x];
    return res;
  }
  int query(int l, int r) { return Sum(r) - Sum(l - 1); }
};
bit T1[3], T2[3];
int Query1(int c1, int c2) {
  int x = 0;
  for (int i = log(n) / log(2); i >= 0; --i)
    if (x + (1 << i) <= n &&
        T1[c1].Sum(x + (1 << i)) <= T1[c2].query(x + (1 << i), n))
      x += (1 << i);
  return max(T1[c1].Sum(x), T1[c2].query(x + 1, n));
}
int Query2(int c1, int c2) {
  int x = 0;
  for (int i = log(n) / log(2); i >= 0; --i)
    if (x + (1 << i) <= n &&
        T2[c1].Sum(x + (1 << i)) <= T2[c2].query(x + (1 << i), n))
      x += (1 << i);
  return max(T2[c1].Sum(x), T2[c2].query(x + 1, n));
}
int read() {
  char c = 0;
  int sum = 0, f = 1;
  while ((c < '0' || c > '9') && c != '-') c = getchar();
  if (c == '-') c = getchar(), f = -1;
  while ('0' <= c && c <= '9') sum = sum * 10 + c - '0', c = getchar();
  return sum * f;
}
int main() {
  n = read();
  for (int i = 1; i <= n; ++i)
    st[i].x = read(), st[i].y = read(), st[i].c = read() - 1,
    k1[++length1] = st[i].x, k2[++length2] = st[i].y;
  sort(k1 + 1, k1 + length1 + 1),
      length1 = unique(k1 + 1, k1 + length1 + 1) - k1 - 1;
  sort(k2 + 1, k2 + length2 + 1),
      length2 = unique(k2 + 1, k2 + length2 + 1) - k2 - 1;
  for (int i = 1; i <= n; ++i)
    st[i].x = lower_bound(k1 + 1, k1 + length1 + 1, st[i].x) - k1,
    st[i].y = lower_bound(k2 + 1, k2 + length2 + 1, st[i].y) - k2;
  sort(st + 1, st + n + 1);
  for (int i = 1; i <= n; ++i) T2[st[i].c].add(st[i].y, 1);
  int ps1 = 0, ps2 = 0;
  for (int i = 1; i <= length1; ++i) {
    while (ps1 + 1 <= n && st[ps1 + 1].x <= i)
      ps1++, T1[st[ps1].c].add(st[ps1].y, 1);
    while (ps2 + 1 <= n && st[ps2 + 1].x < i)
      ps2++, T2[st[ps2].c].add(st[ps2].y, -1);
    ans = max(ans, min(max(Query1(0, 1), Query1(1, 0)), T2[2].Sum(n)));
    ans = max(ans, min(max(Query1(0, 2), Query1(2, 0)), T2[1].Sum(n)));
    ans = max(ans, min(max(Query1(1, 2), Query1(2, 1)), T2[0].Sum(n)));
    ans = max(ans, min(max(Query2(0, 1), Query2(1, 0)), T1[2].Sum(n)));
    ans = max(ans, min(max(Query2(0, 2), Query2(2, 0)), T1[1].Sum(n)));
    ans = max(ans, min(max(Query2(1, 2), Query2(2, 1)), T1[0].Sum(n)));
  }
  sort(st + 1, st + n + 1, cmp), ps1 = 0, ps2 = 0;
  for (int i = 0; i <= 2; ++i) T1[i].clear(), T2[i].clear();
  for (int i = 1; i <= n; ++i) T2[st[i].c].add(st[i].x, 1);
  for (int i = 1; i <= length2; ++i) {
    while (ps1 + 1 <= n && st[ps1 + 1].y <= i)
      ps1++, T1[st[ps1].c].add(st[ps1].x, 1);
    while (ps2 + 1 <= n && st[ps2 + 1].y < i)
      ps2++, T2[st[ps2].c].add(st[ps2].x, -1);
    ans = max(ans, min(max(Query1(0, 1), Query1(1, 0)), T2[2].Sum(n)));
    ans = max(ans, min(max(Query1(0, 2), Query1(2, 0)), T2[1].Sum(n)));
    ans = max(ans, min(max(Query1(1, 2), Query1(2, 1)), T2[0].Sum(n)));
    ans = max(ans, min(max(Query2(0, 1), Query2(1, 0)), T1[2].Sum(n)));
    ans = max(ans, min(max(Query2(0, 2), Query2(2, 0)), T1[1].Sum(n)));
    ans = max(ans, min(max(Query2(1, 2), Query2(2, 1)), T1[0].Sum(n)));
  }
  printf("%d\n", ans * 3);
  return 0;
}
