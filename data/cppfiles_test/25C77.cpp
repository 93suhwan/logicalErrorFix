#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    string s, t;
    cin >> s >> t;
    int n = s.length();
    int m = t.length();
    bool found = false;
    for (int i = 0; i < n; i++) {
      if (found)
        break;
      else if (s[i] != t[0])
        continue;
      else {
        int covered = 0;
        for (int j = i; j < n; j++) {
          if (s[j] == t[covered]) {
            covered++;
            if (covered == m) {
              found = true;
              break;
            }
            int left = m - covered;
            int here = j;
            if (here >= left) {
              string rev = s.substr(here - left, left);
              reverse(rev.begin(), rev.end());
              if (rev == t.substr(covered, left)) {
                found = true;
                break;
              }
            }
          } else
            break;
        }
      }
    }
    if (found)
      cout << "YES\n";
    else
      cout << "NO\n";
  }
}
