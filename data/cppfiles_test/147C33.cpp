#include <bits/stdc++.h>
using namespace std;
int main() {
  long long int i, i1, j, k, n, t, sum, c, c1, c2, b, a;
  cin >> t;
  while (t--) {
    string s;
    cin >> s;
    c = 0;
    for (i = 0; i < s.length(); i++) {
      if (s[i] == 'N') c++;
    }
    if (c == 1)
      cout << "NO" << endl;
    else
      cout << "YES" << endl;
  }
  return 0;
}
