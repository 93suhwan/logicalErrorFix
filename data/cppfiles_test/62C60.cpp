#include <bits/stdc++.h>
using namespace std;
int ttt = 1;
long long n, m, k;
template <class myType>
void print_arr(myType &arr, long long L, string sep) {
  for (int(i) = (0); (i) < (L); ++(i)) {
    cout << arr[i];
    if (i < L - 1) cout << sep;
  }
  cout << "\n";
  return;
}
void solve() {
  cin >> n >> m >> k;
  long long ans = 0;
  for (int(i) = (0); (i) < (n); ++(i))
    for (int(j) = (0); (j) < (m); ++(j)) {
      ans++;
      long long d = n - i - 1, r = m - j - 1;
      ans += 2 * min(d, r) + (r > d ? 1 : 0);
      ans += 2 * min(d, r) + (d > r ? 1 : 0);
    }
  vector<vector<int> > G(n, vector<int>(m, 0));
  while (k--) {
    int i, j;
    cin >> i >> j;
    i--;
    j--;
    if (G[i][j] == 1)
      ans++;
    else
      ans--;
    int r_then_d = 1;
    int x = i, y = j;
    while (1) {
      y++;
      if (y >= m || G[x][y] == 1) break;
      r_then_d++;
      x++;
      if (x >= n || G[x][y] == 1) break;
      r_then_d++;
    }
    int d_then_r = 1;
    x = i;
    y = j;
    while (1) {
      x++;
      if (x >= n || G[x][y] == 1) break;
      d_then_r++;
      y++;
      if (y >= m || G[x][y] == 1) break;
      d_then_r++;
    }
    int u_then_l = 1;
    x = i;
    y = j;
    while (1) {
      x--;
      if (x < 0 || G[x][y] == 1) break;
      u_then_l++;
      y--;
      if (y < 0 || G[x][y] == 1) break;
      u_then_l++;
    }
    int l_then_u = 1;
    x = i;
    y = j;
    while (1) {
      y--;
      if (y < 0 || G[x][y] == 1) break;
      l_then_u++;
      x--;
      if (x < 0 || G[x][y] == 1) break;
      l_then_u++;
    }
    if (G[i][j] == 1) {
      ans += u_then_l * r_then_d - 1 + l_then_u * d_then_r - 1;
    } else {
      ans -= u_then_l * r_then_d - 1 + l_then_u * d_then_r - 1;
    }
    cout << ans << "\n";
    G[i][j] ^= 1;
  }
  return;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  while (ttt--) solve();
  return 0;
}
