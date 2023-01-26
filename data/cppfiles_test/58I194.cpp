#include <bits/stdc++.h>
using namespace std;
bool isPossible(vector<vector<int>> v, int i, int j, int r, int c) {
  if ((i < 0) || (i >= r) || (j >= c) || (v[i][j] == 1)) {
    return false;
  }
  if ((i == r - 1) && (j == c - 1)) {
    return true;
  }
  if (isPossible(v, i + 1, j + 1, r, c)) {
    return true;
  }
  if (isPossible(v, i, j + 1, r, c)) {
    return true;
  }
  if (isPossible(v, i - 1, j + 1, r, c)) {
    return true;
  }
  return false;
}
int main() {
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    vector<vector<int>> v(2);
    for (int i = 0; i < 2; i++) {
      v[i] = vector<int>(n);
      for (int j = 0; j < n; j++) {
        cin >> v[i][j];
      }
    }
    if (isPossible(v, 0, 0, 2, n)) {
      cout << "YES\n";
    } else {
      cout << "NO\n";
    }
  }
  return 0;
}
