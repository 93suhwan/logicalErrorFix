#include <bits/stdc++.h>
using namespace std;
long long freq_str(string s, char c) {
  long long cunt = 0;
  for (int i = 0; i < s.length(); i++) {
    if (s[i] == c) cunt++;
  }
  return (cunt - (s.length() - cunt));
}
void solve() {
  long long n, longest_string, cunt, ans = 0;
  cin >> n;
  vector<string> v(n);
  for (int i = 0; i < n; i++) {
    cin >> v[i];
  }
  for (char c = 'a'; c <= 'e'; c++) {
    vector<long long> fs(n);
    for (int i = 0; i < n; i++) {
      fs[i] = freq_str(v[i], c);
    }
    sort(fs.begin(), fs.end(), greater<int>());
    cunt = 0;
    longest_string = 0;
    for (int j = 0; j < n; j++) {
      longest_string += fs[j];
      if (longest_string > 0) {
        cunt++;
      } else
        break;
    }
    ans = max(ans, cunt);
  }
  cout << ans << endl;
}
int main() {
  int t;
  cin >> t;
  while (t--) {
    solve();
  }
}
