#include <bits/stdc++.h>
using namespace std;
int getFloor(int n, int d) {
  if (n % d == 0)
    return n / d;
  else
    return (n / d) + 1;
}
int solve(int l, int r) {
  int ans = r % l;
  int num1 = r;
  int num2 = getFloor(r, 2) + 1;
  if (num2 < l || num2 > r || num1 < l || num1 > r) return ans;
  ans = max(ans, num1 % num2);
  return ans;
}
int main() {
  int tst;
  cin >> tst;
  while (tst--) {
    int l, r;
    cin >> l >> r;
    cout << solve(l, r) << endl;
  }
}
