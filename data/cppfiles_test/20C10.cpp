#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cin.exceptions(ios::badbit | ios::failbit);
  cout << fixed << setprecision(15);
  int TC = 1;
  cin >> TC;
  while (TC--) {
    int R, C;
    cin >> R >> C;
    vector<vector<int>> grid(R, vector<int>(C, 0));
    for (int r = 0; r < R; r++) {
      string S;
      cin >> S;
      for (int c = 0; c < C; c++) {
        grid[r][c] = S[c] - '0';
      }
    }
    vector<vector<int>> pref;
    vector<int> row(C, 0);
    pref.push_back(row);
    for (int r = 0; r < R; r++) {
      for (int c = 0; c < C; c++) {
        row[c] += grid[r][c];
      }
      pref.push_back(row);
    }
    int ans = R * C;
    for (int r1 = 0; r1 < R; r1++) {
      for (int r2 = r1 + 4; r2 < R; r2++) {
        vector<int> changeToZeroes;
        vector<int> changeToOnes;
        for (int c = 0; c < C; c++) {
          changeToZeroes.push_back((1 - grid[r1][c]) +
                                   (pref[r2][c] - pref[r1 + 1][c]) +
                                   (1 - grid[r2][c]));
          changeToOnes.push_back((r2 - r1 - 1) -
                                 (pref[r2][c] - pref[r1 + 1][c]));
        }
        int base = 0;
        int left = R * C;
        for (int c = 0; c < C - 3; c++) {
          base += changeToZeroes[c];
          left = min(left, changeToOnes[c] - base);
          int right = (changeToZeroes[c + 1] + changeToZeroes[c + 2] +
                       changeToOnes[c + 3]);
          ans = min(ans, base + left + right);
        }
      }
    }
    cout << ans << '\n';
  }
  return 0;
}
