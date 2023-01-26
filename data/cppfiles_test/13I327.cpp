#include <bits/stdc++.h>
using namespace std;
vector<int> dd;
int ans = 0;
int mf(string s, char ch) {
  int kol = 0;
  for (auto i : s) {
    if (i == ch) {
      kol++;
    }
  }
  if (kol * 2 > s.size()) {
    ans++;
    return kol * 2 - s.size();
  } else {
    dd.push_back(int(s.size() - kol * 2));
    return 0;
  }
}
signed main() {
  int t;
  cin >> t;
  for (int q = 0; q < t; q++) {
    int n, m, k;
    cin >> n >> m >> k;
    vector<string> v(n);
    for (int i = 0; i < n; i++) {
      v[i].resize(m);
    }
    char ch = 'a';
    char w = 'a';
    for (int j = 0; j < m; j++) {
      w = ch;
      for (int i = 0; i + 1 < n; i += 2) {
        v[i][j] = ch;
        v[i + 1][j] = ch;
        if (ch == 'a')
          ch = 'b';
        else
          ch = 'a';
      }
      if (w == 'a') {
        ch = 'b';
      } else {
        ch = 'a';
      }
    }
    if (m % 2 == 1) {
      if (k * 2 > (m - 1) * n) {
        cout << "no\n";
        continue;
      }
      m--;
    }
    if (n % 2 == 0) {
      if (k % 2 == 0) {
        cout << "yes\n";
        char ch = 'c';
        char w;
        for (int i = 0; i < m; i += 2) {
          w = ch;
          for (int j = 0; j < n; j++) {
            v[j][i] = ch;
            v[j][i + 1] = ch;
            if (ch == 'c')
              ch = 'd';
            else
              ch = 'c';
            k--;
            if (k == 0) {
              break;
            }
          }
          if (w == 'c') {
            ch = 'd';
          } else {
            ch = 'c';
          }
          if (k == 0) {
            break;
          }
        }
      } else {
        cout << "no\n";
      }
    } else {
      if (k < m / 2) {
        cout << "no\n";
        continue;
      }
      k -= m / 2;
      char ch = 'c';
      for (int j = 0; j < m; j += 2) {
        v[n - 1][j] = ch;
        v[n - 1][j + 1] = ch;
        if (ch == 'c')
          ch = 'd';
        else
          ch = 'c';
      }
      if (k % 2 == 0) {
        cout << "yes\n";
        ch = 'e';
        char w;
        for (int i = 0; i < m; i += 2) {
          w = ch;
          for (int j = 0; j < n - 1; j++) {
            v[j][i] = ch;
            v[j][i + 1] = ch;
            if (ch == 'e')
              ch = 'f';
            else
              ch = 'e';
            k--;
            if (k == 0) {
              break;
            }
          }
          if (w == 'e') {
            ch = 'f';
          } else {
            ch = 'e';
          }
          if (k == 0) {
            break;
          }
        }
      } else {
        cout << "no\n";
      }
    }
    for (auto i : v) {
      cout << i << "\n";
    }
  }
  return 0;
}
