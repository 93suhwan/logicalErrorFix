#include <bits/stdc++.h>
using namespace std;
int main() {
  int t, i, j;
  long long n;
  cin >> t;
  while (t--) {
    cin >> n;
    long long ans = (n + 5) / 6 * 15;
    cout << ans << endl;
  }
  return 0;
}
