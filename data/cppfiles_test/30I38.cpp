#include <bits/stdc++.h>
using namespace std;
const int dx[4] = {-1, 0, 0, 1};
const int dy[4] = {0, -1, 1, 0};
const int maxn = 150005;
const int maxm = 1000006;
const int oo = 1000000009;
const int mod = 14062008;
const long long base = 1000000000000000000;
int n, q, maxa, a[maxn], b[maxn], p[maxm], f[maxm];
bool d[maxm];
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
vector<int> getFac(int a) {
  vector<int> res(0);
  while (a > 1) {
    res.push_back(p[a]);
    while (p[a] == res.back()) a /= p[a];
  }
  return res;
}
bool check(int x, int y) {
  vector<int> facX = getFac(x);
  vector<int> facY = getFac(y);
  for (int i : facX)
    for (int j : facY)
      if (1LL * i * j <= maxa + 1 && d[i * j]) return true;
  return false;
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cin >> n >> q;
  for (int i = 1; i <= n; ++i) {
    cin >> a[i];
    b[i] = a[i] + 1;
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
  for (int i = 1; i <= n; ++i)
    for (int j = 2; j * j <= b[i]; ++j)
      if (b[i] % j == 0) {
        d[j] = true;
        d[b[i] / j] = true;
      }
  int root2 = root(2);
  int x, y;
  while (q--) {
    cin >> x >> y;
    int rootX = root(a[x]);
    int rootY = root(a[y]);
    if (rootX == rootY)
      cout << "0\n";
    else if ((rootX == root2) + (rootY == root2) == 1)
      cout << "1\n";
    else if (check(a[x], a[y]))
      cout << "1\n";
    else
      cout << "2\n";
  }
}
