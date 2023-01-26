#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    vector<vector<char>> a(n, vector<char>(n, ' '));
    vector<int> one, two;
    for (int i = 0; i < n; i++) {
      char k;
      cin >> k;
      if (k == '1')
        one.push_back(i);
      else
        two.push_back(i);
    }
    if (two.size() > 0 && two.size() <= 2) {
      cout << "NO"
           << "\n";
      continue;
    }
    for (int i = 0; i < two.size(); i++) {
      if (i == two.size() - 1) {
        a[two[i]][two[0]] = '+';
        a[two[0]][two[i]] = '-';
      } else {
        a[two[i]][two[i + 1]] = '+';
        a[two[i + 1]][two[i]] = '-';
      }
    }
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        if (i == j)
          a[i][j] = 'X';
        else if (a[i][j] == ' ')
          a[i][j] = '=';
      }
    }
    cout << "YES"
         << "\n";
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        cout << a[i][j];
      }
      cout << "\n";
    }
  }
}
