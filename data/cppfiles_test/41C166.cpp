#include <bits/stdc++.h>
using namespace std;
inline long long POW(long long n, long long k, long long p = 99824435312111LL) {
  long long r = 1;
  for (; k; k >>= 1) {
    if (k & 1) r = r * n % p;
    n = n * n % p;
  }
  return r;
}
const int N = 200020;
int n, m, k, l, r;
string st;
int f[N][4][4];
int main() {
  if (fopen("text.inp", "r")) {
    freopen("text.inp", "r", stdin);
    freopen("text.out", "w", stdout);
  }
  ios_base::sync_with_stdio(false);
  cin >> n >> m;
  cin >> st;
  st = " " + st;
  for (int i = 1; i <= n; i++) {
    for (int j = 0; j <= 2; j++)
      for (int k = 0; k <= 2; k++) f[i][j][k] = f[i - 1][j][k];
    f[i][i % 3][st[i] - 'a']++;
  }
  while (m--) {
    cin >> l >> r;
    if (l == r) {
      cout << 0 << endl;
      continue;
    }
    int mn = INT_MAX;
    for (int i = 0; i <= 2; i++)
      for (int j = 0; j <= 2; j++)
        for (int k = 0; k <= 2; k++) {
          if (i == j || j == k || i == k) continue;
          mn = min(mn, r - l + 1 - (f[r][0][i] - f[l - 1][0][i]) -
                           (f[r][1][j] - f[l - 1][1][j]) -
                           (f[r][2][k] - f[l - 1][2][k]));
        }
    cout << mn << endl;
  }
}
