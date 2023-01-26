#include <bits/stdc++.h>
template <class T>
inline T read() {
  T r = 0, f = 0;
  char c;
  while (!isdigit(c = getchar())) f |= (c == '-');
  while (isdigit(c)) r = (r << 1) + (r << 3) + (c ^ 48), c = getchar();
  return f ? -r : r;
}
template <class T>
inline void swap(T &a, T &b) {
  T c = a;
  a = b;
  b = c;
}
int n, m, B, p[101101], r[101101], jump[101101];
inline void Jump(int x) {
  int X = x;
  for (int i = 1; i <= B; i++) X = p[X];
  for (int i = 1; i <= B; i++) jump[x] = X, x = r[x], X = r[X];
}
inline void Modify() {
  int x = read<int>();
  int y = read<int>();
  swap(r[p[x]], r[p[y]]);
  swap(p[x], p[y]);
  Jump(x), Jump(y);
}
inline void work() {
  int opt = read<int>();
  if (opt == 1) return Modify();
  int x = read<int>(), k = read<int>();
  while (k >= B) k -= B, x = jump[x];
  while (k) x = p[x], k--;
  printf("%d\n", x);
}
int main() {
  n = read<int>();
  m = read<int>();
  B = sqrt(n);
  for (int i = 1; i <= n; i++) p[i] = read<int>(), r[p[i]] = i;
  for (int i = 1; i <= n; i++) {
    jump[i] = i;
    for (int j = 1; j <= B; j++) jump[i] = p[jump[i]];
  }
  for (int t = 1; t <= m; t++) work();
  return 0;
}
