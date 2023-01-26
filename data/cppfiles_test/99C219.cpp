#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int test;
  cin >> test;
  while (test--) {
    int n;
    cin >> n;
    string s;
    cin >> s;
    int cnt2 = 0;
    vector<int> x;
    for (int i = 0; i < n; i++) {
      if (s[i] == '2') {
        cnt2++;
        x.emplace_back(i);
      }
    }
    if (cnt2 == 1 || cnt2 == 2) {
      cout << "NO" << '\n';
      continue;
    }
    cout << "YES" << '\n';
    vector<vector<char>> a(n, vector<char>(n, '='));
    for (int i = 0; i < n; i++) {
      a[i][i] = 'X';
    }
    for (int i = 0; i < cnt2; i++) {
      if (i == 0) {
        a[x[0]][x[cnt2 - 1]] = '+';
        a[x[cnt2 - 1]][x[0]] = '-';
      } else {
        a[x[i]][x[i - 1]] = '+';
        a[x[i - 1]][x[i]] = '-';
      }
    }
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        cout << a[i][j];
      }
      cout << '\n';
    }
  }
  return 0;
}
