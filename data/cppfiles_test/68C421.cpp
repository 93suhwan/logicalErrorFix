#include <bits/stdc++.h>
using namespace std;
void solve() {
  long long k;
  cin >> k;
  long long sqrtl = sqrt(k);
  long long sqrtr = sqrtl + 1;
  long long l = sqrtl * sqrtl;
  long long r = sqrtr * sqrtr;
  if (l == k) {
    cout << sqrtl << " " << 1 << endl;
    return;
  }
  if (l + 1 == k) {
    cout << 1 << " " << sqrtr << endl;
    return;
  }
  long long mid = (l + 1 + r) / 2;
  if (mid < k) {
    cout << sqrtr << " " << sqrtr - (k - mid) << endl;
  } else {
    cout << sqrtr - (mid - k) << " " << sqrtr << endl;
  }
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int t = 1;
  cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}
