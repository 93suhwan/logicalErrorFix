#include <bits/stdc++.h>
using namespace std;
int t;
int main() {
  ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  cin >> t;
  while (t--) {
    string a, s;
    cin >> a >> s;
    string b;
    bool ok = 1;
    int j = s.size() - 1;
    for (int i = a.size() - 1; i >= 0 && j >= 0; i--) {
      if (a[i] == s[j]) {
        b = '0' + b;
        j--;
        continue;
      }
      int A = a[i] - '0';
      int second = s[j] - '0';
      if (A > second) {
        if (j == 0 || s[j - 1] != '1') {
          ok = 0;
          break;
        }
        int x = 10 + second - A;
        b = char(x + '0') + b;
        j -= 2;
      } else {
        int x = second - A;
        b = char(x + '0') + b;
        j--;
      }
    }
    for (int ii = 0; ii < j; ii++) ok &= s[ii] == '0';
    if (!ok)
      cout << -1 << endl;
    else {
      if (b.size() == 1)
        cout << b << endl;
      else {
        int i = 0;
        while (b[i] == '0') i++;
        while (i < b.size()) cout << b[i++];
        cout << endl;
      }
    }
  }
  return 0;
}
