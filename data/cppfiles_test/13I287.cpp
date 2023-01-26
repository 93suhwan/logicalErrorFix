#include <bits/stdc++.h>
using namespace std;
void printstr(vector<string> s) {
  for (int i = 0; i < s.size(); i++) cout << s[i] << endl;
}
void solve() {
  int n, m, k;
  cin >> n >> m >> k;
  if (m == 1 || k > (n * m) / 2) {
    cout << "NO" << endl;
    return;
  }
  vector<string> s(n, string(m, '0'));
  if (n % 2 == 0) {
    if (m % 2 == 0) {
      if (k % 2) {
        cout << "NO" << endl;
      } else {
        cout << "YES" << endl;
        for (int i = 0; i < n; i += 2) {
          for (int j = 0; j < m; j += 2) {
            if (k) {
              char c1 = 'a' + (i + j) % 26;
              char c2 = 'a' + (i + j + 1) % 26;
              s[i][j] = c1;
              s[i][j + 1] = c1;
              s[i + 1][j] = c2;
              s[i + 1][j + 1] = c2;
              k -= 2;
            } else {
              char c1 = 'a' + (i + j) % 26;
              char c2 = 'a' + (i + j + 1) % 26;
              s[i][j] = c1;
              s[i][j + 1] = c2;
              s[i + 1][j] = c1;
              s[i + 1][j + 1] = c2;
            }
          }
        }
        printstr(s);
      }
    } else {
      if (k > (n * (m - 1) / 2)) {
        cout << "NO" << endl;
        return;
      }
      if (k % 2) {
        cout << "NO" << endl;
      } else {
        cout << "YES" << endl;
        for (int i = 0; i < n; i += 2) {
          char c1 = 'a' + (i) % 26;
          s[i][0] = c1;
          s[i + 1][0] = c1;
        }
        for (int i = 0; i < n; i += 2) {
          for (int j = 1; j < m; j += 2) {
            if (k) {
              char c1 = 'a' + (i + j) % 26;
              char c2 = 'a' + (i + j + 1) % 26;
              s[i][j] = c1;
              s[i][j + 1] = c1;
              s[i + 1][j] = c2;
              s[i + 1][j + 1] = c2;
              k -= 2;
            } else {
              char c1 = 'a' + (i + j) % 26;
              char c2 = 'a' + (i + j + 1) % 26;
              s[i][j] = c1;
              s[i][j + 1] = c2;
              s[i + 1][j] = c1;
              s[i + 1][j + 1] = c2;
            }
          }
        }
        printstr(s);
      }
    }
  } else {
    if (k < m / 2) {
      cout << "NO" << endl;
      return;
    }
    k -= m / 2;
    if (k % 2) {
      cout << "NO" << endl;
    } else {
      cout << "YES" << endl;
      for (int i = 0; i < m; i += 2) {
        char c1 = 'a' + (i) % 26;
        s[0][i] = c1;
        s[0][i + 1] = c1;
      }
      for (int i = 1; i < n; i += 2) {
        for (int j = 0; j < m; j += 2) {
          if (k) {
            char c1 = 'a' + (i + j) % 26;
            char c2 = 'a' + (i + j + 1) % 26;
            s[i][j] = c1;
            s[i][j + 1] = c1;
            s[i + 1][j] = c2;
            s[i + 1][j + 1] = c2;
            k -= 2;
          } else {
            char c1 = 'a' + (i + j) % 26;
            char c2 = 'a' + (i + j + 1) % 26;
            s[i][j] = c1;
            s[i][j + 1] = c2;
            s[i + 1][j] = c1;
            s[i + 1][j + 1] = c2;
          }
        }
      }
      printstr(s);
    }
  }
}
int main() {
  int t;
  cin >> t;
  for (int i = 0; i < t; i++) {
    solve();
  }
  return 0;
}
