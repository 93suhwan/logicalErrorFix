#include <bits/stdc++.h>
using namespace std;
long long int mod = 1000000007;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int cases;
  cin >> cases;
  while (cases--) {
    long long int n;
    cin >> n;
    n = 2 * n;
    long long ans = 1;
    while (n > 2) {
      ans = (ans * n) % mod;
      n--;
    }
    cout << ans << endl;
  }
  return 0;
}
