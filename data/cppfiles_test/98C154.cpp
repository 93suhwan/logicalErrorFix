#include <bits/stdc++.h>
using namespace std;
void solve() {
  map<char, long long> m;
  for (long long i = 0; i < 26; i++) {
    char ch;
    cin >> ch;
    m[ch] = i;
  }
  string str;
  cin >> str;
  long long ans = 0, sum = 0;
  for (long long i = 0; i < str.length() - 1; i++) {
    sum = abs(m[str[i]] - m[str[i + 1]]);
    ans += sum;
  }
  cout << ans << "\n";
  return;
}
signed main() {
  ios_base::sync_with_stdio(false), cin.tie(NULL);
  long long t = 1;
  cin >> t;
  for (long long i = 0; i < t; i++) {
    solve();
  }
}
