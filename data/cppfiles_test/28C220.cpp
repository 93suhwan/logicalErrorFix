#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  long long t, a, b, c;
  cin >> t;
  while (t--) {
    cin >> a >> b >> c;
    cout << ((a + b * 2 + c * 3) & 1) << '\n';
  }
  return 0;
}
