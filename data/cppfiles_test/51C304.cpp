#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(NULL);
  cout.tie(NULL);
  long long int t;
  cin >> t;
  while (t--) {
    long long int n, l, r;
    cin >> n;
    if (n == 1) {
      cout << 0 << " " << 1 << endl;
    } else if (n == 2) {
      cout << -1 << " " << 2 << endl;
    } else {
      cout << (-1) * (n - 1) << " " << n << endl;
    }
  }
  return 0;
}
