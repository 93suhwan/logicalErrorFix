#include <bits/stdc++.h>
using namespace std;
long long int t, a, b, c, m;
string s;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cin >> t;
  while (t--) {
    cin >> s;
    a = b = c = 0;
    for (long long int i = (0); i <= (s.size() - 1); i++) {
      if (s[i] == 'A') ++a;
      if (s[i] == 'B') ++b;
      if (s[i] == 'C') ++c;
    }
    if (b == a + c)
      cout << "YES"
           << "\n";
    else
      cout << "NO"
           << "\n";
  }
  return 0;
}
