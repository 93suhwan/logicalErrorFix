#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int cases;
  cin >> cases;
  for (int c = 0; c < cases; c++) {
    int len;
    cin >> len;
    string str;
    cin >> str;
    for (int i = 0; i < len; i++)
      if (str[i] == '?')
        if (!(i == 0 || str[i - 1] == '?')) {
          if (str[i - 1] == 'R')
            str[i] = 'B';
          else
            str[i] = 'R';
        }
    for (int i = len - 1; i >= 0; i--)
      if (str[i] == '?')
        if (!(i == len - 1 || str[i + 1] == '?')) {
          if (str[i + 1] == 'R')
            str[i] = 'B';
          else
            str[i] = 'R';
        }
    if (str[0] == '?')
      for (int i = 0; i < len; i++) str[i] = (i & 1) ? 'B' : 'R';
    cout << str << '\n';
  }
  return 0;
}
