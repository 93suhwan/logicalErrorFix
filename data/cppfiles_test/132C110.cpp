#include <bits/stdc++.h>
using namespace std;
long long a[9];
void solve() {
  for (int i = 0; i < 7; i++) {
    cin >> a[i];
  }
  int sum = a[0] + a[1];
  if (a[3] == sum) {
    cout << a[0] << ' ' << a[1] << ' ' << a[2] << endl;
  } else {
    cout << a[0] << ' ' << a[1] << ' ' << a[3] << endl;
  }
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int _;
  cin >> _;
  while (_--) {
    solve();
  }
  return 0;
}
