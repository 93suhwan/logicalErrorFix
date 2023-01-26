#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int test;
  cin >> test;
  while (test--) {
    int n;
    cin >> n;
    string s;
    cin >> s;
    for (int i = 0; i < n; i++) {
      if (s[i] != '?') {
        int j = i - 1;
        while (j >= 0 && s[j] == '?') {
          if (s[j + 1] == 'R') {
            s[j] = 'B';
          } else {
            s[j] = 'R';
          }
          j--;
        }
      }
    }
    reverse((s).begin(), (s).end());
    for (int i = 0; i < n; i++) {
      if (s[i] != '?') {
        int j = i - 1;
        while (j >= 0 && s[j] == '?') {
          if (s[j + 1] == 'R') {
            s[j] = 'B';
          } else {
            s[j] = 'R';
          }
          j--;
        }
      }
    }
    if (s[0] == '?') {
      for (int i = 0; i < n; i++) {
        if (i % 2) {
          s[i] = 'R';
        } else {
          s[i] = 'B';
        }
      }
    }
    cout << s << '\n';
  }
}
