#include <bits/stdc++.h>
using namespace std;
long long mod = 998244353;
int n, m, xL, yL;
int moveX[] = {0, 0, 1, -1};
int moveY[] = {1, -1, 0, 0};
bool check(int x, int y, string s[]) {
  if (x < 0 or y < 0 or x >= n or y >= m) return false;
  if (s[x][y] == '+' or s[x][y] == '#') return false;
  int der = 0, cntcong = 0;
  for (int i = 0; i < 4; i++) {
    int xnew = x + moveX[i];
    int ynew = y + moveY[i];
    if (xnew < 0 or ynew < 0 or xnew >= n or ynew >= m) continue;
    if (s[xnew][ynew] == '#') continue;
    der++;
    if (s[xnew][ynew] == '+') cntcong++;
  }
  if (der - cntcong > 1) return false;
  return true;
}
void solve() {
  cin >> n >> m;
  string s[n];
  for (int i = 0; i < n; i++) {
    cin >> s[i];
    for (int j = 0; j < m; j++)
      if (s[i][j] == 'L') {
        xL = i, yL = j;
        s[i][j] = '+';
      }
  }
  queue<int> X;
  queue<int> Y;
  X.push(xL);
  Y.push(yL);
  while (!X.empty()) {
    int x = X.front();
    int y = Y.front();
    s[x][y] = '+';
    X.pop();
    Y.pop();
    for (int i = 0; i < 4; i++) {
      int xnew = x + moveX[i];
      int ynew = y + moveY[i];
      if (check(xnew, ynew, s)) {
        X.push(xnew);
        Y.push(ynew);
      }
    }
  }
  s[xL][yL] = 'L';
  for (int i = 0; i < n; i++) cout << s[i] << "\n";
}
void solve1() {}
signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(NULL);
  if (fopen("text.in", "r")) {
    freopen("text.in", "r", stdin);
    freopen("text.out", "w", stdout);
  }
  int t;
  cin >> t;
  while (t--) solve();
}
