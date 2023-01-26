#include <bits/stdc++.h>
using namespace std;
int main() {
  int t, c = 0, sum = 0;
  cin >> t;
  string s, x;
  while (t--) {
    cin >> s >> x;
    int a[x.length()];
    for (int i = 0; i < x.length(); i++) {
      for (int j = 0; j < s.length(); j++) {
        if (x[i] == s[j]) {
          a[c] = j + 1;
          c++;
          break;
        }
      }
    }
    for (int i = 0; i < x.length() - 1; i++) {
      if (a[i] > a[i + 1])
        sum += (a[i] - a[i + 1]);
      else
        sum += (a[i + 1] - a[i]);
    }
    cout << sum << endl;
    sum = 0;
    c = 0;
  }
  return 0;
}
