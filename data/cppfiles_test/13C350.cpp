#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, k, t, a, b, c;
  cin >> n;
  string s;
  for (k = 0; k < n; k++) {
    cin >> s;
    a = b = c = 0;
    for (t = 0; t < s.length(); t++) {
      if (s[t] == 'A') a++;
      if (s[t] == 'B') b++;
      if (s[t] == 'C') c++;
    }
    if (b == a + c)
      cout << "YES" << endl;
    else
      cout << "NO" << endl;
  }
}
