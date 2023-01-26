#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  ;
  long long int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    string s;
    cin >> s;
    for (int i = 0; i < n; i++) {
      if (i == 0 && s[i] == '?') {
        if (n == 1) {
          s[i] = 'B';
        } else {
          if (s[i + 1] == 'B') {
            s[i] = 'R';
          } else {
            s[i] = 'B';
          }
        }
      } else if (s[i] == '?') {
        if (s[i - 1] == 'B') {
          s[i] = 'R';
        }
        if (s[i - 1] == 'R') {
          s[i] = 'B';
        }
      }
    }
    cout << s << endl;
  }
  return 0;
}
