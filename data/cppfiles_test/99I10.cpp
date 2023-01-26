#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    string s;
    cin >> s;
    if (count(s.begin(), s.end(), '2') == 1) {
      cout << "NO" << endl;
    } else {
      vector<char> players(s.begin(), s.end());
      char results[50][50];
      for (int i = 0; i < n; i++) {
        int flag = 1;
        char c = players[i];
        for (int j = 0; j < n; j++) {
          if (c == '1') {
            if (i == j)
              results[i][j] = 'X';
            else {
              results[i][j] = '=';
            }
          } else {
            if (i == j) {
              results[i][j] = 'X';
            } else if (results[i][j] == '-') {
              continue;
            } else if (players[j] == '2' && flag == 1) {
              results[i][j] = '+';
              results[j][i] = '-';
              flag = 0;
            } else if (players[j] == '1') {
              results[i][j] = '=';
            } else if (players[j] == '2' && flag == 0) {
              results[i][j] = '=';
            }
          }
        }
      }
      cout << "YES" << endl;
      for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
          cout << results[i][j];
        }
        cout << endl;
      }
    }
  }
  return 0;
}
