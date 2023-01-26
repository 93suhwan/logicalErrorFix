#include <bits/stdc++.h>
using namespace std;
const unsigned int M = 1000000007;
int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  int t = 1;
  cin >> t;
  while (t--) {
    long long n;
    cin >> n;
    long long i, j, z;
    for (i = 2; i * i <= n; ++i) {
    }
    for (j = 2; j * j * j <= n; ++j) {
    }
    for (z = 2; z * z * z * z * z * z <= n; ++z) {
    }
    cout << i + j - z - 1 << endl;
  }
  return 0;
}
