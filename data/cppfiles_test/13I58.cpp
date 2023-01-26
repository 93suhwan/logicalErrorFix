#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  for (int i = 0; i < t; i++) {
    int n, m, k;
    cin >> n >> m >> k;
    int a = 0;
    if (n % 2) {
      if (m / 2 > k) {
        cout << "NO" << endl;
        continue;
      } else {
        a += m / 2;
      }
    } else if (m % 2) {
      if (n * m / 2 - n / 2 < k) {
        cout << "NO" << endl;
        continue;
      }
    }
    k -= a;
    if (k % 2) {
      cout << "NO" << endl;
      continue;
    }
    cout << "YES"
         << "\n";
    k += a;
    vector<char> ch(26);
    for (int j = 0; j < 26; j++) ch[j] = 'a' + j;
    vector<vector<char>> v(n, vector<char>(m, '0'));
    if (n % 2) {
      int p = 0;
      for (int j = 0; j < m && k > 0; j += 2) {
        v[0][j] = ch[p % 26];
        v[0][j + 1] = ch[p % 26];
        p += 8;
        k--;
      }
      int r = 1, c = 0;
      while (k > 0) {
        if (r > 0 && v[r - 1][c] == ch[p % 26]) p++;
        v[r][c] = ch[p % 26];
        v[r][c + 1] = ch[p % 26];
        p += 8;
        v[r + 1][c] = ch[p % 26];
        v[r + 1][c + 1] = ch[p % 26];
        p += 8;
        k -= 2;
        if (c + 2 == m) {
          r += 2;
        } else {
          c += 2;
        }
      }
      for (int j = 1; j < n; j++) {
        for (int l = 0; l < m; l++) {
          if (v[j][l] == '0') {
            v[j][l] = ch[p % 26];
            v[j + 1][l] = ch[p % 26];
            p += 8;
          }
        }
      }
    } else if (m % 2) {
      int r = 0, p = 0;
      while (k > 0) {
        for (int j = 0; j < m && k > 0; j += 2) {
          if (r > 0 && v[r - 1][j] == ch[p % 26]) p++;
          v[r][j] = ch[p % 26];
          v[r][j + 1] = ch[p % 26];
          p += 8;
          v[r + 1][j] = ch[p % 26];
          v[r + 1][j + 1] = ch[p % 26];
          p += 8;
          k -= 2;
        }
        r++;
      }
      for (int j = 0; j < n; j++) {
        for (int l = 0; l < m; l++) {
          if (v[j][l] == '0') {
            v[j][l] = ch[p % 26];
            v[j + 1][l] = ch[p % 26];
            p += 8;
          }
        }
      }
    } else {
      int r = 0, p = 0;
      while (k > 0) {
        for (int j = 0; j < m && k > 0; j += 2) {
          v[r][j] = ch[p % 26];
          v[r][j + 1] = ch[p % 26];
          p += 8;
          v[r + 1][j] = ch[p % 26];
          v[r + 1][j + 1] = ch[p % 26];
          p += 8;
          k -= 2;
        }
        r += 2;
      }
      for (int j = 0; j < n; j++) {
        for (int l = 0; l < m; l++) {
          if (v[j][l] == '0') {
            v[j][l] = ch[p % 26];
            v[j + 1][l] = ch[p % 26];
            p += 8;
          }
        }
      }
    }
    for (int j = 0; j < n; j++) {
      for (int l = 0; l < m; l++) {
        cout << v[j][l];
      }
      cout << endl;
    }
  }
}
