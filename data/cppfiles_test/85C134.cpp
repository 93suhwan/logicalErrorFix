#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int t;
  cin >> t;
  while (t--) {
    string s;
    cin >> s;
    s = s + '1';
    int i;
    int c = 0;
    int n = s.length();
    for (i = 0; i < n; i++) {
      if ((s[i] == '0') && (s[i + 1] != '0')) {
        c++;
      }
    }
    if (c > 2) {
      cout << "2" << endl;
    } else {
      cout << c << endl;
    }
  }
  return 0;
}
