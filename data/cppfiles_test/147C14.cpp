#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    string s;
    cin >> s;
    long long int n = s.length(), i, d = 0, e = 0;
    for (i = 0; i < n; i++) {
      if (s[i] == 'E')
        e++;
      else
        d++;
    }
    if (d == 1)
      cout << "NO\n";
    else
      cout << "YES\n";
  }
}
