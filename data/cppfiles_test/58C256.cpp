#include <bits/stdc++.h>
using namespace std;
void solve();
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int t;
  cin >> t;
  for (int t_ = 0; t_ < t; t_++) {
    solve();
  }
  return 0;
}
void solve() {
  int n;
  cin >> n;
  string s1, s2;
  cin >> s1 >> s2;
  bool b = true;
  for (int i = 1; i < n - 1; i++) {
    if (s1[i] == '1' && s2[i] == '1') {
      b = false;
      break;
    }
  }
  if (b)
    cout << "YES" << endl;
  else
    cout << "NO" << endl;
}
