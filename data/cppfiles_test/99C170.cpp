#include <bits/stdc++.h>
using namespace std;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
void omae_wa_mou_shindeiru(int tc) {
  int n;
  cin >> n;
  string s;
  cin >> s;
  vector<bool> check(n, 1);
  vector<vector<char>> v(n, vector<char>(n, '#'));
  for (int i = 0; i < n; i++) {
    for (int j = i; j < n; j++) {
      if (i == j) v[i][j] = 'X';
      if (v[i][j] != '#')
        continue;
      else if (s[i] == '2' and s[j] == '2') {
        if (check[i]) {
          v[i][j] = '+';
          v[j][i] = '-';
          check[i] = 0;
        } else {
          v[i][j] = '-';
          v[j][i] = '+';
          check[j] = 0;
        }
      } else if (s[i] == '2' and s[j] == '1') {
        v[i][j] = '=';
        v[j][i] = '=';
      } else if (s[i] == '1' and s[j] == '2') {
        v[i][j] = '=';
        v[j][i] = '=';
      } else {
        v[i][j] = '=';
        v[j][i] = '=';
      }
    }
    if (s[i] == '2' and check[i]) {
      cout << "NO"
           << "\n";
      return;
    }
  }
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      if (s[i] == '1' and v[i][j] == '-') {
        cout << "NO"
             << "\n";
        return;
      }
    }
  }
  cout << "YES"
       << "\n";
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      cout << v[i][j];
    }
    cout << "\n";
  }
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int tc = 1;
  cin >> tc;
  for (int i = 1; i < tc + 1; i++) {
    omae_wa_mou_shindeiru(i);
  }
}
