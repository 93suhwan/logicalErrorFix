#include <bits/stdc++.h>
using namespace std;
string change(char x) {
  string s(1, x);
  return s;
}
int main() {
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    string s;
    bool flag = true;
    char big[100][2];
    cin >> big[0][0] >> big[0][1];
    s += change(big[0][0]) + change(big[0][1]);
    for (int i = 1; i < n - 2; i++) {
      cin >> big[i][0] >> big[i][1];
      if (big[i][0] == big[i - 1][1]) {
        s += change(big[i][1]);
      } else {
        flag = false;
        s += change(big[i][0]) + change(big[i][1]);
      }
    }
    if (flag) {
      s += change(s[s.size() - 1]);
    }
    cout << s << endl;
  }
  return 0;
}
