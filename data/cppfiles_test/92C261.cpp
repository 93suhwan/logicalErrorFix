#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    string s;
    cin >> s;
    long long int i, j, c = 0, z = 0, n = s.size();
    for (i = 1; i < n; i++) {
      if (s[i] != s[i - 1]) {
        c++;
      }
      if (s[i] != s[i - 1] && c == 0) {
        z = i - 1;
      }
    }
    if (c % 2) {
      s[z] = 1 - (s[z] - 97) + 97;
    }
    cout << s << "\n";
  }
}
