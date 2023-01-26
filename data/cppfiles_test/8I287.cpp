#include <bits/stdc++.h>
using namespace std;
const int INF = (int)1E9 + 7;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  long long t, n, c1, c2;
  cin >> t;
  for (int i = 0; i < int(t); ++i) {
    cin >> n;
    if (n % 2 == 0) {
      c1 = (n / 2) + 2, c2 = ((n / 2) / 2) - 1;
    } else {
      c1 = (n + 1) / 2, c2 = ((n - 1) / 4);
    }
    while (c1 - 2 > 0) {
      if (abs(c1 - c2) < abs((c1 - 2) - (c2 + 1))) {
        break;
      }
      c1 -= 2;
      c2++;
    }
    cout << c1 << " " << c2 << endl;
  }
  return 0;
}
