#include <bits/stdc++.h>
using namespace std;
void solve() {
  long long n;
  cin >> n;
  long long a1 = n / 3;
  long long a2 = n % 3;
  if (a2 == 1)
    cout << (a1 + 1) << " " << a1 << "\n";
  else if (a2 == 2)
    cout << a1 << " " << (a1 + 1) << "\n";
  else
    cout << a1 << " " << a1 << "\n";
}
int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  long long t = 1;
  cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}
