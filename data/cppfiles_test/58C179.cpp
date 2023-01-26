#include <bits/stdc++.h>
using namespace std;
void solve() {
  int n;
  cin >> n;
  string a, b;
  cin >> a >> b;
  bool possible = true;
  for (int i = 0; i < n; i++)
    if (a[i] == b[i] && a[i] == '1') possible = false;
  if (possible)
    cout << "YES\n";
  else
    cout << "NO\n";
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int t;
  cin >> t;
  while (t--) {
    solve();
  }
}
