#include <bits/stdc++.h>
using namespace std;
int mod = 1e9 + 7;
int main() {
  int t;
  cin >> t;
  while (t--) {
    long long int n;
    cin >> n;
    long long int ans = 1;
    for (long long int i = 3; i <= 2 * n; i++) ans = (ans * i) % mod;
    cout << ans << endl;
  }
}
