#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
int main() {
  int t, a, b, c, m;
  cin >> t;
  while (t--) {
    cin >> a >> b >> c >> m;
    int num[3] = {0}, sum = 0;
    if (a > 0) sum++;
    if (b > 0) sum++;
    if (c > 0) sum++;
    num[0] = max(a, max(b, c)), num[1] = min(a, max(b, c)),
    num[2] = min(a, min(b, c));
    if (m > a + b + c - sum || num[0] - num[1] - num[2] - 1 > m)
      cout << "NO" << endl;
    else
      cout << "YES" << endl;
  }
  return 0;
}
