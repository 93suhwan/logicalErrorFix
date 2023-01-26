#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    string s;
    cin >> s;
    int n;
    int b = 0;
    int ac = 0;
    for (int i = 0; i < s.length(); i++) {
      if (s[i] == 'B') {
        b++;
      } else
        ac++;
    }
    if (b == ac) {
      cout << "YES"
           << "\n";
    } else
      cout << "NO"
           << "\n";
  }
  return 0;
}
