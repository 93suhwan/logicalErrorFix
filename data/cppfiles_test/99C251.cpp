#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    string s;
    cin >> s;
    int bro = 0;
    for (int i = 0; i < n; i++) {
      if (s[i] == '2') {
        bro++;
      }
    }
    if (bro == 0) {
      cout << "YES" << endl;
      for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
          if (i == j) {
            cout << "X";
          } else {
            cout << "=";
          }
        }
        cout << endl;
      }
    } else if (bro <= 2) {
      cout << "NO" << endl;
    } else {
      cout << "YES" << endl;
      int mat[n][n];
      for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
          mat[i][j] = 0;
        }
      }
      int first = -1;
      int right = -1;
      for (int i = 0; i < n; i++) {
        if (s[i] == '2') {
          if (first == -1) {
            first = i;
          }
          right = i;
        }
      }
      int t1 = first;
      for (int i = 0; i < n; i++) {
        if (s[i] == '2' and i != t1) {
          mat[t1][i]++;
          mat[i][t1]--;
          t1 = i;
        }
      }
      mat[t1][first]++;
      mat[first][t1]--;
      for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
          if (i == j) {
            cout << "X";
          } else {
            if (mat[i][j] == 0) {
              cout << "=";
            } else if (mat[i][j] == 1) {
              cout << "+";
            } else {
              cout << "-";
            }
          }
        }
        cout << endl;
      }
    }
  }
}
