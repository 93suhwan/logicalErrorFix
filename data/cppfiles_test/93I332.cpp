#include <bits/stdc++.h>
const int N = 1000001;
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  long long int t;
  cin >> t;
  while (t--) {
    long long int n, k;
    cin >> n >> k;
    if (n == 1) {
      cout << "0\n";
      continue;
    }
    long long int r = log2(n);
    long long int x = log2(2 * k);
    long long int ans = x;
    long long int y = pow(2, x);
    long long int z = n - y;
    if (z > 0) {
      ans += (z / k);
      if (z % k != 0) ans++;
    }
    cout << min(r, ans) << "\n";
  }
  return 0;
}
