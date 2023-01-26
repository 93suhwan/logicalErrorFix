#include <bits/stdc++.h>
using namespace std;
int m, n, k;
char letter[2][2][2] = {{{'a', 'b'}, {'c', 'd'}}, {{'e', 'f'}, {'g', 'h'}}};
void heng(int posx, int posy, int num, vector<vector<char>>& ans) {
  for (int i = 0; i < num; i++) {
    ans[posx + i][posy] = letter[(posx >> 1) & 1][(posy >> 1) & 1][i & 1];
    ans[posx + i][posy + 1] = letter[(posx >> 1) & 1][(posy >> 1) & 1][i & 1];
  }
}
void lie(int posx, int posy, int num, vector<vector<char>>& ans) {
  int t = posx & 2 + (posy >> 1) & 1;
  for (int i = 0; i < num; i++) {
    ans[posx][posy + i] = letter[(posx >> 1) & 1][(posy >> 1) & 1][i & 1];
    ans[posx + 1][posy + i] = letter[(posx >> 1) & 1][(posy >> 1) & 1][i & 1];
  }
}
void solve() {
  vector<vector<char>> ans(m, vector<char>(n));
  if (m & 1) {
    for (int i = 0; i < n; i += 2) heng(m - 1, i, 1, ans), k--;
    m--;
  }
  if (n & 1) {
    for (int i = 0; i < m; i += 2) lie(i, n - 1, 1, ans);
    n--;
  }
  for (int i = 0; i < m; i += 2)
    for (int j = 0; j < n; j += 2) {
      if (k) {
        heng(i, j, 2, ans);
        k -= 2;
      } else
        lie(i, j, 2, ans);
    }
  for (int i = 0; i < ans.size(); i++) {
    for (int j = 0; j < ans[i].size(); j++) cout << ans[i][j];
    cout << endl;
  }
}
int main() {
  int T;
  cin >> T;
  while (T--) {
    cin >> m >> n >> k;
    int minnum, maxnum;
    maxnum = m * (n / 2);
    minnum = m * n / 2 - (m / 2) * n;
    if (k >= minnum && k <= maxnum && ((k ^ maxnum) & 1) == 0) {
      cout << "YES" << endl;
      solve();
    } else
      cout << "NO" << endl;
  }
}
