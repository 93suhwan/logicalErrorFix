#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    string s, n;
    cin >> s >> n;
    sort(s.begin(), s.end());
    if (n == "abc" && s[0] == 'a')
      sort(lower_bound(s.begin(), s.end(), 'b'),
           upper_bound(s.begin(), s.end(), 'c'), greater<char>());
    cout << s << "\n";
  }
  return 0;
}
