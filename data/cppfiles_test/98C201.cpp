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
    int a = 0, b = 0;
    for (int i = 0; i < n; i++) {
      if (s[i] == 'a')
        a++;
      else
        b++;
    }
    if (a == 0 || b == 0)
      cout << "-1"
           << " "
           << "-1" << endl;
    else {
      for (int i = 0; i < n - 1; i++) {
        if (s[i] == 'a' && s[i + 1] == 'b') {
          cout << i + 1 << " " << i + 2 << endl;
          break;
        } else if (s[i] == 'b' && s[i + 1] == 'a') {
          cout << i + 1 << " " << i + 2 << endl;
          break;
        }
      }
    }
  }
  return 0;
}
