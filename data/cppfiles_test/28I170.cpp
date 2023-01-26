#include <bits/stdc++.h>
using namespace std;
const int maxn = 5e4 + 5;
const double eps = 1e-8;
void solve() {
  long long a, b, c;
  cin >> a >> b >> c;
  a %= 2;
  b %= 2;
  c %= 2;
  if (a == b && a == c)
    cout << 0 << endl;
  else
    cout << 1 << endl;
}
int main() {
  int T = 1;
  scanf("%d", &T);
  while (T--) {
    solve();
  }
  return 0;
}
