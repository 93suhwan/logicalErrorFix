#include <bits/stdc++.h>
using namespace std;
inline long long read(void) {
  register int x = 0;
  register short sgn = 1;
  register char c = getchar();
  while (c < 48 || 57 < c) {
    if (c == 45) sgn = 0;
    c = getchar();
  }
  while (47 < c && c < 58) {
    x = (x << 3) + (x << 1) + c - 48;
    c = getchar();
  }
  return sgn ? x : -x;
}
inline void write(long long x) {
  if (x < 0) putchar('-'), x = -x;
  if (x > 9) write(x / 10);
  putchar(x % 10 + '0');
}
const int N = 1e5 + 10;
int fa1[N], fa2[N];
int find(int *fa, int x) {
  if (fa[x] == x)
    return x;
  else
    return fa[x] = find(fa, fa[x]);
}
int main() {
  int n = read(), m1 = read(), m2 = read();
  for (int i = 1; i <= n; i++) fa1[i] = i, fa2[i] = i;
  for (int i = 1; i <= m1; i++) {
    int a = read(), b = read();
    if (find(fa1, a) != find(fa1, b)) fa1[find(fa1, a)] = find(fa1, b);
  }
  for (int i = 1; i <= m2; i++) {
    int a = read(), b = read();
    if (find(fa2, a) != find(fa2, b)) fa2[find(fa2, a)] = find(fa2, b);
  }
  vector<pair<int, int> > res;
  for (int i = 2; i <= n; i++) {
    if (find(fa1, i) != find(fa1, 1) && find(fa2, i) != find(fa2, 1)) {
      res.push_back({1, i});
      fa1[find(fa1, 1)] = find(fa1, i);
      fa2[find(fa2, 1)] = find(fa2, i);
    }
  }
  set<int> s1, s2;
  for (int i = 2; i <= n; i++) {
    if (find(fa1, i) != find(fa1, 1)) s1.insert(find(fa1, i));
    if (find(fa2, i) != find(fa2, 1)) s2.insert(find(fa2, i));
  }
  for (auto i = s1.begin(), j = s2.begin(); i != s1.end() && j != s2.end();
       i++, j++) {
    res.push_back({(*i), (*j)});
  }
  printf("%d\n", res.size());
  for (auto i : res) {
    printf("%d %d\n", i.first, i.second);
  }
  return 0;
}
