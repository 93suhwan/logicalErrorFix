#include <bits/stdc++.h>
using namespace std;
bool isPrime(int n) {
  if (n <= 1) return false;
  if (n <= 3) return true;
  if (n % 2 == 0 || n % 3 == 0) return false;
  for (int i = 5; i * i <= n; i = i + 6)
    if (n % i == 0 || n % (i + 2) == 0) return false;
  return true;
}
bool baal(string temp) {
  if (count(temp.begin(), temp.end(), 'a') ==
      count(temp.begin(), temp.end(), 'b')) {
    return true;
  }
  return false;
}
void solve() {
  long long int n, i, j, k, l, m, odd = 0, even = 0, x, ans = 0;
  string s;
  cin >> n;
  cin >> s;
  char a[n + 5][n + 5];
  for (i = 0; i <= n; i++) {
    for (j = 0; j <= n; j++) {
      a[i][j] = '#';
    }
  }
  l = 0;
  for (i = 0; i < n; i++) {
    if (s[i] == '1') {
      for (j = 0; j < n; j++) {
        a[i][j] = '=';
        a[j][i] = '=';
      }
    }
  }
  for (i = 0; i < n; i++) {
    for (j = 0; j < n; j++) {
      if (i == j) {
        a[i][j] = 'X';
        continue;
      }
      if (s[i] == '1' && a[i][j] == '#') {
        a[i][j] = '=';
        a[j][i] = '=';
      }
      if (s[i] == '2' && s[j] == '2' && a[i][j] == '#' && a[j][i] == '#') {
        a[i][j] = '+';
        a[j][i] = '-';
        for (m = j + 1; m < n; m++) {
          a[i][m] = '-';
          a[m][i] = '+';
        }
        break;
      }
    }
    l++;
  }
  for (i = 0; i < n; i++) {
    int cnt = 0;
    for (j = 0; j < n; j++) {
      if (s[i] == '1' && a[i][j] == '-') {
        cout << "NO" << endl;
        return;
      }
      if (s[i] == '2' && a[i][j] == '+') {
        cnt++;
      }
    }
    if (s[i] == '2' && cnt == 0) {
      cout << "NO" << endl;
      return;
    }
  }
  cout << "YES" << endl;
  for (i = 0; i < n; i++) {
    for (j = 0; j < n; j++) {
      cout << a[i][j];
    }
    cout << endl;
  }
}
int main() {
  int t;
  cin >> t;
  while (t--) {
    solve();
  }
}
