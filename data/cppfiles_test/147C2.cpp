#include <bits/stdc++.h>
using namespace std;
void solve() {
  string s;
  cin >> s;
  if (count(s.begin(), s.end(), 'N') == 1) {
    cout << "NO" << endl;
  } else {
    cout << "YES" << endl;
  }
}
int32_t main() {
  ios_base ::sync_with_stdio(false);
  cin.tie(nullptr);
  long long t;
  cin >> t;
  while (t--) {
    solve();
  }
}
