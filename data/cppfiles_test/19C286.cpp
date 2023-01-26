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
std::vector<int> s, t;
int a[20], b[20];
int T, n;
bool flag;
void dfs(int x) {
  if (flag) return;
  if (x > n) {
    if (s.empty() && t.empty()) return;
    int s1 = 0, s2 = 0;
    for (auto i : s) s1 += i;
    for (auto i : t) s2 += i;
    if (s1 == s2) flag = true;
    return;
  }
  dfs(x + 1);
  s.push_back(a[x]);
  dfs(x + 1);
  s.pop_back();
  t.push_back(a[x]);
  dfs(x + 1);
  t.pop_back();
}
int main() {
  read(T);
  while (T--) {
    flag = false;
    s.clear(), t.clear();
    read(n);
    for (int i = 1; i <= n; ++i) read(a[i]);
    dfs(1);
    puts(flag ? "YES" : "NO");
  }
  return 0;
}
