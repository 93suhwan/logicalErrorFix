#include <bits/stdc++.h>
using namespace std;
int main() {
  int test;
  cin >> test;
  while (test--) {
    int n;
    cin >> n;
    string s;
    cin >> s;
    int i = 0;
    for (i = 0; i < n; i++)
      if (s[i] != '?') break;
    if (i == n) {
      for (int j = 0; j < n; j++)
        if (j % 2 == 0)
          s[j] = 'R';
        else
          s[j] = 'B';
    } else {
      int j = i - 1;
      while (j >= 0) {
        if (s[j] == '?') {
          if (s[j + 1] == 'R')
            s[j] = 'B';
          else
            s[j] = 'R';
        }
        j--;
      }
      j = i + 1;
      while (j < n) {
        if (s[j] == '?') {
          if (s[j - 1] == 'R')
            s[j] = 'B';
          else
            s[j] = 'R';
        }
        j++;
      }
    }
    cout << s << "\n";
  }
  return 0;
}
