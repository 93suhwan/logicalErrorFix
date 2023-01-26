#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 10;
char s[N];
long long b[10][10] = {{1, 2, 3}, {1, 3, 2}, {2, 1, 3},
                       {2, 3, 1}, {3, 1, 2}, {3, 2, 1}};
long long f[10][N];
int main() {
  int n, m;
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cin >> n >> m;
  cin >> s + 1;
  for (int i = 1; i <= n; i++) {
    for (int j = 0; j < 6; j++) {
      if (s[i] - 'a' + 1 != b[j][i % 3])
        f[j][i] = f[j][i - 1] + 1;
      else
        f[j][i] = f[j][i - 1];
    }
  }
  int l, r;
  for (int i = 1; i <= m; i++) {
    cin >> l >> r;
    long long ans = 1e9;
    for (int j = 0; j < 6; j++) ans = min(ans, f[j][r] - f[j][l - 1]);
    cout << ans << endl;
  }
  return 0;
}
