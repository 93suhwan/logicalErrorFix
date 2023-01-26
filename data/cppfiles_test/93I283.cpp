#include <bits/stdc++.h>
using namespace std;
signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  long long testcases = 1;
  cin >> testcases;
  while (testcases--) {
    long long n, k;
    cin >> n >> k;
    if (n == 1)
      cout << 0 << endl;
    else if (k == 1)
      cout << n - 1 << endl;
    else {
      cout << ((k + 1) / 2) + (n - 1) / k << endl;
    }
  }
}
