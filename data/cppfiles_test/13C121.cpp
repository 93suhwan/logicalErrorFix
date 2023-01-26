#include <bits/stdc++.h>
using namespace std;
const int N = 1e6 + 2;
int32_t main() {
  int t;
  cin >> t;
  while (t--) {
    string s;
    cin >> s;
    int ansa = 0, ansb = 0, ansc = 0;
    for (int i = 0; i < s.size(); i++) {
      if (s[i] == 'A') ansa++;
      if (s[i] == 'B') ansb++;
      if (s[i] == 'C') ansc++;
    }
    if (ansb != ansc + ansa)
      cout << "No" << '\n';
    else
      cout << "Yes" << '\n';
  }
}
