#include <bits/stdc++.h>
using namespace std;
void solve() {
  string s;
  cin >> s;
  if (s[0] == 'E' && s[1] == 'N' && s.length() == 2)
    cout << "NO" << endl;
  else
    cout << "YES" << endl;
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
