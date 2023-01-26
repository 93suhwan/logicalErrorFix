#include <bits/stdc++.h>
template <class T>
inline void read(T &x) {
  x = 0;
  int f = 0;
  char ch = getchar();
  while (!isdigit(ch)) {
    f |= ch == '-';
    ch = getchar();
  }
  while (isdigit(ch)) {
    x = (x << 1) + (x << 3) + (ch ^ 48);
    ch = getchar();
  }
  x = f ? -x : x;
  return;
}
std::vector<std::pair<int, int>> ans;
std::vector<int> a, b;
int f1[100010], f2[100010];
int n, m1, m2;
int find1(int x) { return f1[x] == x ? x : f1[x] = find1(f1[x]); }
int find2(int x) { return f2[x] == x ? x : f2[x] = find2(f2[x]); }
void link1(int u, int v) {
  int fu = find1(u), fv = find1(v);
  if (fu != fv) f1[fu] = fv;
  return;
}
void link2(int u, int v) {
  int fu = find2(u), fv = find2(v);
  if (fu != fv) f2[fu] = fv;
  return;
}
int main() {
  read(n), read(m1), read(m2);
  for (int i = 1; i <= n; ++i) f1[i] = f2[i] = i;
  for (int i = 1, u, v; i <= m1; ++i) {
    read(u), read(v);
    link1(u, v);
  }
  for (int i = 1, u, v; i <= m2; ++i) {
    read(u), read(v);
    link2(u, v);
  }
  for (int i = 1; i <= n; ++i) {
    int u1 = find1(1), v1 = find1(i), u2 = find2(1), v2 = find2(i);
    if (u1 != v1 && u2 != v2) {
      link1(1, i), link2(1, i);
      ans.emplace_back(i, 1);
    }
  }
  for (int i = 1; i <= n; ++i) {
    int u1 = find1(1), v1 = find1(i), u2 = find2(1), v2 = find2(i);
    if (u1 != v1) a.push_back(i), link1(1, i);
    if (u2 != v2) b.push_back(i), link2(1, i);
  }
  printf("%d\n", ans.size() + std::min(a.size(), b.size()));
  for (auto i : ans) printf("%d %d\n", i.first, i.second);
  for (int i = 0; i < std::min(a.size(), b.size()); ++i)
    printf("%d %d\n", a[i], b[i]);
  return 0;
}
