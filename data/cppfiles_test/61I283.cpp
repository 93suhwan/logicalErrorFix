#include <bits/stdc++.h>
using namespace std;
const int MIN = -1e9, MAX = 1e9 + 1, MOD = 1e9 + 7;
int main() {
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    string s;
    cin >> s;
    char last;
    for (int i = 0; i < n; i++) {
      if (s[i] != '?') {
        last = s[i];
        break;
      }
    }
    long long int a[n];
    for (int i = 0; i < n; i++) {
      if (s[i] == '?') {
        if (last == 'B') {
          s[i] = 'R';
          last = 'R';
        } else {
          s[i] = 'B';
          last = 'B';
        }
      } else {
        last = s[i];
      }
    }
    cout << s << endl;
  }
  return 0;
}
