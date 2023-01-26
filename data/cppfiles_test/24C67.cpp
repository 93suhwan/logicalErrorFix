#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int t;
  cin >> t;
  while (t--) {
    long long n;
    cin >> n;
    long long ans = n / 10;
    ans += (n % 10 + 1) / 10;
    cout << ans << endl;
  }
  return 0;
}
