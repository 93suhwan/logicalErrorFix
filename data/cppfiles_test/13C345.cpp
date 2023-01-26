#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  long long t;
  cin >> t;
  while (t--) {
    string s;
    long long a{0}, b{0}, c{0};
    cin >> s;
    for (int i = 0; i < s.size(); i++) {
      if (s[i] == 'A')
        a++;
      else if (s[i] == 'B')
        b++;
      else
        c++;
    }
    if ((a + c) == b)
      cout << "YES"
           << "\n";
    else
      cout << "NO"
           << "\n";
  }
  return 0;
}
