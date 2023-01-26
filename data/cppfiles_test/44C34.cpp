#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int n;
  cin >> n;
  char mat[n][n];
  for (int i = 0; i < n; i++) cin >> mat[i];
  int bin[n][n];
  for (int i = 0; i < n; i++)
    for (int j = 0; j < n; j++)
      if (mat[i][j] == '.')
        bin[i][j] = -1;
      else
        bin[i][j] = (mat[i][j] == 'G');
  if (n % 2 == 1) {
    cout << "NONE\n";
    return 0;
  }
  int group[n][n];
  bool inv[n][n];
  for (int i = 0; i < n; i++)
    for (int j = 0; j < n; j++) {
      int x, y;
      if ((i + j) % 2 == 0) {
        x = (i + j) / 2;
        y = ((n - 1 - i) + (n - 1 - j)) / 2;
      } else {
        x = (i + (n - 1 - j)) / 2;
        y = ((n - 1 - i) + j) / 2;
      }
      if (x < y)
        group[i][j] = x;
      else
        group[i][j] = y;
      inv[i][j] = (min({i, j, n - 1 - i, n - 1 - j}) % 2 == 1 &&
                   (1 <= i && i < n - 1 && 1 <= j && j < n - 1));
      if ((i + j) % 2 == 1) group[i][j] = n / 2 - 1 - group[i][j];
    }
  int fix[n / 2];
  for (int i = 0; i < n / 2; i++) fix[i] = -1;
  for (int i = 0; i < n; i++)
    for (int j = 0; j < n; j++)
      if (bin[i][j] != -1) {
        bool v = (bin[i][j] ^ inv[i][j]);
        if (fix[group[i][j]] != -1 && fix[group[i][j]] != v) {
          cout << "NONE\n";
          return 0;
        }
        fix[group[i][j]] = v;
      }
  for (int i = 0; i < n / 2; i++)
    if (fix[i] == -1) {
      cout << "MULTIPLE\n";
      return 0;
    }
  char chars[] = {'S', 'G'};
  cout << "UNIQUE\n";
  for (int i = 0; i < n; i++, cout << "\n")
    for (int j = 0; j < n; j++) cout << (chars[fix[group[i][j]] ^ inv[i][j]]);
  return 0;
}
