#include <bits/stdc++.h>
using namespace std;
void solve() {
  int n;
  cin >> n;
  string s, s1;
  cin >> s >> s1;
  bool check = false;
  for (int i = 0; i < n; i++) {
    if (((int(s[i]) - 48) & (int(s1[i]) - 48))) {
      check = true;
    }
  }
  if (check) {
    cout << "NO"
         << "\n";
  } else {
    cout << "YES"
         << "\n";
  }
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  long long tc;
  cin >> tc;
  while (tc--) {
    solve();
  }
  return 0;
}
