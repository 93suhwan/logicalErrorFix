#include <bits/stdc++.h>
using namespace std;
void solve() {
  int n;
  cin >> n;
  string s;
  cin >> s;
  int ct = 0;
  vector<int> v;
  for (int i = 0; i < n; i++)
    if (s[i] == '2') {
      ct++;
      v.push_back(i);
    }
  if (ct == 0) {
    cout << "YES"
         << "\n";
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        if (i == j)
          cout << 'X';
        else
          cout << '=';
      }
      cout << "\n";
    }
    return;
  }
  if (ct <= 2) {
    cout << "NO"
         << "\n";
    return;
  } else {
    cout << "YES"
         << "\n";
    char a[n][n];
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        if (i == j)
          a[i][i] = 'X';
        else
          a[i][j] = '=';
      }
    }
    for (int i = 0; i < ct - 1; i++) {
      a[v[i]][v[i + 1]] = '+';
      a[v[i + 1]][v[i]] = '-';
    }
    a[v[ct - 1]][v[0]] = '+';
    a[v[0]][v[ct - 1]] = '-';
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) cout << a[i][j];
      cout << "\n";
    }
  }
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  long long int t = 1;
  cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}
