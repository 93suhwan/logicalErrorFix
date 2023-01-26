#include <bits/stdc++.h>
using namespace std;
const long long int mod = 1000000007;
bool check(unsigned long long int l, unsigned long long int a,
           unsigned long long int b) {
  if (a == b) {
    if (l % 2 == 0) return true;
    return false;
  }
  if (l == a + b) return true;
  return false;
}
void solve() {
  unsigned long long int l1, l2, l3;
  cin >> l1 >> l2 >> l3;
  if (check(l1, l2, l3)) {
    cout << "YES" << endl;
    return;
  } else if (check(l2, l1, l3)) {
    cout << "YES" << endl;
    return;
  } else if (check(l3, l1, l2)) {
    cout << "YES" << endl;
    return;
  }
  cout << "NO" << endl;
  return;
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int tc = 1;
  cin >> tc;
  for (int t = 1; t <= tc; t++) {
    solve();
  }
}
