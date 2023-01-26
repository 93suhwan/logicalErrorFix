#include <bits/stdc++.h>
using namespace std;
const int maxn = 5e4 + 5;
const double eps = 1e-8;
void solve() {
  long long a, b, c;
  cin >> a >> b >> c;
  long long bb = b / 2;
  long long m = min(a, c);
  if (bb <= m) {
    b -= bb * 2;
    a -= bb;
    c -= bb;
  } else {
    b -= m * 2;
    a -= m;
    c -= m;
  }
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
