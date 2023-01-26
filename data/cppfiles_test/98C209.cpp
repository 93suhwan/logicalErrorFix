#include <bits/stdc++.h>
using namespace std;
int main() {
  long long int t;
  cin >> t;
  while (t--) {
    string s, s1;
    cin >> s;
    map<char, int> m;
    for (long long int i = 1; i < 26; i++) {
      m[s[i]] = i;
    }
    cin >> s1;
    long long int ans = 0;
    for (long long int i = 0; i < s1.length() - 1; i++) {
      ans = ans + abs(m[s1[i + 1]] - m[s1[i]]);
    }
    cout << ans << endl;
  }
  return 0;
}
