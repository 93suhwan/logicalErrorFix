#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  string s, tt;
  int a, b, c, k;
  string result;
  while (t--) {
    cin >> s >> tt;
    sort(s.begin(), s.end());
    if (tt == "abc") {
      for (int i = 0; i < s.length(); i++) {
        if (s[i] == 'a') continue;
        if (i == 0) break;
        if (s[i] == 'b') {
          k = i;
          for (int j = i + 1; j < s.length(); j++)
            if (s[j] == 'c') {
              swap(s[k], s[j]);
              k++;
            }
          break;
        }
      }
    }
    cout << s << endl;
  }
  return 0;
}
