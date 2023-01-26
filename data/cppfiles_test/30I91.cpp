#include <bits/stdc++.h>
using namespace std;
const int dx[4] = {-1, 0, 0, 1};
const int dy[4] = {0, -1, 1, 0};
const int maxn = 150005;
const int maxm = 1000006;
const int oo = 1000000009;
const int mod = 14062008;
const long long base = 1000000000000000000;
int n, q, maxa, a[maxn], p[maxm], f[maxm];
map<int, map<int, bool> > m;
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
vector<int> factor(int a) {
  vector<int> res(0);
  while (a > 1) {
    res.push_back(p[a]);
    while (p[a] == res.back()) a /= p[a];
  }
  return res;
}
bool check(int x, int y) {
  vector<int> facX = factor(x);
  vector<int> facY = factor(y);
  for (int i : facX)
    for (int j : facY)
      if (m[root(i)][root(j)]) return true;
  return false;
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cin >> n >> q;
  for (int i = 1; i <= n; ++i) {
    cin >> a[i];
    maxa = (maxa > a[i] + 1 ? maxa : a[i] + 1);
  }
  for (int i = 2; i * i <= maxa; ++i)
    if (p[i] == 0)
      for (int j = i * i; j <= maxa; j += i)
        if (p[j] == 0) p[j] = i;
  for (int i = 1; i <= maxa; ++i) {
    if (p[i] == 0) p[i] = i;
    f[i] = -1;
  }
  for (int i = 1; i <= n; ++i) {
    vector<int> facA = factor(a[i]);
    vector<int> facB = factor(a[i] + 1);
    merge(a[i], facA[0]);
    for (int i = 0; i <= int(facA.size() - 2); ++i) merge(facA[i], facA[i + 1]);
    for (int i : facA)
      for (int j : facB) {
        int rootI = root(i);
        int rootJ = root(j);
        m[rootI][rootJ] = true;
        m[rootJ][rootI] = true;
      }
    for (int i = 0; i <= int(facB.size() - 2); ++i)
      for (int j = i + 1; j <= int(facB.size() - 1); ++j) {
        int rootI = root(facB[i]);
        int rootJ = root(facB[j]);
        m[rootI][rootJ] = true;
        m[rootJ][rootI] = true;
      }
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
