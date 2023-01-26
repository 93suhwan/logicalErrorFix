#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    string s;
    cin >> s;
    int first = -1;
    for (int i = 0; i < n; i++)
      if (s[i] != '?') {
        first = i;
        break;
      }
    if (first != -1) {
      char filler;
      for (int i = first; i >= 0; i--) {
        if (s[i] != '?')
          filler = s[i] == 'R' ? 'B' : 'R';
        else {
          s[i] = filler;
          filler = filler == 'R' ? 'B' : 'R';
        }
      }
      for (int i = first; i < n; i++) {
        if (s[i] != '?')
          filler = s[i] == 'R' ? 'B' : 'R';
        else {
          s[i] = filler;
          filler = filler == 'R' ? 'B' : 'R';
        }
      }
    } else {
      char filler = 'R';
      for (int i = 0; i < n; i++) {
        s[i] = filler;
        filler = filler == 'R' ? 'B' : 'R';
      }
    }
    cout << s << endl;
  }
  return 0;
}
