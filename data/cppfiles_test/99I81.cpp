#include <bits/stdc++.h>
using namespace std;
const double pi = acos(-1.0);
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    string s;
    cin >> s;
    int count = 0;
    for (int i = 0; i < s.size(); i += 1) {
      if (s[i] == '2') count++;
    }
    int d = (n * (n - 1)) / 2;
    if (count * 2 > d) {
      cout << "NO" << '\n';
      continue;
    } else
      cout << "YES" << '\n';
    char a[n][n];
    for (int i = 0; i < n; i += 1) {
      for (int j = 0; j < n; j += 1) {
        if (i == j)
          a[i][j] = 'X';
        else
          a[i][j] = '=';
      }
    }
    if (count == 0) {
      for (int i = 0; i < n; i += 1) {
        for (int j = 0; j < n; j += 1) {
          cout << a[i][j];
        }
        cout << '\n';
      }
      continue;
    }
    int w = count + 1;
    for (int i = 0; i < n; i += 1) {
      for (int j = 0; j < n; j += 1) {
        if (i != j && s[j] != '1' && w > 0 && (s[i] != '1') && a[i][j] == '=' &&
            a[j][i] == '=') {
          a[i][j] = '+';
          a[j][i] = '-';
          w--;
          break;
        }
      }
    }
    for (int i = 0; i < n; i += 1) {
      for (int j = 0; j < n; j += 1) {
        cout << a[i][j];
      }
      cout << '\n';
    }
  }
}
