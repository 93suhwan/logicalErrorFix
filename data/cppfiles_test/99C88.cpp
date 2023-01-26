#include <bits/stdc++.h>
using namespace std;
const long long int MOD = 1e9 + 7;
void solve() {
  long long int n;
  cin >> n;
  string s;
  cin >> s;
  long long int cnt2 = 0;
  for (int i = 0; i < n; i++) {
    if (s[i] == '2') {
      cnt2++;
    }
  }
  if (cnt2 == 1 or cnt2 == 2) {
    cout << "NO"
         << "\n";
    ;
    return;
  }
  char ch[n][n];
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      ch[i][j] = '.';
    }
  }
  for (int i = 0; i < n; i++) {
    bool check_2 = false;
    for (int j = 0; j < n; j++) {
      if (i == j) {
        ch[i][j] = 'X';
      } else if (s[i] == '1' and s[j] == '1' and ch[i][j] == '.') {
        ch[i][j] = '=';
        ch[j][i] = '=';
      } else if (s[i] == '1' and s[j] == '2' and ch[i][j] == '.') {
        ch[i][j] = '+';
        ch[j][i] = '-';
      } else if (s[i] == '2' and s[j] == '1' and ch[i][j] == '.') {
        ch[i][j] = '-';
        ch[j][i] = '+';
      } else if (s[i] == '2' and s[j] == '2' and ch[i][j] == '.') {
        if (check_2 == false) {
          ch[i][j] = '+';
          ch[j][i] = '-';
          check_2 = true;
        } else {
          ch[i][j] = '-';
          ch[j][i] = '+';
        }
      }
    }
  }
  cout << "YES"
       << "\n";
  ;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      cout << ch[i][j];
    }
    cout << "\n";
    ;
  }
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  long long int t;
  cin >> t;
  while (t--) {
    solve();
  }
}
