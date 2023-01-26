#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int t;
  cin >> t;
  while (t--) {
    string s, ss;
    cin >> s >> ss;
    int n = s.length(), m = ss.length();
    int i = 0, j = 0;
    bool poss = false;
    while (i < n && j < m) {
      if (s[i] != ss[j]) {
        i++;
      } else {
        int k = i, kk = j;
        while (s[i] == ss[j]) {
          i++;
          j++;
          if (i == n || j == m) break;
        }
        if (j == m) {
          poss = true;
          break;
        } else {
          i -= 2;
          while (i >= 0 && j < m && s[i] == ss[j]) {
            i--;
            j++;
          }
          if (j == m) {
            poss = true;
            break;
          } else {
            i = k + 1;
            j = 0;
          }
        }
      }
    }
    if (poss)
      cout << "YES\n";
    else
      cout << "NO\n";
  }
}
