#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int t, n;
  cin >> t;
  while (t--) {
    cin >> n;
    long long ans = 1;
    while (n) {
      ans *= 10;
      ans++;
      cout << ans << " ";
      n--;
    }
    cout << endl;
  }
  return 0;
}
