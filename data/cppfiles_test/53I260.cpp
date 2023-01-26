#include <bits/stdc++.h>
using namespace std;
void solve() {
  long long int n;
  char c;
  cin >> n >> c;
  string s;
  cin >> s;
  long long int o = 0, e = 0;
  for (long long int i = 1; i <= n; i++) {
    if (s[i - 1] != c) {
      if (i % 2)
        o++;
      else
        e++;
    }
  }
  if (o == 0 and e == 0) {
    cout << 0 << endl;
  } else if (o == 0) {
    cout << 1 << endl << 3 << endl;
  } else if (e == 0) {
    cout << 1 << endl << 2 << endl;
  } else {
    cout << 2 << endl;
    cout << "2 3\n";
  }
}
int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  long long int t;
  cin >> t;
  while (t--) solve();
  return 0;
}
