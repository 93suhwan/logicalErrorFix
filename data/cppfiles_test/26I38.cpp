#include <bits/stdc++.h>
using namespace std;
int t;
long long n;
long long res[100002];
int main() {
  cin >> t;
  res[1] = 1;
  for (long long i = 2; i <= 10000; i++) {
    res[i] = ((i << 1) - 1ll) * res[i - 1] % 1000000007 * (i << 1) % 1000000007;
  }
  while (t--) {
    cin >> n;
    cout << res[n] << endl;
  }
}
