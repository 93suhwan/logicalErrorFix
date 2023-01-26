#include <bits/stdc++.h>
using namespace std;
string RedandBlue(string s, int n) {
  int j = -1;
  for (int i = 0; i < n; i++) {
    if (s[i] != '?') {
      j = i;
      break;
    }
  }
  if (j == -1) {
    s[0] = 'B';
    for (int i = 1; i < n; i++) {
      if (s[i - 1] == 'B')
        s[i] = 'R';
      else
        s[i] = 'B';
    }
    return s;
  }
  for (int i = j - 1; i >= 0; i--) {
    if (s[i + 1] == 'R')
      s[i] = 'B';
    else
      s[i] = 'R';
  }
  for (int i = j + 1; i < n; i++) {
    if (s[i] == '?') {
      if (s[i - 1] == 'R')
        s[i] = 'B';
      else
        s[i] = 'R';
    }
  }
  return s;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    string s;
    cin >> s;
    cout << RedandBlue(s, n) << endl;
  }
}
