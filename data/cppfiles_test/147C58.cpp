#include <bits/stdc++.h>
using namespace std;
void solve() {
  string s;
  cin >> s;
  int numN = 0;
  for (int i = 0; i < s.length(); ++i) {
    if (s[i] == 'N') {
      numN++;
    }
  }
  if (numN == 1) {
    cout << "NO\n";
  } else {
    cout << "YES\n";
  }
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int t;
  cin >> t;
  while (t--) solve();
  return 0;
}
