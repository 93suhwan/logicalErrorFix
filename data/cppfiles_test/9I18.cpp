#include <bits/stdc++.h>
using namespace std;
int mat[1001][1001];
int n, m;
int go(int j) {
  int i = 0;
  while (i != n - 1) {
    if (mat[i][j] == 1) {
      mat[i][j] = 2;
      j++;
    } else if (mat[i][j] == 2) {
      i++;
    } else if (mat[i][j] == 3) {
      mat[i][j] = 2;
      j--;
    }
  }
  return j;
}
void solve() {
  int k;
  cin >> n >> m >> k;
  for (int i = 0; i < n; i++)
    for (int j = 0; j < m; j++) cin >> mat[i][j];
  int a[k];
  for (int i = 0; i < k; i++) {
    cin >> a[i];
  }
  for (int i = 0; i < k; i++) {
    cout << go(a[i] - 1) + 1 << " ";
  }
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int t = 1;
  while (t--) {
    solve();
  }
}
