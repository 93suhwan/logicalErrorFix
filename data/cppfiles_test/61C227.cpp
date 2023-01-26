#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    string s;
    cin >> s;
    int c = 0;
    for (int i = 0; i < n; i++) {
      if (s[i] == '?') c++;
    }
    if (c == n) {
      for (int i = 0; i < n; i++) {
        if (i % 2 == 0) {
          s[i] = 'R';
        } else
          s[i] = 'B';
      }
      cout << s << "\n";
      continue;
    }
    int l = -1;
    for (int i = 0; i < n; i++) {
      if (s[i] == '?') {
        int j = i;
        while (j < n && s[j] == '?') {
          j++;
        }
        if (l != -1) {
          for (int k = l + 1; k < j; k++) {
            if ((k - l) % 2 == 0) {
              s[k] = s[l];
            } else
              s[k] = (s[l] == 'R' ? 'B' : 'R');
          }
        } else {
          for (int k = l + 1; k < j; k++) {
            if ((j - k) % 2 == 0) {
              s[k] = s[j];
            } else
              s[k] = (s[j] == 'R' ? 'B' : 'R');
          }
        }
        i = j - 1;
        l = j - 1;
      } else {
        l++;
      }
    }
    cout << s << "\n";
  }
}
