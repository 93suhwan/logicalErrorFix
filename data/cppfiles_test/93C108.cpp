#include <bits/stdc++.h>
using namespace std;
void solve() {
  int a, b, ans;
  cin >> a >> b;
  int x = (a / 4) * 4;
  int i = x, val = 0;
  while (i < a) {
    val = val ^ i;
    i++;
  }
  if (val == b) {
    ans = a;
  } else if ((val ^ a) == b) {
    ans = a + 2;
  } else {
    ans = a + 1;
  }
  cout << ans << endl;
  return;
}
int main() {
  int t;
  cin >> t;
  while (t > 0) {
    solve();
    t--;
  }
  return 0;
}
