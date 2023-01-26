#include <bits/stdc++.h>
using namespace std;
int test;
int n, m, k, l, r;
long long x, y, z, t, kq, mx;
int a[301010];
long long f[302013][4][2], p[111];
string s;
char v;
void pcs() {
  cin >> n >> m;
  for (int i = 1; i <= n; i++) {
    cin >> v;
    f[i][1][0] = f[i - 1][1][0];
    f[i][1][1] = f[i - 1][1][1];
    f[i][3][0] = f[i - 1][3][0];
    f[i][3][1] = f[i - 1][3][1];
    if (v == '+' && i % 2 == 0) f[i][1][0]++;
    if (v == '+' && i % 2 == 1) f[i][1][1]++;
    if (v == '-' && i % 2 == 0) f[i][3][0]++;
    if (v == '-' && i % 2 == 1) f[i][3][1]++;
  }
  while (m--) {
    cin >> l >> r;
    x = f[r][1][0] - f[l - 1][1][0];
    y = f[r][1][1] - f[l - 1][1][1];
    z = f[r][3][0] - f[l - 1][3][0];
    t = f[r][3][1] - f[l - 1][3][1];
    if ((r - l + 1) % 2)
      cout << 1 << '\n';
    else {
      if (x - y - z + t == 0)
        cout << 0 << '\n';
      else
        cout << 2 << '\n';
    }
  }
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  cin >> test;
  while (test--) pcs();
}
