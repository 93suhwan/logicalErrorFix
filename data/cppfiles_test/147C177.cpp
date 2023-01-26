#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    string s;
    cin >> s;
    int n = s.length(), c = 0;
    for (int i = 0; i < n; i++) {
      if (s[i] == 'N') c++;
    }
    if (c == 1)
      cout << "NO"
           << "\n";
    else
      cout << "YES"
           << "\n";
  }
  return 0;
}
