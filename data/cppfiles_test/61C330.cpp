#include <bits/stdc++.h>
using namespace std;
long long int mod = 1e9 + 7;
void solve() {
  long long int n;
  cin >> n;
  string a;
  cin >> a;
  string x = a, y = a;
  if (a[0] == '?') x[0] = 'B', y[0] = 'R';
  for (long long int i = 1; i < n; i++) {
    if (x[i] == '?') {
      x[i] = (x[i - 1] == 'R') ? 'B' : 'R';
      y[i] = (y[i - 1] == 'R') ? 'B' : 'R';
    }
  }
  long long int xc = 0, yc = 0;
  for (long long int i = 1; i < n; i++) {
    if (x[i] == x[i - 1]) xc++;
    if (y[i] == y[i - 1]) yc++;
  }
  if (xc < yc)
    cout << x << endl;
  else
    cout << y << endl;
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int T = 1;
  cin >> T;
  while (T--) solve();
  return 0;
}
