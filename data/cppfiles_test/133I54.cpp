#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    char v[n - 2][2];
    for (int i = 0; i < n - 2; i++)
      for (int j = 0; j < 2; j++) {
        cin >> v[i][j];
      }
    char s[n];
    if (n == 3) {
      if (v[0][0] == 'a')
        cout << "b";
      else
        cout << "a";
      cout << v[0][0];
      cout << v[0][1];
      cout << endl;
    } else {
      cout << v[0][0];
      bool x = 0;
      for (int i = 0, j = 0; i < n - 2; i++) {
        if (v[i][1] == v[i + 1][0]) {
          s[j] = v[i][1];
          ++j;
        } else {
          s[j] = v[i][1];
          ++j;
          s[j] = v[i + 1][0];
          ++j;
          x = 1;
          if ((i + 1) == n - 3) x = 2;
        }
      }
      if (x == 1) {
        for (int i = 0; i < n - 2; i++) cout << s[i];
        cout << "a";
      } else {
        if (x == 2) {
          for (int i = 0; i < n - 2; i++) cout << s[i];
          cout << s[n - 3];
        } else {
          for (int i = 0; i < n - 1; i++) cout << s[i];
        }
      }
      cout << endl;
    }
  }
  return 0;
}
