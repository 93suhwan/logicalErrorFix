#include <bits/stdc++.h>
using namespace std;
inline int read() {
  int x = 0, f = 0;
  char ch = getchar();
  while (!isdigit(ch)) f |= ch == '-', ch = getchar();
  while (isdigit(ch)) x = 10 * x + ch - '0', ch = getchar();
  return f ? -x : x;
}
template <class T>
void print(T x) {
  if (x < 0) putchar('-'), x = -x;
  if (x >= 10) print(x / 10);
  putchar(x % 10 + '0');
}
template <class T>
void print(T x, char let) {
  print(x), putchar(let);
}
template <class T1, class T2>
void ckmin(T1& x, T2 y) {
  if (x > y) x = y;
}
template <class T1, class T2>
void ckmax(T1& x, T2 y) {
  if (x < y) x = y;
}
const int N = 500005;
int p[N], a[N], n, m, q;
int b[N];
vector<pair<int, int> > ask;
pair<int, int> c[N];
int f[N], sz[N];
long long sum[N], ans[N];
int find(int x) { return f[x] == x ? x : f[x] = find(f[x]); }
void sol() {
  iota(f + 1, f + n + m + 1, 1);
  long long res = 0;
  int cur = 1;
  for (int i = (1); i <= (n + m); i++) {
    if (p[i] <= n) sz[i] = 1, res += b[i];
    sum[i] = sum[i - 1] + b[i];
  }
  for (auto it : ask) {
    int k = it.first, id = it.second;
    while (cur < n + m && c[cur].first <= k) {
      int u = c[cur].second, v = c[cur].second + 1;
      v = find(v);
      res -= sum[u] - sum[u - sz[u]];
      res -= sum[v] - sum[v - sz[v]];
      sz[v] += sz[u], f[u] = v;
      res += sum[v] - sum[v - sz[v]];
      cur++;
    }
    ans[id] = res;
  }
}
int main() {
  n = read(), m = read(), q = read();
  iota(p + 1, p + n + m + 1, 1);
  for (int i = (1); i <= (n + m); i++) a[i] = read();
  sort(p + 1, p + n + m + 1, [&](int x, int y) { return a[x] < a[y]; });
  for (int i = (1); i <= (n + m); i++) b[i] = a[p[i]];
  for (int i = (2); i <= (n + m); i++) c[i] = {b[i] - b[i - 1], i - 1};
  for (int i = (1); i <= (n + m); i++) c[i] = c[i + 1];
  sort(c + 1, c + n + m);
  for (int i = (1); i <= (q); i++) {
    int x = read();
    ask.push_back({x, i});
  }
  sort(ask.begin(), ask.end());
  sol();
  for (int i = (1); i <= (q); i++) print(ans[i], '\n');
  return 0;
}
