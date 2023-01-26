#include <bits/stdc++.h>
using namespace std;
void solve() {
  long long int n;
  cin >> n;
  long long int a = n % 3;
  if (a == 1) {
    long long int c1 = floor(n / 3) + 1;
    long long int c2 = floor(n / 3);
    cout << c1 << " " << c2 << "\n";
  } else if (a == 2) {
    long long int c1 = floor(n / 3);
    long long int c2 = floor(n / 3) + 1;
    cout << c1 << " " << c2 << "\n";
  } else {
    long long int c1 = floor(n / 3);
    long long int c2 = floor(n / 3);
    cout << c1 << " " << c2 << "\n";
  }
}
int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  long long int t;
  cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}
