#include <bits/stdc++.h>
using namespace std;
int solve(int a, int b) {
  if (a == 0 && b == 0) return 0;
  if (a == b) return 1;
  int diff1 = abs(a - b);
  if (diff1 % 2 == 0) return 2;
  return -1;
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int t;
  cin >> t;
  while (t--) {
    int a, b;
    cin >> a >> b;
    cout << solve(a, b) << endl;
  }
  return 0;
}
