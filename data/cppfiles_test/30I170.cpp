#include <bits/stdc++.h>
using namespace std;
const int dx[4] = {-1, 0, 0, 1};
const int dy[4] = {0, -1, 1, 0};
const int maxn = 150005;
const int maxa = 1000006;
const int oo = 1000000009;
const int mod = 14062008;
const long long base = 1000000000000000000;
int n, q, a[maxn], p[maxa], f[maxa];
int root(int x) { return (f[x] < 0 ? x : f[x] = root(f[x])); }
void merge(int x, int y) {
  x = root(x);
  y = root(y);
  if (x != y) {
    if (f[y] < f[x]) swap(x, y);
    f[x] += f[y];
    f[y] = x;
  }
}
void factor(int a) {
  int preP = a;
  while (a > 1) {
    int minP = p[a];
    while (p[a] == minP) a /= minP;
    merge(minP, preP);
    preP = minP;
  }
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int maxa = 0;
  cin >> n >> q;
  for (int i = 1; i <= n; ++i) {
    cin >> a[i];
    maxa = (maxa > a[i] ? maxa : a[i]);
  }
  for (int i = 2; i * i <= maxa; ++i)
    if (p[i] == 0)
      for (int j = i * i; j <= maxa; j += i)
        if (p[j] == 0) p[j] = i;
  for (int i = 1; i <= maxa; ++i) {
    if (p[i] == 0) p[i] = i;
    f[i] = -1;
  }
  for (int i = 1; i <= n; ++i) factor(a[i]);
  int root2 = root(2);
  int x, y;
  while (q--) {
    cin >> x >> y;
    if (root(a[x]) == root(a[y]))
      cout << "0\n";
    else
      cout << (root(a[x]) != root2) + (root(a[y]) != root2) << '\n';
  }
}
