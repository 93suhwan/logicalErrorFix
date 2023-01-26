#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    int ans = 1;
    for (long long int i = 3; i < 2 * n + 1; ++i) {
      ans = (ans * i) % 1000000007;
    }
    cout << ans << endl;
  }
}
