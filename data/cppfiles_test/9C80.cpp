#include <bits/stdc++.h>
using namespace std;
struct Tree {
  int val;
  Tree* right = NULL;
  Tree* left = NULL;
};
long long int b_expo(long long x, long long int y, long long int p) {
  long long int res = 1;
  x = x % p;
  if (x == 0) return 0;
  while (y > 0) {
    if (y & 1) res = (res * x) % p;
    y = y >> 1;
    x = (x * x) % p;
  }
  return res;
}
long long int gcd(long long int a, long long int b) {
  return b ? gcd(b, a % b) : a;
}
void solve() {
  long long int n, m, k;
  cin >> n >> m >> k;
  vector<vector<long long int>> a(n + 1, vector<long long int>(m + 1));
  for (long long int i = 1; i < n + 1; i++) {
    for (long long int j = 1; j < m + 1; j++) {
      cin >> a[i][j];
    }
  }
  int v, u, x;
  while (k--) {
    cin >> v;
    u = 1;
    while (u <= n) {
      x = a[u][v];
      a[u][v] = 2;
      if (x == 1) v++;
      if (x == 2) u++;
      if (x == 3) v--;
    }
    cout << v << endl;
  }
}
int main() {
  solve();
  return 0;
}
