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
    c2 = n / 3;
    if (abs(n - 3 * c2) > abs(n - 3 * (c2 + 1))) {
      c2++;
    }
    cout << n - (c2)*2 << " " << c2 << endl;
  }
  return 0;
}
