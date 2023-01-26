#include <bits/stdc++.h>
using namespace std;
void solve() {
  long long x, y;
  cin >> x >> y;
  long long n;
  if (x <= y) {
    long long t = y / x * x;
    n = (t + y) / 2;
  } else {
    n = x + y;
  }
  cout << n << endl;
  return;
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int t;
  cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}
