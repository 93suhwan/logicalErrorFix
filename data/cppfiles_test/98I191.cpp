#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    string s;
    cin >> s;
    int a = 0, b = 0;
    for (int i = 0; i < n; i++) {
      if (s[i] == 'a')
        a++;
      else
        b++;
    }
    if (a == b) {
      cout << 1 << " " << n << "\n";
    } else {
      size_t found = s.find("ab");
      if (found != string::npos)
        cout << found << " " << found + 1 << "\n";
      else
        cout << -1 << " " << -1 << "\n";
    }
  }
  return 0;
}
