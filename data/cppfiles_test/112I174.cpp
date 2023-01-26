#include <bits/stdc++.h>
using namespace std;
void solve(int tc = 0) {
  long long int a, b, c, m;
  cin >> a >> b >> c >> m;
  long long int gaps = (a - 1) + (b - 1) + (c - 1);
  if (m >= (gaps - 3) and m <= gaps)
    cout << "YES" << endl;
  else
    cout << "NO" << endl;
}
int main() {
  long long int t;
  cin >> t;
  while (t--) {
    solve(t);
  }
  return 0;
}
