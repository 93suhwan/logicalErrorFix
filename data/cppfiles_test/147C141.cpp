#include <bits/stdc++.h>
using namespace std;
void solve(void) {
  string str;
  int cnt = 0;
  cin >> str;
  for (int i = 0; i < (int)str.size(); i++) {
    if (str[i] == 'N') cnt++;
  }
  if (cnt == 1) {
    cout << "NO\n";
  } else
    cout << "YES\n";
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int tc = 1;
  cin >> tc;
  while (tc--) {
    solve();
  }
  return 0;
}
