#include <bits/stdc++.h>
template <class T>
inline void rd(T& x) {
  x = 0;
  char ch = getchar();
  bool f = 0;
  while (ch < '0' || ch > '9') f |= (ch == '-'), ch = getchar();
  while (ch >= '0' && ch <= '9') x = x * 10 + (ch & 15), ch = getchar();
  f && (x = -x);
}
template <class T>
inline void Cmin(T& x, const T y) {
  x = x > y ? y : x;
}
template <class T>
inline void Cmax(T& x, const T y) {
  x = x > y ? x : y;
}
template <class T>
inline std::vector<T> ils(T* s, T* t) {
  std::vector<T> res;
  for (; s != t; s++) res.emplace_back(*s);
  return res;
}
int n, a[200100], cnt[32];
inline void Mcase() {
  rd(n);
  for (int i = 1; i <= n; ++i) rd(a[i]);
  if (std::count((a) + (1), (a) + (n) + 1, 0) == n) {
    for (int i = 1; i <= n; ++i) printf("%d ", i);
    return;
  }
  int mx = 0;
  for (int i = 1; i <= n; ++i)
    for (int x = a[i], c = 0; x; x >>= 1) cnt[c] += (x & 1), Cmax(mx, c), c++;
  int X = 1e9;
  for (int i = 0; i < 32; ++i)
    if (cnt[i]) {
      Cmin(X, cnt[i]);
      if (cnt[i] & 1) return puts("1"), void();
    }
  std::vector<int> res;
  for (int i = 1; i <= X; ++i)
    if (X % i == 0) res.emplace_back(i);
  for (int i : res) printf("%d ", i);
  puts("");
  for (int i = 0; i < 32; ++i) cnt[i] = 0;
}
signed main() {
  int KNS;
  rd(KNS);
  while (KNS--) Mcase();
}
