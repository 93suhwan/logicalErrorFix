#include <bits/stdc++.h>
using namespace std;
long long power(long long a, long long n) {
  long long ans = 1;
  while (n > 0) {
    ans *= a;
    n--;
  }
  return ans;
}
void solve() {
  long long l1, l2, l3;
  cin >> l1 >> l2 >> l3;
  if (((l1 == l2) && (l3 % 2 == 0)) || ((l1 == l3) && (l2 % 2 == 0)) ||
      ((l3 == l2) && (l1 % 2 == 0))) {
    cout << "YES" << endl;
    return;
  }
  if ((l1 == (l2 + l3)) || (l2 == (l1 + l3)) || (l3 == (l2 + l1))) {
    cout << "YES" << endl;
    return;
  }
  cout << "NO" << endl;
}
int main() {
  int t;
  cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}
