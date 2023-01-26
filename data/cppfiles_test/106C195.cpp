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
    long long ans = 3;
    while (n) {
      cout << ans << " ";
      ans++;
      n--;
    }
    cout << endl;
  }
  return 0;
}
