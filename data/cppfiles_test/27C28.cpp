#include <bits/stdc++.h>
using namespace std;
bool Safe(int r, int c, int n, int m) {
  return ((r < n) && (c < m) && (r >= 0) && (c >= 0));
}
class dsu {
 public:
  pair<int, int>* parr;
  dsu(int n) {
    parr = new pair<int, int>[n + 1];
    for (int i = 0; i <= n; i += 1) parr[i] = {i, 1};
  }
  pair<int, int> Findparr(int x) {
    if (x == parr[x].first) return parr[x];
    return Findparr(parr[x].first);
  }
  void Union(int x, int y) {
    if (parr[x].first == parr[y].first) return;
    pair<int, int> u = Findparr(x);
    pair<int, int> v = Findparr(y);
    parr[u.first].first = v.first;
    parr[v.first].second += parr[u.first].second;
  }
};
int gcd(int a, int b) {
  if (b == a) return a;
  return gcd(b, a % b);
}
int FindSolutions(int a, int b, int& x, int& y) {
  if (b == 0) {
    x = 1;
    y = 0;
    return a;
  }
  int x2, y2;
  int g = FindSolutions(b, a % b, x2, y2);
  x = y2;
  y = x2 - y2 * (a / b);
  return g;
}
int Fp(int x, int* parr) {
  if (x == parr[x]) return x;
  parr[x] = Fp(parr[x], parr);
  return parr[x];
}
void Unite(int x, int y, int* parr, long long* size) {
  if (parr[x] == parr[y]) return;
  int a = Fp(x, parr);
  int b = Fp(y, parr);
  if (size[a] < size[b]) swap(a, b);
  parr[b] = a;
  size[a] += size[b];
}
void solve() {
  long long n, m, k;
  cin >> n >> m >> k;
  if ((m < n - 1) || (m > (n * (n - 1)) / 2)) {
    cout << "NO\n";
    return;
  }
  if (n == 1) {
    if (k > 1)
      cout << "YES\n";
    else
      cout << "NO\n";
    return;
  }
  if (m == (n * (n - 1)) / 2) {
    if (k > 2)
      cout << "YES\n";
    else
      cout << "NO\n";
    return;
  }
  if (k > 3)
    cout << "YES\n";
  else
    cout << "NO\n";
  return;
}
int main() {
  int t;
  cin >> t;
  while (t--) solve();
  return 0;
}
