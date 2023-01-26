#include <bits/stdc++.h>
using namespace std;
int main() {
  long long int t;
  cin >> t;
  while (t--) {
    string s;
    cin >> s;
    map<char, long long int> m;
    long long int i;
    for (i = 0; i < s.size(); i++) {
      m[s[i]]++;
      if (i) {
        if (s[i] == '0' && s[i - 1] == '0') m['0']--;
      }
    }
    long long int ans = m['0'];
    if (m['1'] >= 1) {
      long long int x = 2;
      ans = min(ans, x);
    } else {
      long long int x = 1;
      ans = min(ans, x);
    }
    cout << ans << endl;
  }
}
