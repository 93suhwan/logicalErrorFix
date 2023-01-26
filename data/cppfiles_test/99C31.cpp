#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    string s;
    cin >> s;
    vector<vector<char>> mat(n, vector<char>(n));
    vector<int> pos;
    for (int i = 0; i < n; i++) {
      if (s[i] == '2') {
        pos.push_back(i);
      }
    }
    if (pos.size() <= 2 && pos.size() > 0) {
      cout << "NO\n";
      continue;
    }
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        if (i == j) {
          mat[i][j] = 'X';
        } else {
          mat[i][j] = mat[j][i] = '=';
        }
      }
    }
    for (int i = 0; i < (int)pos.size() - 1; i++) {
      mat[pos[i]][pos[i + 1]] = '+';
      mat[pos[i + 1]][pos[i]] = '-';
    }
    if (pos.size() > 0) {
      mat[pos[pos.size() - 1]][pos[0]] = '+';
      mat[pos[0]][pos[pos.size() - 1]] = '-';
    }
    cout << "YES\n";
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        cout << mat[i][j];
      }
      cout << "\n";
    }
  }
}
