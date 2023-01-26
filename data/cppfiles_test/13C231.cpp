#include <bits/stdc++.h>
using namespace std;
void solve() {
  string s;
  cin >> s;
  int f = 0;
  for (auto i : s)
    if (i == 'B')
      f++;
    else
      f--;
  if (!f)
    cout << "YES\n";
  else
    cout << "NO\n";
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  long long int t = 1;
  cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}
