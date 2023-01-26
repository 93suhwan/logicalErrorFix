#include <bits/stdc++.h>
using namespace std;
int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  long long t;
  cin >> t;
  while (t--) {
    long long n;
    cin >> n;
    long long permute = 1;
    for (long long i = 2 * n; i > 2; i--) {
      permute = (permute * i) % 1000000007;
    }
    cout << permute % 1000000007 << "\n";
  }
  return 0;
}
