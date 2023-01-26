#include <bits/stdc++.h>
using namespace std;
void solve() {
  long long n;
  cin >> n;
  if (n % 2 == 0)
    cout << n / 2 - 1 << " " << n / 2 << " " << 1 << endl;
  else {
    long long half = (n - 1) / 2;
    if (half % 2 == 0)
      cout << half - 1 << " " << half + 1 << " " << 1 << endl;
    else
      cout << half - 2 << " " << half + 2 << " " << 1 << endl;
  }
}
int main() {
  int t;
  cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}
