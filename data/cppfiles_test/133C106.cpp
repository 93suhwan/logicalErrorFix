#include <bits/stdc++.h>
using namespace std;
string w[100];
void solve() {
  int n;
  cin >> n;
  for (int i = 2; i < n; i++) cin >> w[i - 2];
  string s = w[0];
  for (int i = 1; i < n - 2; i++) {
    if (w[i][0] != w[i - 1][1]) s += w[i][0];
    s += w[i][1];
  }
  if (s.size() == n - 1) s += 'a';
  cout << s;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int t = 1;
  cin >> t;
  while (t--) {
    solve();
    cout << "\n";
  }
  return 0;
}
