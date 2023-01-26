#include <bits/stdc++.h>
constexpr int N = 10005;
int T, n;
bool f[N], g[N];
std::vector<int> ans;
bool query(int x, int y, int z) {
  std::cout << "? " << x << ' ' << y << ' ' << z << std::endl;
  bool res;
  std::cin >> res;
  return res;
}
void submit() {
  std::cout << "! " << ans.size();
  for (int i : ans) std::cout << ' ' << i;
  std::cout << std::endl;
}
int main() {
  std::ios::sync_with_stdio(false), std::cin.tie(nullptr);
  std::cin >> T;
  while (T--) {
    std::cin >> n;
    int x = 0, y = 0;
    for (int i = 1; i <= n / 3; ++i) {
      f[i] = query(i * 3 - 2, i * 3 - 1, i * 3);
      if (f[i]) {
        if (!x) x = i;
      } else {
        if (!y) y = i;
      }
    }
    bool a = query(y * 3 - 2, y * 3 - 1, x * 3 - 2),
         b = query(y * 3 - 2, y * 3 - 1, x * 3 - 1), c;
    if (!a && !b) {
      g[y * 3 - 2] = g[y * 3 - 1] = 1;
      bool A = query(y * 3 - 2, x * 3 - 2, x * 3 - 1),
           B = query(y * 3 - 2, x * 3 - 2, x * 3);
      g[x * 3 - 2] = g[x * 3 - 1] = g[x * 3] = 0;
      if (!A && !B)
        g[x * 3 - 2] = 1;
      else if (!A)
        g[x * 3 - 1] = 1;
      else if (!B)
        g[x * 3] = 1;
      int t = x * 3 - 2;
      if (g[t]) ++t;
      bool res = query(t, y * 3 - 1, y * 3);
      g[y * 3] = !res;
    } else {
      c = query(y * 3 - 2, y * 3 - 1, x * 3);
      g[x * 3 - 2] = !a;
      g[x * 3 - 1] = !b;
      g[x * 3] = !c;
      int t = x * 3 - 2;
      if (g[t]) ++t;
      g[y * 3 - 2] = g[y * 3 - 1] = g[y * 3] = 1;
      bool A = query(t, y * 3 - 2, y * 3 - 1), B = query(t, y * 3 - 2, y * 3);
      if (A && B)
        g[y * 3 - 2] = 0;
      else if (A)
        g[y * 3 - 1] = 0;
      else if (B)
        g[y * 3] = 0;
    }
    int p0 = x * 3 - 2;
    if (g[p0]) ++p0;
    int p1 = y * 3 - 2;
    if (!g[p1]) ++p1;
    for (int i = 1; i <= n / 3; ++i) {
      if (i == x || i == y) continue;
      if (f[i]) {
        bool A = query(p1, i * 3 - 2, i * 3 - 1),
             B = query(p1, i * 3 - 2, i * 3);
        g[i * 3 - 2] = g[i * 3 - 1] = g[i * 3] = 0;
        if (!A && !B)
          g[i * 3 - 2] = 1;
        else if (!A)
          g[i * 3 - 1] = 1;
        else if (!B)
          g[i * 3] = 1;
      } else {
        bool A = query(p0, i * 3 - 2, i * 3 - 1),
             B = query(p0, i * 3 - 2, i * 3);
        g[i * 3 - 2] = g[i * 3 - 1] = g[i * 3] = 1;
        if (A && B)
          g[i * 3 - 2] = 0;
        else if (A)
          g[i * 3 - 1] = 0;
        else if (B)
          g[i * 3] = 0;
      }
    }
    ans.clear();
    for (int i = 1; i <= n; ++i)
      if (g[i]) ans.push_back(i);
    submit();
  }
  return 0;
}
