#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    string s, res = "";
    cin >> res;
    for (int i = 1; i < n - 2; i++) {
      cin >> s;
      if (res[res.length() - 1] == s[0])
        res = res + s[1];
      else
        res = res + s[0] + s[1];
    }
    if (n == 3)
      cout << res + "b" << endl;
    else if (n > res.length())
      cout << res + "a" << endl;
    else
      cout << res << endl;
  }
}
