#include <bits/stdc++.h>
using namespace std;
int solve() {
  int a, b, c;
  cin >> a >> b >> c;
  int diff = abs(a - b);
  if (diff * 2 < c || max(a, b) > diff * 2) return -1;
  if (c > diff) return (c - diff);
  return (c + diff);
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int t;
  cin >> t;
  while (t--) {
    cout << solve() << endl;
  }
  return 0;
}
