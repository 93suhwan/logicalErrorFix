#include <bits/stdc++.h>
using namespace std;
void solve() {
  string s;
  cin >> s;
  string t;
  for (int i = 0; i < (int((s).size())); i++) {
    if (count((t).begin(), (t).end(), s[i]) < 2) {
      t += s[i];
    }
  }
  if ((int((t).size())) % 2 == 1)
    cout << ((int((t).size())) - 1) / 2;
  else
    cout << (int((t).size())) / 2;
  cout << '\n';
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int t;
  cin >> t;
  while (t--) solve();
  return 0;
}
