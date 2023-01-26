#include <bits/stdc++.h>
using namespace std;
void yo() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.precision(0);
  cout << fixed;
}
void solve() {
  long long int n;
  cin >> n;
  string a, b;
  cin >> a >> b;
  for (long long int i = 0; i < n; i++)
    if (a[i] == '1' && b[i] == '1') {
      cout << "NO\n";
      return;
    }
  cout << "YES"
       << "\n";
}
int main() {
  yo();
  long long int t;
  cin >> t;
  while (t--) solve();
  return 0;
}
