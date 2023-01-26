#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int t;
  cin >> t;
  while (t--) {
    string s;
    cin >> s;
    int l = s.length();
    if (l == 1) {
      cout << 0 << endl;
      continue;
    }
    int r = 0;
    int g = 0;
    int k = 0;
    int del = 0;
    for (int i = 0; i < l; i++) {
      if (s[i] == '0') {
        continue;
      }
      for (int j = i + 1; j < l; j++) {
        if (s[i] == s[j]) {
          s[j] = '0';
          k++;
        }
      }
      if (k != 0) {
        r++;
        g++;
        s[i] = '0';
        k = 0;
      } else {
        del++;
      }
    }
    del = del / 2;
    r += del;
    g += del;
    cout << r << endl;
  }
}
