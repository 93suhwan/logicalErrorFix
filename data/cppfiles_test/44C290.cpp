#include <bits/stdc++.h>
using namespace std;
void solve() {
  long long c, d;
  cin >> c >> d;
  long long dif = abs(c - d);
  if (c == 0 && d == 0)
    cout << "0"
         << "\n";
  else if (c == d && c != 0)
    cout << "1"
         << "\n";
  else if (dif % 2 == 0)
    cout << "2"
         << "\n";
  else
    cout << "-1"
         << "\n";
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cin.tie(NULL);
  long long t;
  cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}
