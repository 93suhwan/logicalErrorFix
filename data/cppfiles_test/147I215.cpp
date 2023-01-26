#include <bits/stdc++.h>
using namespace std;
void Solve() {
  string s;
  cin >> s;
  if (s == "NE" || s == "EN") {
    cout << "NO\n";
  } else {
    cout << "YES\n";
  }
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int t = 1;
  cin >> t;
  while (t--) Solve();
}
