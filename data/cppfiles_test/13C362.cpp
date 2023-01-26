#include <bits/stdc++.h>
using namespace std;
void solve() {
  string s;
  cin >> s;
  long long a[3] = {0};
  for (long long i = 0; i < (long long)((s).size()); i++) {
    if (s[i] == 'A')
      a[0]++;
    else if (s[i] == 'B')
      a[1]++;
    else
      a[2]++;
  }
  if (a[0] + a[2] == a[1]) {
    cout << "YES\n";
  } else {
    cout << "NO\n";
  }
}
signed main() {
  { ios_base::sync_with_stdio(false); }
  { cin.tie(NULL); }
  long long tc = 1;
  cin >> tc;
  while (tc--) {
    solve();
  }
}
