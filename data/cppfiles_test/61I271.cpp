#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int t = 0;
  cin >> t;
  while (t--) {
    int n = 0;
    string s, r;
    cin >> n;
    cin >> s;
    r = s;
    for (int i = 0; i < n; i++) {
      if (s[i] != '?' || i == n - 1) {
        for (int j = i - 1; j >= 0 && s[j] == '?'; j--) {
          if (s[j + 1] == 'R')
            s[j] = 'B';
          else
            s[j] = 'R';
        }
      }
    }
    if (s[n - 1] == '?') {
      if (n == 1)
        s[n - 1] == 'B';
      else if (s[n - 2] == 'R')
        s[n - 1] = 'B';
      else
        s[n - 1] = 'R';
    }
    cout << s << endl;
  }
  return 0;
}
