#include <bits/stdc++.h>
using namespace std;
void solve() {
  string s;
  cin >> s;
  if (s[0] == s[s.length() - 1])
    cout << "YES" << endl;
  else
    cout << "NO" << endl;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  long long test = 1;
  cin >> test;
  while (test--) {
    solve();
  }
  return 0;
}
