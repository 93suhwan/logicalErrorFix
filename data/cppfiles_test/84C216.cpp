#include <bits/stdc++.h>
using namespace std;
const int MOD = 1e9 + 7;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int test;
  cin >> test;
  while (test--) {
    long long int n, s;
    cin >> n >> s;
    long long int z = n / 2;
    if (n % 2 == 0) z--;
    long long int o = n - z;
    long long int ans = (s) / o;
    cout << ans << endl;
  }
  return 0;
}
