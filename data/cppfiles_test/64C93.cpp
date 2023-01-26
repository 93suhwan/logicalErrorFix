#include <bits/stdc++.h>
using namespace std;
const int INF = 0x3f3f3f3f;
const long long mod = 1e9 + 7;
template <class A>
void read(A& a) {
  a = 0;
  int c = getchar(), f = 0;
  for (; !isdigit(c); c = getchar()) f |= c == '-';
  for (; isdigit(c); c = getchar()) a = a * 10 + (c ^ 48);
  if (f) a = -a;
}
template <class A, class... B>
void read(A& a, B&... b) {
  read(a);
  read(b...);
}
template <class T>
inline void print(T x) {
  if (x < 0) x = ~x + 1, putchar('-');
  if (x > 9) print(x / 10);
  putchar(x % 10 + '0');
}
const int N = 1e5 + 10;
int n, m1, m2;
int f1[N], f2[N];
void init() {
  for (int i = 1; i <= n; i++) f1[i] = f2[i] = i;
}
int finds(int* f, int x) {
  if (x == f[x])
    return x;
  else
    return f[x] = finds(f, f[x]);
}
void unio(int* f, int x, int y) {
  int fx = finds(f, x), fy = finds(f, y);
  if (fx < fy) f[fy] = fx;
  if (fy < fx) f[fx] = fy;
}
int main() {
  read(n, m1, m2);
  init();
  for (int i = 1, x, y; i <= m1; i++) {
    read(x, y);
    unio(f1, x, y);
  }
  for (int i = 1, x, y; i <= m2; i++) {
    read(x, y);
    unio(f2, x, y);
  }
  vector<pair<int, int> > ans;
  vector<int> v1, v2;
  for (int i = 1; i <= n; i++) {
    if (finds(f2, i) != 1 && finds(f1, i) != 1) {
      unio(f2, i, 1), unio(f1, i, 1);
      ans.push_back({1, i});
    }
    if (finds(f2, i) != 1) v1.push_back(i);
    if (finds(f1, i) != 1) v2.push_back(i);
  }
  for (auto i : v1) {
    if (finds(f2, i) == 1) continue;
    while (v2.size()) {
      int u = v2.back();
      v2.pop_back();
      if (finds(f1, u) == 1) continue;
      ans.push_back({i, u});
      unio(f2, i, u), unio(f1, i, u);
      break;
    }
  }
  printf("%d\n", ans.size());
  for (auto t : ans) printf("%d %d\n", t.first, t.second);
}
