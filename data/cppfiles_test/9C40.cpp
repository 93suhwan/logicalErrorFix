#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e3 + 10;
const int mx = 1e5 + 10;
int a[maxn][maxn];
int n, m, k;
int c[mx];
int cnt[maxn];
int vis[maxn];
int solve(int i) {
  if (vis[i] >= cnt[i]) return i;
  int f = i;
  vis[i]++;
  for (int j = 1; j <= n; j) {
    if (a[j][f] == 1) {
      a[j][f] = 2;
      f++;
    } else if (a[j][f] == 2) {
      a[j][f] = 2;
      j++;
    } else {
      a[j][f] = 2;
      f--;
    }
  }
  return f;
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cin >> n >> m >> k;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      cin >> a[i][j];
      if (a[i][j] != 2) {
        cnt[j]++;
      }
    }
  }
  for (int i = 1; i <= k; i++) {
    cin >> c[i];
  }
  for (int i = 1; i <= k; i++) {
    cout << solve(c[i]) << ' ';
  }
  cout << endl;
  return 0;
}
