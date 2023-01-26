#include <bits/stdc++.h>
using namespace std;
void solve() {
  int n;
  cin >> n;
  string str;
  cin >> str;
  int two = 0;
  for (int i = 0; i < str.size(); i++) {
    if (str[i] == '2') {
      two++;
    }
  }
  if (two <= 2 && two != 0) {
    cout << "NO\n";
    return;
  }
  char ans[52][52];
  for (int i = 0; i < str.size(); i++) {
    for (int j = 0; j < str.size(); j++) {
      if (i == j)
        ans[i][j] = 'X';
      else
        ans[i][j] = '.';
    }
  }
  for (int i = str.size() - 1; i >= 0; i--) {
    for (int j = str.size() - 1; j >= 0; j--) {
      if (ans[i][j] == '.') {
        if (str[i] == '1' && str[j] == '1') {
          ans[i][j] = '=';
          ans[j][i] = '=';
        }
      }
    }
  }
  for (int i = str.size() - 1; i >= 0; i--) {
    for (int j = str.size() - 1; j >= 0; j--) {
      if (str[i] == '1' && ans[i][j] == '.') {
        ans[i][j] = '+';
      }
    }
  }
  for (int i = str.size() - 1; i >= 0; i--) {
    for (int j = str.size() - 1; j >= 0; j--) {
      if (ans[i][j] == '.' && ans[j][i] != '+') {
        ans[i][j] = '+';
        break;
      }
    }
  }
  for (int i = 0; i < str.size(); i++) {
    for (int j = i + 1; j < str.size(); j++) {
      if (ans[i][j] == '+') ans[j][i] = '-';
    }
  }
  for (int i = 0; i < str.size(); i++) {
    for (int j = i + 1; j < str.size(); j++) {
      if (ans[i][j] == '.') {
        ans[j][i] = '+';
        ans[i][j] = '-';
      }
    }
  }
  for (int i = 0; i < str.size(); i++) {
    for (int j = 0; j < str.size(); j++) {
      cout << ans[i][j];
    }
    cout << "\n";
  }
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int t;
  cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}
