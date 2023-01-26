#include <bits/stdc++.h>
using namespace std;
void solve() {
  long long x, y;
  scanf("%lld%lld", &x, &y);
  long long n;
  if (x <= y) {
    n = (y - x) / 2 + x;
  } else {
    n = x + y;
  }
  cout << n << endl;
  return;
}
int main() {
  int t;
  cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}
