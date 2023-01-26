#include <bits/stdc++.h>
using ll = long long;
using namespace std;
int f(string s, string t) {
  int j = 0;
  for (int i = 0; i < s.size() && j < t.size(); i++) {
    if (s[i] == t[j]) j++;
  }
  return (s.size() - j) + (t.size() - j);
}
int main() {
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    string s = to_string(n);
    int ans = 2e9;
    for (int i = 0; i < 60; i++) {
      ans = min(ans, f(s, to_string((ll)1 << i)));
    }
    cout << ans << endl;
  }
  return 0;
}
