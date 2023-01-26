#include <bits/stdc++.h>
using namespace std;
void solve() {
  long long n;
  cin >> n;
  if (n == 5) {
    cout << 2 << " " << 4 << "\n";
  } else {
    cout << 2 << " " << n / 2 << "\n";
  }
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int t;
  t = 1;
  cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}
