#include <bits/stdc++.h>
using namespace std;
void sol() {
  long long int n;
  cin >> n;
  string a;
  cin >> a;
  int cnt = 0;
  for (int i = 0; i < n; i++) {
    if (a[i] == '2') {
      cnt++;
    }
  }
  if (cnt > 0 && cnt < 3) {
    cout << "NO" << endl;
    return;
  }
  char ans[n][n];
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      ans[i][j] = '0';
    }
  }
  cout << "YES" << endl;
  for (int i = 0; i < n; i++) {
    int flag = 0;
    for (int j = 0; j < n; j++) {
      if (i == j) {
        ans[i][j] = 'X';
      } else if (a[i] == '1') {
        ans[i][j] = '=';
      } else if (a[j] == '1') {
        ans[i][j] = '=';
      }
      if (flag) {
        a[i] = '-';
      } else if (ans[i][j] == '0') {
        if (ans[i][j] == '0') {
          ans[i][j] = '+';
          ans[j][i] = '-';
        }
        flag = 1;
      }
    }
  }
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      if (ans[i][j] == '0') {
        ans[i][j] = '=';
      }
    }
  }
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      cout << ans[i][j];
    }
    cout << endl;
  }
}
int main() {
  long long int t;
  cin >> t;
  while (t--) {
    sol();
  }
}
