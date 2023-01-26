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
    int w = count;
    vector<int> v;
    for (int i = 1; i < n; i += 1) v.push_back(i);
    v.push_back(0);
    int ref = 0;
    for (int i = 0; i < n; i += 1) {
      bool f = true;
      for (int j = 0; j < n; j += 1) {
        if (s[i] == '1' && i != j)
          a[i][j] = '+';
        else {
          if (j == v[ref] && i != j && f && w > 0) {
            a[i][j] = '+';
            ref++;
            f = false;
            w--;
          } else if (i != j)
            a[i][j] = '-';
        }
      }
      if (s[i] == '1') ref++;
    }
    for (int i = 0; i < n; i += 1) {
      for (int j = 0; j < n; j += 1) {
        cout << a[i][j];
      }
      cout << '\n';
    }
  }
}
