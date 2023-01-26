#include <bits/stdc++.h>
using namespace std;
const int INF = (int)1E9 + 7;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  long long t, n, c1, c2;
  cin >> t;
  while (t--) {
    cin >> n;
    c1 = n, c2 = 0;
    while (c1 - 2 > 0 && abs(c1 - 3 - c2) > abs(c1 - c2)) {
      c1 -= 2;
      c2++;
    }
    cout << c1 << " " << c2 << endl;
  }
  return 0;
}
