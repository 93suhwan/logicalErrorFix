#include <bits/stdc++.h>
using namespace std;
long long INF = 1e9;
void solve() {
  int n;
  cin >> n;
  vector<int> vec(n);
  int count = 0;
  string s;
  cin >> s;
  for (int i = 0; i < n; i++) {
    vec[i] = s[i] - '0';
    if (vec[i] == 2) count++;
  }
  if (count == 1 || count == 2) {
    cout << "NO" << endl;
  } else {
    vector<bool> was(n, false);
    vector<vector<char>> v(n, vector<char>(n, 'X'));
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        if (j != i && v[i][j] == 'X') {
          if (vec[i] == 1 && vec[j] == 1) {
            v[i][j] = '=';
          } else if (vec[i] == 2 && vec[j] == 1) {
            v[i][j] = '-';
          } else if (vec[i] == 1 && vec[j] == 2) {
            v[i][j] = '+';
          } else if (vec[i] == 2 && vec[j] == 2) {
            if (was[i]) {
              v[i][j] = '-';
              was[j] = true;
              v[j][i] = '+';
            } else {
              v[i][j] = '+';
              was[i] = true;
              v[j][i] = '-';
            }
          }
        }
      }
    }
    cout << "YES" << endl;
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) cout << v[i][j];
      cout << endl;
    }
  }
}
int main() {
  int t;
  cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}
