#include <bits/stdc++.h>
using namespace std;
void solve() {
  int n;
  cin >> n;
  int a = n / 10;
  int b = n % 10;
  if (b == 9)
    cout << a + 1 << endl;
  else
    cout << a << endl;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  ;
  int t;
  cin >> t;
  while (t--) solve();
  return 0;
}
