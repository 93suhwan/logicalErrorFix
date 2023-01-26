#include <bits/stdc++.h>
using namespace std;
void solve() {
  string s;
  cin >> s;
  long long ab = 0, ba = 0, n = s.length();
  for (long long i = 0; i < n - 1; i++) {
    if (s[i] == 'a' && s[i + 1] == 'b') ab++;
    if (s[i] == 'b' && s[i + 1] == 'a') ba++;
  }
  if (ab > ba)
    s[n - 1] = 'a';
  else if (ba > ab)
    s[n - 1] = 'b';
  cout << s;
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  long long t;
  cin >> t;
  while (t--) {
    solve();
    cout << "\n";
  }
  return 0;
}
