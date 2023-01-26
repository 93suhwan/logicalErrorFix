#include <bits/stdc++.h>
using namespace std;
void run() {
  int n, m, dr, dc, i, j;
  cin >> n >> m >> i >> j >> dr >> dc;
  int r = dr - i < 0 ? i - dr + 2 * (n - i) : dr - i;
  int c = dc - j < 0 ? j - dc + 2 * (m - j) : dc - j;
  cout << min(r, c) << endl;
}
int main() {
  long long int t;
  cin >> t;
  while (t--) {
    run();
  }
  return 0;
}
