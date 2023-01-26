#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    string s;
    cin >> s;
    int cn1 = 0, cn2 = 0;
    for (int i = 0; i < s.length(); i++) {
      if (s[i] == 'A' || s[i] == 'C')
        cn1++;
      else
        cn2++;
    }
    if (cn1 == 1 || cn2 == 1 || cn1 == 0 || cn2 == 0) {
      cout << "NO" << endl;
    } else if (cn1 == cn2) {
      cout << "YES\n";
    } else {
      cout << "NO\n";
    }
  }
}
