#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    string s = "";
    int cnt = 0;
    for (int i = 0; i < n - 2; i++) {
      string x;
      cin >> x;
      int k = s.length();
      if (cnt < n - 4 && x[0] == x[1]) {
        s += x[0];
        cnt++;
      } else if (cnt < n - 4 && s[k - 1] == x[0]) {
        s += x[1];
        cnt++;
      } else
        s += x;
    }
    if (s.length() == 2)
      cout << "b" << s << endl;
    else
      cout << s << endl;
  }
  return 0;
}
