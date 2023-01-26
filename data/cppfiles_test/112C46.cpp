#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(NULL);
  cin.tie(0);
  cout.tie(0);
  int t;
  cin >> t;
  while (t--) {
    int a, b, c, m;
    cin >> a >> b >> c >> m;
    int len = a + b + c;
    int maxi = len - 3;
    int valMax = max(a, max(b, c));
    int mini = max(0, ((2 * valMax) - len - 1));
    if (m < mini || m > maxi)
      cout << "NO\n";
    else
      cout << "YES\n";
  }
  return 0;
}
