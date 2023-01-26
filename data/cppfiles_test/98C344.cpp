#include <bits/stdc++.h>
using namespace std;
int main() {
  int t, sum, l;
  string s, base;
  cin >> t;
  while (t--) {
    cin >> base >> s;
    sum = 0;
    map<char, int> m;
    for (int i = 0; i < base.length(); i++) m[base[i]] = i + 1;
    l = s.length();
    for (int i = 1; i < l; i++) {
      sum += abs(m[s[i]] - m[s[i - 1]]);
    }
    cout << sum << '\n';
  }
  return 0;
}
