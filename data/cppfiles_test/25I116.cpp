#include <bits/stdc++.h>
using namespace std;
void solve() {
  int n, m, j, c = 0, x, y = 0;
  string str, ch;
  cin >> str >> ch;
  if (str == ch) {
    cout << "YES"
         << "\n";
    return;
  }
  n = str.length();
  m = ch.length();
  for (int i = 0; i < n; i++) {
    c = i, j = 0;
    if (str[i++] == ch[j++]) {
      while (i != n && j != m && str[i] == ch[j]) i++, j++;
      if (j == m) {
        cout << "YES"
             << "\n";
        return;
      }
      y = j;
      for (i -= 2; i >= 0; i--) {
        x = i;
        while (i >= 0 && j != m && (str[i] == ch[j])) i--, j++;
        if (j == m) {
          cout << "YES" << endl;
          return;
        }
        i = x, j = y;
      }
    }
    i = c;
  }
  cout << "NO"
       << "\n";
}
int main() {
  ios_base::sync_with_stdio(false), cin.tie(0);
  int n;
  cin >> n;
  while (n--) {
    solve();
  }
  return 0;
}
