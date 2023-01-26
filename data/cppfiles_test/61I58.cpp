#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
const int MAX = 1000;
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
    int start = 0;
    for (int i = 0; i < n; i++) {
      if (s[i] != '?') {
        start = i;
        break;
      }
    }
    cout << start << endl;
    for (int i = start + 1; i < n; i++) {
      if (s[i] == '?') {
        if (s[i - 1] == 'R')
          s[i] = 'B';
        else
          s[i] = 'R';
      }
      if (s[i] != '?') continue;
    }
    for (int i = start; i >= 0; i--) {
      if (s[i] == '?') {
        if (s[i + 1] == 'R')
          s[i] = 'B';
        else
          s[i] = 'R';
      }
      if (s[i] != '?') continue;
    }
    cout << s << endl;
  }
}
