#include <bits/stdc++.h>
using namespace std;
int main() {
  int T;
  cin >> T;
  while (T--) {
    string s;
    cin >> s;
    int n = s.size();
    string a, b;
    for (int i = 0; i < n; ++i) {
      if (i < (n / 2))
        a += s[i];
      else
        b += s[i];
    }
    if (a == b)
      cout << "YES\n";
    else
      cout << "NO\n";
  }
}
