#include <bits/stdc++.h>
using namespace std;
signed main() {
  long long int t;
  cin >> t;
  while (t--) {
    string s;
    cin >> s;
    long long int a = 0, b = 0, c = 0;
    for (long long int i = 0; i < s.length(); i++) {
      if (s[i] == 'A') a++;
      if (s[i] == 'B') b++;
      if (s[i] == 'C') c++;
    }
    if (b == a + c)
      cout << "YES";
    else
      cout << "NO";
    cout << endl;
  }
  return 0;
}
