#include <bits/stdc++.h>
using namespace std;
char arr[101][101];
int n, m, k;
bool valid(int i, int j) { return i >= 0 and j >= 0 and i < n and j < m - 1; }
bool valid2(int i, int j, char c) {
  bool x = (i >= 0 and j >= 0 and i < n and j < m and c != arr[i][j]) or
           (i < 0 or j < 0 or i >= n or j >= m);
  return x;
}
bool check(int i, int j, char c) {
  bool x = valid2(i + 1, j - 1, c) and valid2(i, j + 1, c) and
           valid2(i + 1, j + 1, c) and valid2(i - 1, j + 1, c) and
           valid2(i - 1, j, c) and valid2(i, j - 1, c) and
           valid2(i + 1, j, c) and valid2(i, j + 2, c);
  return x;
}
void solve(int i, int j, int cnt) {
  if (!cnt or !valid(i, j)) return;
  char now;
  for (char ch = 'a'; ch <= 'z'; ch++) {
    if (check(i, j, ch)) {
      now = ch;
    }
  }
  arr[i][j] = arr[i][j + 1] = now;
  cnt--;
  k--;
  if ((n - i) % 2 == 0 and valid(i + 1, j)) {
    solve(i + 1, j, cnt);
  } else {
    while (valid(i - 1, j + 2) and !arr[i - 1][j + 2]) i--;
    if (valid(i, j + 2))
      solve(i, j + 2, cnt);
    else if (valid(i, j + 2))
      solve(i, j + 2, cnt);
    else {
      while (valid(i + 1, j - 2) and !arr[i + 1][j - 2]) j -= 2;
      solve(i + 1, j, cnt);
    }
  }
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int t;
  cin >> t;
  while (t--) {
    memset(arr, 0, sizeof arr);
    cin >> n >> m >> k;
    solve(0, 0, k);
    int ok = 0;
    for (int i = 0; i < m; i++) {
      int cnt = 0;
      for (int j = 0; j < n; j++) {
        if (!arr[j][i]) cnt++;
      }
      if (cnt & 1) ok = 1;
    }
    if (k or ok)
      cout << "NO\n";
    else {
      for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
          char now;
          for (char ch = 'a'; ch <= 'z'; ch++) {
            if (check(i, j, ch)) {
              now = ch;
            }
          }
          if (!arr[i][j]) arr[i][j] = arr[i + 1][j] = now;
        }
      }
      cout << "YES\n";
      for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
          cout << arr[i][j];
          arr[i][j] = 0;
        }
        cout << '\n';
      }
    }
  }
  return 0;
}
