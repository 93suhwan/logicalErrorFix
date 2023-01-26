#include <bits/stdc++.h>
using namespace std;
bool compare(pair<long long, long long> a, pair<long long, long long> b) {
  return a.second <= b.second;
}
int main() {
  int t = 1;
  cin >> t;
  while (t--) {
    int n, m, x, y, x1, y1;
    cin >> n >> m >> x >> y >> x1 >> y1;
    if (y <= y1 && x <= x1) {
      cout << min(y1 - y, x1 - x) << endl;
    } else if (y <= y1) {
      cout << y1 - y << endl;
    } else if (x <= x1) {
      cout << x1 - x << endl;
    } else {
      cout << min(n - x + n - x1, m - y + m - y1) << endl;
    }
  }
  return 0;
}
