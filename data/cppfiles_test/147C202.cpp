#include <bits/stdc++.h>
using namespace std;
void solve() {
  string s;
  cin >> s;
  int c = 0;
  for (auto x : s) {
    if (x == 'N') c++;
  }
  if (c == 1) {
    cout << "NO"
         << "\n";
    ;
  } else
    cout << "YES"
         << "\n";
  ;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int t;
  cin >> t;
  while (t--) {
    solve();
  }
  cerr << "Time elapsed :" << clock() * 1000.0 / CLOCKS_PER_SEC << " ms"
       << '\n';
  return 0;
}
