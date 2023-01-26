#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  long long t, x, y, z = 1e9;
  cin >> t;
  while (t--) {
    cin >> x >> y;
    cout << z * x + y << "\n";
  }
}
