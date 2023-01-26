#include <bits/stdc++.h>
using namespace std;
int solve() {
  int x;
  cin >> x;
  if (x < 9) return 0;
  while (x % 10 != 9) x--;
  return x / 10 + 1;
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int t;
  cin >> t;
  while (t--) cout << solve() << endl;
  return 0;
}
