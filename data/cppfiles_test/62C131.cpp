#include <bits/stdc++.h>
using namespace std;
void solve() {
  using ll = long long;
  ll n, m, q;
  cin >> n >> m >> q;
  vector<vector<bool>> matrix(n, vector<bool>(m, true));
  ll count = -m * n;
  for (ll i = 0; i < n; i++) {
    if (m > i) count += 2 * (n - i) * (m - i);
    if (m > i + 1) count += (n - i) * (m - i - 1);
    if (i > 0 && m > i - 1) count += (n - i) * (m - i + 1);
  }
  while (q--) {
    int x, y;
    cin >> x >> y;
    x--;
    y--;
    ll changeCount = 1;
    int cx, cy;
    ll leftCount = 0;
    bool turn = 1;
    cx = x - 1;
    cy = y;
    for (; cx >= 0 && cy >= 0; turn ? cx-- : cy--) {
      if (!matrix[cx][cy]) break;
      leftCount++;
      turn = !turn;
    }
    ll bottomCount = 0;
    turn = 1;
    cx = x;
    cy = y + 1;
    for (; cx < n && cy < m; turn ? cy++ : cx++) {
      if (!matrix[cx][cy]) break;
      bottomCount++;
      turn = !turn;
    }
    changeCount += (leftCount + 1) * (bottomCount + 1) - 1;
    ll topCount = 0;
    turn = 1;
    cx = x;
    cy = y - 1;
    for (; cx >= 0 && cy >= 0; turn ? cy-- : cx--) {
      if (!matrix[cx][cy]) break;
      topCount++;
      turn = !turn;
    }
    ll rightCount = 0;
    turn = 1;
    cx = x + 1;
    cy = y;
    for (; cx < n && cy < m; turn ? cx++ : cy++) {
      if (!matrix[cx][cy]) break;
      rightCount++;
      turn = !turn;
    }
    changeCount += (topCount + 1) * (rightCount + 1) - 1;
    if (matrix[x][y]) {
      count -= changeCount;
    } else {
      count += changeCount;
    }
    matrix[x][y] = !matrix[x][y];
    cout << count << '\n';
  }
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  solve();
}
